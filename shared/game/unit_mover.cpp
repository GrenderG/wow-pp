//
// This file is part of the WoW++ project.
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software 
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// World of Warcraft, and all World of Warcraft or Warcraft art, images,
// and lore are copyrighted by Blizzard Entertainment, Inc.
// 

#include "unit_mover.h"
#include "game_unit.h"
#include "world_instance.h"
#include "universe.h"
#include "binary_io/vector_sink.h"
#include "game_protocol/game_protocol.h"
#include "each_tile_in_sight.h"
#include "common/constants.h"
#include <memory>

namespace wowpp
{
	const GameTime UnitMover::UpdateFrequency = constants::OneSecond / 4;

	UnitMover::UnitMover(GameUnit &unit)
		: m_unit(unit)
		, m_moveReached(unit.getTimers())
		, m_moveUpdated(unit.getTimers())
		, m_moveStart(0)
		, m_moveEnd(0)
	{
		m_moveUpdated.ended.connect([this]()
		{
			GameTime time = getCurrentTime();
			if (time >= m_moveEnd)
				return;

			// Calculate new position
			float o = getMoved().getOrientation();
			o = getMoved().getAngle(m_target.x, m_target.y);

			math::Vector3 oldPosition = getCurrentLocation();

			// Trigger next update if needed
			if (time < m_moveEnd - UnitMover::UpdateFrequency)
			{
				m_moveUpdated.setEnd(time + UnitMover::UpdateFrequency);
			}

			// Update creatures position in the next update frame
			auto strongUnit = getMoved().shared_from_this();
			std::weak_ptr<GameObject> weakUnit(strongUnit);
			getMoved().getWorldInstance()->getUniverse().post([weakUnit, oldPosition, o]()
			{
				auto strongUnit = weakUnit.lock();
				if (strongUnit)
				{
					strongUnit->relocate(oldPosition, o);
				}
			});
		});

		m_moveReached.ended.connect([this]()
		{
			// Cancel update timer
			m_moveUpdated.cancel();

			// Fire signal since we reached our target
			targetReached();

			float angle = getMoved().getOrientation();
			auto &target = m_target;

			// Update creatures position
			auto strongUnit = getMoved().shared_from_this();
			std::weak_ptr<GameObject> weakUnit(strongUnit);
			getMoved().getWorldInstance()->getUniverse().post([weakUnit, target, angle]()
			{
				auto strongUnit = weakUnit.lock();
				if (strongUnit)
				{
					strongUnit->relocate(target, angle);
				}
			});
		});
	}

	UnitMover::~UnitMover()
	{
	}

	bool UnitMover::moveTo(const math::Vector3 & target)
	{
		// Same target!
		if (m_target == target)
			return true;

		// Dead units can't move
		if (!getMoved().isAlive())
			return false;

		// Stunned / Rooted units can't move either
		// TODO

		// Get current location
		auto currentLoc = getCurrentLocation();

		// Do we really need to move?
		if (target == currentLoc)
		{
			stopMovement();
			return true;
		}

		// Now we need to stop the current movement
		if (m_moveReached.running)
		{
			// Cancel movement timers
			m_moveReached.cancel();
			m_moveUpdated.cancel();

			// Calculate our orientation
			const float dx = target.x - currentLoc.x;
			const float dy = target.y - currentLoc.y;
			float o = ::atan2(dy, dx);
			o = (o >= 0) ? o : 2 * 3.1415927f + o;

			// Stop, here, but since we are moving to the next point immediatly after this,
			// we won't notify the grid about this for performance reasons (since the next
			// movement update tick will do this for us automatically).
			getMoved().relocate(currentLoc, o, false);
		}

		// Use new values
		m_start = currentLoc;
		m_target = target;
		float distance = (m_target - m_start).length();

		// Update timing
		m_moveStart = getCurrentTime();

		// Calculate time of arrival
		// TODO: take movement speed into account
		GameTime moveTime = (distance / 7.5f) * constants::OneSecond;
		m_moveEnd = m_moveStart + moveTime;

		// Send movement packet
		TileIndex2D tile;
		if (getMoved().getTileIndex(tile))
		{
			// TODO: Maybe, player characters need another movement packet for this...
			std::vector<char> buffer;
			io::VectorSink sink(buffer);
			game::Protocol::OutgoingPacket packet(sink);
			game::server_write::monsterMove(packet, getMoved().getGuid(), currentLoc, target, moveTime);

			forEachSubscriberInSight(
				getMoved().getWorldInstance()->getGrid(),
				tile,
				[&packet, &buffer](ITileSubscriber &subscriber)
			{
				subscriber.sendPacket(packet, buffer);
			});
		}

		// Setup update timer if needed
		GameTime nextUpdate = m_moveStart + UnitMover::UpdateFrequency;
		if (nextUpdate < m_moveEnd)
		{
			m_moveUpdated.setEnd(nextUpdate);
		}

		// Setup end timer
		m_moveReached.setEnd(m_moveEnd);

		// Raise signal
		targetChanged();

		return true;
	}

	void UnitMover::stopMovement()
	{
		if (isMoving())
		{
			// Cancel timers
			m_moveReached.cancel();
			m_moveUpdated.cancel();

			// Update current location
			auto currentLoc = getCurrentLocation();
			const float dx = m_target.x - currentLoc.x;
			const float dy = m_target.y - currentLoc.y;
			float o = ::atan2(dy, dx);
			o = (o >= 0) ? o : 2 * 3.1415927f + o;

			// Update with grid notification
			getMoved().relocate(currentLoc, o);

			// Fire this trigger only here, not when movement was updated,
			// since only then we are really stopping
			movementStopped();
		}
	}

	math::Vector3 UnitMover::getCurrentLocation() const
	{
		// Unit didn't move yet or isn't moving at all
		if (m_moveStart == 0 || !isMoving())
			return getMoved().getLocation();

		// Linear interpolation
		const float t = static_cast<float>(static_cast<double>(getCurrentTime() - m_moveStart) / static_cast<double>(m_moveEnd - m_moveStart));
		return m_start.lerp(m_target, t);
	}
}
