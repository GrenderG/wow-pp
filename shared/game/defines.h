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

#include "common/typedefs.h"
#include <map>

namespace wowpp
{
	namespace game
	{
		namespace gender
		{
			enum Type
			{
				Male		= 0x00,
				Female		= 0x01,
				None		= 0x02,

				Max			= 0x02
			};
		}

		typedef gender::Type Gender;

		namespace race
		{
			enum Type
			{
				Human		= 0x01,
				Orc			= 0x02,
				Dwarf		= 0x03,
				NightElf	= 0x04,
				Undead		= 0x05,
				Tauren		= 0x06,
				Gnome		= 0x07,
				Troll		= 0x08,
				Goblin		= 0x09,
				BloodElf	= 0x0A,
				Draenei		= 0x0B,

				AllPlayable = ((1 << (Human - 1)) | (1 << (Orc - 1)) | (1 << (Dwarf - 1)) | (1 << (NightElf - 1)) | (1 << (Undead - 1)) | (1 << (Tauren - 1)) | (1 << (Gnome - 1)) | (1 << (Troll - 1)) | (1 << (BloodElf - 1)) | (1 << (Draenei - 1))),
				Alliance = ((1 << (Human - 1)) | (1 << (Dwarf - 1)) | (1 << (NightElf - 1)) | (1 << (Gnome - 1)) | (1 << (Draenei - 1))),
				Horde = ((1 << (Orc - 1)) | (1 << (Undead - 1)) | (1 << (Tauren - 1)) | (1 << (Troll - 1)) | (1 << (BloodElf - 1))),

				Max			= 0x0B
			};
		}

		typedef race::Type Race;

		namespace char_class
		{
			enum Type
			{
				Warrior		= 0x01,
				Paladin		= 0x02,
				Hunter		= 0x03,
				Rogue		= 0x04,
				Priest		= 0x05,
				Shaman		= 0x07,
				Mage		= 0x08,
				Warlock		= 0x09,
				Druid		= 0x0B,

				AllPlayable = ((1 << (Warrior - 1)) | (1 << (Paladin - 1)) | (1 << (Hunter - 1)) | (1 << (Rogue - 1)) | (1 << (Priest - 1)) | (1 << (Shaman - 1)) | (1 << (Mage - 1)) | (1 << (Warlock - 1)) | (1 << (Druid - 1))),
				AllCreature = ((1 << (Warrior - 1)) | (1 << (Paladin - 1)) | (1 << (Mage - 1))),
				WandUsers	= ((1 << (Priest - 1)) | (1 << (Mage - 1)) | (1 << (Warlock - 1))),

				Max			= 0x0C
			};
		}

		typedef char_class::Type CharClass;

		namespace chat_msg
		{
			enum Type
			{
				Addon				= 0xFFFFFFFF,
				System				= 0x00,
				Say					= 0x01,
				Party				= 0x02,
				Raid				= 0x03,
				Guild				= 0x04,
				Officer				= 0x05,
				Yell				= 0x06,
				Whisper				= 0x07,
				WhisperInform		= 0x08,
				Reply				= 0x09,
				Emote				= 0x0A,
				TextEmote			= 0x0B,
				MonsterSay			= 0x0C,
				MonsterParty		= 0x0D,
				MonsterYell			= 0x0E,
				MonsterWhisper		= 0x0F,
				MonsterEmote		= 0x10,
				Channel				= 0x11,
				ChannelJoin			= 0x12,
				ChannelLeave		= 0x13,
				ChannelList			= 0x14,
				ChannelNotice		= 0x15,
				ChannelNoticeUser	= 0x16,
				Afk					= 0x17,
				Dnd					= 0x18,
				Ignored				= 0x19,
				Skill				= 0x1A,
				Loot				= 0x1B,
				Money				= 0x1C,
				Opening				= 0x1D,
				TradeSkill			= 0x1E,
				PetInfo				= 0x1F,
				CombatMiscInfo		= 0x20,
				CombatXPGain		= 0x21,
				CombatHonorGain		= 0x22,
				CombatFactionChange	= 0x23,
				BGSystemNeutral		= 0x24,
				BGSystemAlliance	= 0x25,
				BGSystemHorde		= 0x26,
				RaidLeader			= 0x27,
				RaidWarning			= 0x28,
				RaidBossWhisper		= 0x29,
				RaidBossEmote		= 0x2A,
				Filtered			= 0x2B,
				Battleground		= 0x2C,
				BattlegroundLeader	= 0x2D,
				Restricted			= 0x2E
			};
		}

		typedef chat_msg::Type ChatMsg;

		namespace language
		{
			enum Type
			{
				Universal			= 0x00,
				Orcish				= 0x01,
				Darnassian			= 0x02,
				Taurahe				= 0x03,
				Dwarvish			= 0x04,
				Common				= 0x07,
				Demonic				= 0x08,
				Titan				= 0x09,
				Thalassian			= 0x0A,
				Draconic			= 0x0B,
				Kalimag				= 0x0C,
				Gnomish				= 0x0D,
				Troll				= 0x0E,
				GutterSpeak			= 0x21,
				Draenei				= 0x23,
				Zombie				= 0x24,
				GnomishBinary		= 0x25,
				GoblinBinary		= 0x26,
				Addon				= 0xFFFFFFFF,

				Count_				= 0x13
			};
		}

		typedef language::Type Language;

		namespace movement_flags
		{
			enum Type
			{
				None = 0x00000000,
				Forward = 0x00000001,
				Backward = 0x00000002,
				StrafeLeft = 0x00000004,
				StrafeRight = 0x00000008,
				TurnLeft = 0x00000010,
				TurnRight = 0x00000020,
				PitchUp = 0x00000040,
				PitchDown = 0x00000080,
				WalkMode = 0x00000100,
				OnTransport = 0x00000200,
				Levitating = 0x00000400,
				Root = 0x00000800,
				Falling = 0x00001000,
				FallingFar = 0x00004000,
				Swimming = 0x00200000,
				Ascending = 0x00400000,
				CanFly = 0x00800000,
				Flying = 0x01000000,
				Flying2 = 0x02000000,
				SplineElevation = 0x04000000,
				SplineEnabled = 0x08000000,
				WaterWalking = 0x10000000,
				SafeFall = 0x20000000,
				Hover = 0x40000000,

				Moving =
				Forward | Backward | StrafeLeft | StrafeRight | PitchUp | PitchDown |
				Falling | FallingFar | Ascending | Flying2 | SplineElevation,
				Turning =
				TurnLeft | TurnRight,
			};
		}

		typedef movement_flags::Type MovementFlags;

		namespace spline_flags
		{
			enum Type
			{
				None = 0x00000000,
				Jump = 0x00000008,
				WalkMode = 0x00000100,
				Flying = 0x00000200
			};
		}

		typedef spline_flags::Type SplineFlags;

		namespace friend_result
		{
			enum Type
			{
				DatabaseError		= 0x00,
				ListFull			= 0x01,
				Online				= 0x02,
				Offline				= 0x03,
				NotFound			= 0x04,
				Removed				= 0x05,
				AddedOnline			= 0x06,
				AddedOffline		= 0x07,
				AlreadyAdded		= 0x08,
				Self				= 0x09,
				Enemy				= 0x0A,
				IgnoreFull			= 0x0B,
				IgnoreSelf			= 0x0C,
				IgnoreNotFound		= 0x0D,
				IgnoreAlreadyAdded	= 0x0E,
				IgnoreAdded			= 0x0F,
				IgnoreRemoved		= 0x10,
				IgnoreAmbigous		= 0x11,     // That name is ambiguous, type more of the player's server name
				MuteFull			= 0x12,
				MuteSelf			= 0x13,
				MuteNotFound		= 0x14,
				MuteAlreadyAdded	= 0x15,
				MuteAdded			= 0x16,
				MuteRemoved			= 0x17,
				MuteAmbigous		= 0x18,     // That name is ambiguous, type more of the player's server name
				Unknown_7			= 0x19,     // no message at client
				Uknown				= 0x1A      // Unknown friend response from server
			};
		}

		typedef friend_result::Type FriendResult;

		namespace friend_status
		{
			enum Type
			{
				Offline		= 0x00,
				Online		= 0x01,
				Afk			= 0x02,
				Dnd			= 0x04,
				Raf			= 0x08
			};
		}

		typedef friend_status::Type FriendStatus;

		namespace social_flag
		{
			enum Type
			{
				Friend		= 0x01,
				Ignored		= 0x02,
				Muted		= 0x04
			};
		}

		typedef social_flag::Type SocialFlag;

		// TODO: Move this?
		struct SocialInfo final
		{
			FriendStatus status;
			UInt32 flags;
			UInt32 area;
			UInt32 level;
			UInt32 class_;
			String note;

			/// 
			SocialInfo()
				: status(friend_status::Offline)
				, flags(0)
				, area(0)
				, level(0)
				, class_(0)
			{
			}

			/// 
			explicit SocialInfo(UInt32 flags_, String note_)
				: status(friend_status::Offline)
				, flags(flags_)
				, area(0)
				, level(0)
				, class_(0)
				, note(std::move(note_))
			{
			}
		};

		typedef std::map<UInt64, SocialInfo> SocialInfoMap;
	}
}
