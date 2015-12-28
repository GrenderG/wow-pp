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

#include "creature_ai_idle_state.h"
#include "creature_ai.h"
#include "game_creature.h"
#include "world_instance.h"
#include "tiled_unit_watcher.h"
#include "unit_finder.h"
#include "universe.h"
#include "proto_data/faction_helper.h"
#include "log/default_log_levels.h"

namespace wowpp
{
	CreatureAIIdleState::CreatureAIIdleState(CreatureAI &ai)
		: CreatureAIState(ai)
	{
	}

	CreatureAIIdleState::~CreatureAIIdleState()
	{
	}

	void CreatureAIIdleState::onEnter()
	{
		auto &controlled = getControlled();

		// Handle incoming threat
		auto &ai = getAI();
		m_onThreatened = controlled.threatened.connect(std::bind(&CreatureAI::onThreatened, &ai, std::placeholders::_1, std::placeholders::_2));

		auto *worldInstance = controlled.getWorldInstance();
		assert(worldInstance);

		float x, y, z, o;
		controlled.getLocation(x, y, z, o);

		Circle circle(x, y, 40.0f);
		m_aggroWatcher = worldInstance->getUnitFinder().watchUnits(circle);
		m_aggroWatcher->visibilityChanged.connect([this](GameUnit& unit, bool isVisible) -> bool
		{
			auto &controlled = getControlled();
			if (unit.getGuid() == controlled.getGuid())
			{
				return false;
			}

			if (!controlled.isAlive())
			{
				return false;
			}

			if (!unit.isAlive())
			{
				return false;
			}

			// Check if we are hostile against this unit
			const auto &ourFaction = controlled.getFactionTemplate();
			const auto &unitFaction = unit.getFactionTemplate();
			if (isNeutralToAll(ourFaction))
			{
				return false;
			}

			const float dist = controlled.getDistanceTo(unit, false);

			const bool isHostile = isHostileTo(ourFaction, unitFaction);
			const bool isFriendly = isFriendlyTo(ourFaction, unitFaction);
			if (isHostile && !isFriendly)
			{
				if (isVisible)
				{
					const Int32 ourLevel = static_cast<Int32>(controlled.getLevel());
					const Int32 otherLevel = static_cast<Int32>(unit.getLevel());
					const Int32 diff = ::abs(ourLevel - otherLevel);

					// Check distance
					float reqDist = 20.0f;
					if (ourLevel < otherLevel)
					{
						reqDist = limit<float>(reqDist - diff, 5.0f, 40.0f);
					}
					else if (otherLevel < ourLevel)
					{
						reqDist = limit<float>(reqDist + diff, 5.0f, 40.0f);
					}

					if (dist > reqDist)
					{
						return false;
					}

					// Little hack since LoS is not working
					float tmp = 0.0f, z2 = 0.0f, z = 0.0f;
					controlled.getLocation(tmp, tmp, z, tmp);
					unit.getLocation(tmp, tmp, z2, tmp);
					if (::abs(z - z2) > 3.0f)
					{
						return false;
					}

					getAI().enterCombat(unit);
					return true;
				}

				// We don't care
				return false;
			}
			else if (isFriendly)
			{
				if (isVisible)
				{
					if (dist < 8.0f)
					{
						auto *victim = unit.getVictim();
						if (unit.isInCombat() && victim != nullptr)
						{
							if (!isHostileTo(unitFaction, victim->getFactionTemplate()))
								return false;

							getAI().enterCombat(*victim);
							return true;
						}
					}
				}
			}

			return false;
		});

		m_aggroWatcher->start();
	}

	void CreatureAIIdleState::onLeave()
	{

	}

}
