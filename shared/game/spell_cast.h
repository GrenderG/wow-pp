//
// This file is part of the WoW++ project.
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU Genral Public License as published by
// the Free Software Foudnation; either version 2 of the Licanse, or
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

#pragma once

#include "game/defines.h"
#include "data/spell_entry.h"
#include "spell_target_map.h"
#include "common/timer_queue.h"
#include <boost/signals2.hpp>

namespace wowpp
{
	class GameUnit;

	/// 
	class SpellCasting final
	{
	public:

		typedef boost::signals2::signal<void(bool)> EndSignal;

	public:

		EndSignal ended;
	};

	/// This class handles spell casting logic for an executing unit object.
	class SpellCast final
	{
	public:

		class CastState;

	public:

		explicit SpellCast(TimerQueue &timer, GameUnit &executer);

		GameUnit &getExecuter() const { return m_executer; }
		TimerQueue &getTimers() const { return m_timers; }

		std::pair<game::SpellCastResult, SpellCasting*> startCast(
			const SpellEntry &spell,
			SpellTargetMap target,
			GameTime castTime,
			bool doReplacePreviousCast);
		void stopCast();
		void onUserStartsMoving();
		void setState(std::unique_ptr<CastState> castState);

	private:

		TimerQueue &m_timers;
		GameUnit &m_executer;
		std::unique_ptr<CastState> m_castState;
	};

	/// 
	class SpellCast::CastState
	{
	public:

		virtual ~CastState() { }

		virtual std::pair<game::SpellCastResult, SpellCasting*> startCast(
			SpellCast &cast,
			const SpellEntry &spell,
			SpellTargetMap target,
			GameTime castTime,
			bool doReplacePreviousCast
			) = 0;
		virtual void stopCast() = 0;
		virtual void onUserStartsMoving() = 0;
	};

	SpellCasting &castSpell(
		SpellCast &cast,
		const SpellEntry &spell,
		SpellTargetMap target,
		GameTime castTime
		);

	bool isInSkillRange(
		const SpellEntry &spell,
		GameUnit &user,
		SpellTargetMap &target);
}