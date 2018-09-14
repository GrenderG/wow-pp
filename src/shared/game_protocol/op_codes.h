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

#pragma once

namespace wowpp
{
	namespace game
	{				
		/// Enumerates all OP codes sent by the client.
		namespace client_packet
		{
			enum
			{
				BootMe							= 0x001,		// UNHANDLED
				DbLookUp						= 0x002,		// UNHANDLED
				QueryObjectPosition				= 0x004,		// UNHANDLED
				QueryObjectRotation				= 0x006,		// UNHANDLED
				WorldTeleport					= 0x008,		// UNHANDLED
				ZoneMap							= 0x00A,		// UNHANDLED
				DebugChangeCellZone				= 0x00C,		// UNHANDLED
				EmblazonTabardObsolete			= 0x00D,		// UNHANDLED
				UnemblazonTabardObsolete		= 0x00E,		// UNHANDLED
				Recharge						= 0x00F,		// UNHANDLED
				LearnSpell						= 0x010,		// UNHANDLED
				CreateMonster					= 0x011,		// UNHANDLED
				DestroyMonster					= 0x012,		// UNHANDLED
				CreateItem						= 0x013,		// UNHANDLED
				CreateGameObject				= 0x014,		// UNHANDLED
				MakeMonsterAttackGuid			= 0x016,		// UNHANDLED
				BotDetected						= 0x017,		// UNHANDLED
				ForceAction						= 0x018,		// UNHANDLED
				ForceActionOnOther				= 0x019,		// UNHANDLED
				ForceActionShow					= 0x01A,		// UNHANDLED
				PetGodMode						= 0x01C,		// UNHANDLED
				WeatherSpeedCheat				= 0x01F,		// UNHANDLED
				UndressPlayer					= 0x020,		// UNHANDLED
				BeastMaster						= 0x021,		// UNHANDLED
				GodMode							= 0x022,		// UNHANDLED
				CheatSetMoney					= 0x024,		// UNHANDLED
				LevelCheat						= 0x025,		// UNHANDLED
				PetLevelCheat					= 0x026,		// UNHANDLED
				SetWorldState					= 0x027,		// UNHANDLED
				CooldownCheat					= 0x028,		// UNHANDLED
				UseSkillCheat					= 0x029,		// UNHANDLED
				FlagQuest						= 0x02A,		// UNHANDLED
				FlagQuestFinish					= 0x02B,		// UNHANDLED
				ClearQuest						= 0x02C,		// UNHANDLED
				SendEvent						= 0x02D,		// UNHANDLED
				DebugAIState					= 0x02E,		// UNHANDLED
				DisablePvPCheat					= 0x030,		// UNHANDLED
				AdvanceSpawnTime				= 0x031,		// UNHANDLED
				PvPPortObsolete					= 0x032,		// UNHANDLED
				AuthSRP6Begin					= 0x033,		// UNHANDLED
				AuthSRP6Proof					= 0x034,		// UNHANDLED
				AuthSRP6Recode					= 0x035,		// UNHANDLED
				CharCreate						= 0x036,		
				CharEnum						= 0x037,
				CharDelete						= 0x038,
				PlayerLogin						= 0x03D,
				GameTimeSet						= 0x044,		// UNHANDLED
				GameSpeedSet					= 0x046,		// UNHANDLED
				ServerTime						= 0x048,		// UNHANDLED
				PlayerLogout					= 0x04A,
				LogoutRequest					= 0x04B,
				LogoutCancel					= 0x04E,
				NameQuery						= 0x050,
				PetNameQuery					= 0x052,
				GuildQuery						= 0x054,		// UNHANDLED
				ItemQuerySingle					= 0x056,
				ItemQueryMultiple				= 0x057,
				PageTextQuery					= 0x05A,		// UNHANDLED
				QuestQuery						= 0x05C,
				GameObjectQuery					= 0x05E,
				CreatureQuery					= 0x060,
				Who								= 0x062,
				WhoIs							= 0x064,		// UNHANDLED
				ContactList						= 0x066,
				AddFriend						= 0x069,
				DeleteFriend					= 0x06A,
				SetContactNotes					= 0x06B,
				AddIgnore						= 0x06C,
				DeleteIgnore					= 0x06D,
				GroupInvite						= 0x06E,
				GroupCancel						= 0x070,		// UNHANDLED
				GroupAccept						= 0x072,
				GroupDecline					= 0x073,
				GroupUninvite					= 0x075,
				GroupUninviteGUID				= 0x076,
				GroupSetLeader					= 0x078,
				LootMethod						= 0x07A,
				GroupDisband					= 0x07B,
				UpdateGroupMembers				= 0x080,		// UNHANDLED
				GuildCreate						= 0x081,		// UNHANDLED
				GuildInvite						= 0x082,		// UNHANDLED
				GuildAccept						= 0x084,		// UNHANDLED
				GuildDecline					= 0x085,		// UNHANDLED
				GuildInfo						= 0x087,		// UNHANDLED
				GuildRoster						= 0x089,		// UNHANDLED
				GuildPromote					= 0x08B,		// UNHANDLED
				GuildDemote						= 0x08C,		// UNHANDLED
				GuildLeave						= 0x08D,		// UNHANDLED
				GuildRemove						= 0x08E,		// UNHANDLED
				GuildDisband					= 0x08F,		// UNHANDLED
				GuildLeader						= 0x090,		// UNHANDLED
				GuildMotd						= 0x091,		// UNHANDLED
				UpdateGuild						= 0x094,		// UNHANDLED
				MessageChat						= 0x095,
				JoinChannel						= 0x097,		// UNHANDLED
				LeaveChannel					= 0x098,		// UNHANDLED
				ChannelList						= 0x09A,		// UNHANDLED
				ChannelPassword					= 0x09C,		// UNHANDLED
				ChannelSetOwner					= 0x09D,		// UNHANDLED
				ChannelOwner					= 0x09E,		// UNHANDLED
				ChannelModerator				= 0x09F,		// UNHANDLED
				ChannelUnModerator				= 0x0A0,		// UNHANDLED
				ChannelMute						= 0x0A1,		// UNHANDLED
				ChannelUnmute					= 0x0A2,		// UNHANDLED
				ChannelInvite					= 0x0A3,		// UNHANDLED
				ChannelKick						= 0x0A4,		// UNHANDLED
				ChannelBan						= 0x0A5,		// UNHANDLED
				ChannelUnban					= 0x0A6,		// UNHANDLED
				ChannelAnnouncements			= 0x0A7,		// UNHANDLED
				ChannelModerate					= 0x0A8,		// UNHANDLED
				UseItem							= 0x0AB,
				OpenItem						= 0x0AC,
				ReadItem						= 0x0AD,		// UNHANDLED
				GameObjectUse					= 0x0B1,
				GameObjectChairUseObsolete		= 0x0B2,		// UNHANDLED
				AreaTrigger						= 0x0B4,
				MoveStartForward				= 0x0B5,
				MoveStartBackward				= 0x0B6,
				MoveStop						= 0x0B7,
				StartStrafeLeft					= 0x0B8,
				StartStrafeRight				= 0x0B9,
				StopStrafe						= 0x0BA,
				MoveJump						= 0x0BB,
				StartTurnLeft					= 0x0BC,
				StartTurnRight					= 0x0BD,
				StopTurn						= 0x0BE,
				StartPitchUp					= 0x0BF,
				StartPitchDown					= 0x0C0,
				StopPitch						= 0x0C1,
				MoveSetRunMode					= 0x0C2,
				MoveSetWalkMode					= 0x0C3,
				MoveToggleLogging				= 0x0C4,		// UNHANDLED
				MoveTeleport					= 0x0C5,		// UNHANDLED
				MoveTeleportCheat				= 0x0C6,		// UNHANDLED
				MoveTeleportAck					= 0x0C7,	// ACK
				MoveToggleFallLogging			= 0x0C8,		// UNHANDLED
				MoveFallLand					= 0x0C9,
				MoveStartSwim					= 0x0CA,
				MoveStopSwim					= 0x0CB,
				MoveSetRunSpeedCheat			= 0x0CC,		// UNHANDLED
				MoveSetRunSpeed					= 0x0CD,		// UNHANDLED
				MoveSetRunBackSpeedCheat		= 0x0CE,		// UNHANDLED
				MoveSetRunBackSpeed				= 0x0CF,		// UNHANDLED
				MoveSetWalkSpeedCheat			= 0x0D0,		// UNHANDLED
				MoveSetWalkSpeed				= 0x0D1,		// UNHANDLED
				MoveSetSwimSpeedCheat			= 0x0D2,		// UNHANDLED
				MoveSetSwimSpeed				= 0x0D3,		// UNHANDLED
				MoveSetSwimBackSpeedCheat		= 0x0D4,		// UNHANDLED
				MoveSetSwimBackSpeed			= 0x0D5,		// UNHANDLED
				MoveSetAllSpeedCheat			= 0x0D6,		// UNHANDLED
				MoveSetTurnRateCheat			= 0x0D7,		// UNHANDLED
				MoveSetTurnRate					= 0x0D8,		// UNHANDLED
				MoveToggleCollisionCheat		= 0x0D9,		// UNHANDLED
				SetFacing						= 0x0DA,
				SetPitch						= 0x0DB,
				MoveWorldPortAck				= 0x0DC,	// ACK
				MoveSetRawPositionAck			= 0x0E0,	// ACK
				ForceRunSpeedChangeAck			= 0x0E3,	// ACK
				ForceRunBackSpeedChangeAck		= 0x0E5,	// ACK
				ForceSwimSpeedChangeAck			= 0x0E7,	// ACK
				ForceMoveRootAck				= 0x0E9,	// ACK
				ForceMoveUnrootAck				= 0x0EB,	// ACK
				MoveRoot						= 0x0EC,		// UNHANDLED
				MoveUnroot						= 0x0ED,		// UNHANDLED
				MoveHeartBeat					= 0x0EE,
				MoveKnockBackAck				= 0x0F0,	// ACK
				MoveKnockBack					= 0x0F1,		// UNHANDLED
				MoveHoverAck					= 0x0F6,	// ACK
				MoveHover						= 0x0F7,		// UNHANDLED
				TriggerCinematicCheat			= 0x0F8,		// UNHANDLED
				OpeningCinematic				= 0x0F9,		// UNHANDLED
				NextCinematicCamera				= 0x0FB,		// UNHANDLED
				CompleteCinematic				= 0x0FC,
				TutorialFlag					= 0x0FE,
				TutorialClear					= 0x0FF,
				TutorialReset					= 0x100,
				StandStateChange				= 0x101,
				Emote							= 0x102,
				TextEmote						= 0x104,
				AutoEquipGroundItem				= 0x106,		// UNHANDLED
				AutoStoreGroundItem				= 0x107,		// UNHANDLED
				AutoStoreLootItem				= 0x108,
				StoreLootInSlot					= 0x109,		// UNHANDLED
				AutoEquipItem					= 0x10A,
				AutoStoreBagItem				= 0x10B,
				SwapItem						= 0x10C,
				SwapInvItem						= 0x10D,
				SplitItem						= 0x10E,
				AutoEquipItemSlot				= 0x10F,
				ObsoleteDropItem				= 0x110,		// UNHANDLED
				DestroyItem						= 0x111,
				Inspect							= 0x114,		// UNHANDLED
				InitateTrade					= 0x116,
				BeginTrade						= 0x117,
				BusyTrade						= 0x118,
				IgnoreTrade						= 0x119,
				AcceptTrade						= 0x11A,
				UnacceptTrade					= 0x11B,
				CancelTrade						= 0x11C,
				SetTradeItem					= 0x11D,
				ClearTradeItem					= 0x11E,
				SetTradeGold					= 0x11F,
				SetFactionAtWar					= 0x125,		// UNHANDLED
				SetFactionCheat					= 0x126,		// UNHANDLED
				SetActionButton					= 0x128,
				NewSpellSlot					= 0x12D,		// UNHANDLED
				CastSpell						= 0x12E,
				CancelCast						= 0x12F,
				CancelAura						= 0x136,
				ChannelStart					= 0x139,		// UNHANDLED
				ChannelUpdate					= 0x13A,		// UNHANDLED
				CancelChanneling				= 0x13B,
				SetSelection					= 0x13D,
				SetTargetObsolete				= 0x13E,		// UNHANDLED
				AttackSwing						= 0x141,
				AttackStop						= 0x142,
				SheatheObsolete					= 0x152,		// UNHANDLED
				SavePlayer						= 0x153,		// UNHANDLED
				SetDeathBindPoint				= 0x154,		// UNHANDLED
				GetDeathBindZone				= 0x156,		// UNHANDLED
				RepopRequest					= 0x15A,
				ResurrectResponse				= 0x15C,
				Loot							= 0x15D,
				LootMoney						= 0x15E,
				LootRelease						= 0x15F,
				DuelAccepted					= 0x16C,		// UNHANDLED
				DuelCancelled					= 0x16D,		// UNHANDLED
				MountSpecialAnim				= 0x171,		// UNHANDLED
				PetSetAction					= 0x174,		// UNHANDLED
				PetAction						= 0x175,		// UNHANDLED
				PetAbandon						= 0x176,		// UNHANDLED
				PetRename						= 0x177,		// UNHANDLED
				GossipHello						= 0x17B,
				GossipSelectOption				= 0x17C,		// UNHANDLED
				NpcTextQuery					= 0x17F,		// UNHANDLED
				QuestgiverStatusQuery			= 0x182,
				QuestgiverHello					= 0x184,
				QuestgiverQueryQuest			= 0x186,
				QuestgiverQuestAutolaunch		= 0x187,
				QuestgiverAcceptQuest			= 0x189,
				QuestgiverCompleteQuest			= 0x18A,
				QuestgiverRequestReward			= 0x18C,
				QuestgiverChooseReward			= 0x18E,
				QuestgiverCancel				= 0x190,
				QuestlogSwapQuest				= 0x193,		// UNHANDLED
				QuestlogRemoveQuest				= 0x194,
				QuestConfirmAccept				= 0x19B,		// UNHANDLED
				PshQuestToParty					= 0x19D,		// UNHANDLED
				ListInventory					= 0x19E,
				SellItem						= 0x1A0,
				BuyItem							= 0x1A2,
				BuyItemInSlot					= 0x1A3,
				TaxiClearAllNodes				= 0x1A6,		// UNHANDLED
				TaxiEnableAllNodes				= 0x1A7,		// UNHANDLED
				TaxiShowNodes					= 0x1A8,		// UNHANDLED
				TaxiNodeStatusQuery				= 0x1AA,		// UNHANDLED
				TaxiQueryAvailableNodes			= 0x1AC,		// UNHANDLED
				ActivateTaxi					= 0x1AD,		// UNHANDLED
				TrainerList						= 0x1B0,		// UNHANDLED
				TrainerBuySpell					= 0x1B2,
				BinderActivate					= 0x1B5,		// UNHANDLED
				BankerActivate					= 0x1B7,		// UNHANDLED
				BuyBankSlot						= 0x1B9,		// UNHANDLED
				PetitionShowList				= 0x1BB,		// UNHANDLED
				PetitionBuy						= 0x1BD,		// UNHANDLED
				PetitionShowSignatures			= 0x1BE,		// UNHANDLED
				PetitionSign					= 0x1C0,		// UNHANDLED
				PetitionDecline					= 0x1C2,		// UNHANDLED
				OfferPetition					= 0x1C3,		// UNHANDLED
				TurnInPetition					= 0x1C4,		// UNHANDLED
				PetitionQuery					= 0x1C5,		// UNHANDLED
				Bug								= 0x1CA,		// UNHANDLED
				PlayedTime						= 0x1CC,
				QueryTime						= 0x1CE,		// UNHANDLED
				ReclaimCorpse					= 0x1D2,		// UNHANDLED
				WrapItem						= 0x1D3,		// UNHANDLED
				MinimapPing						= 0x1D5,
				SetSkillCheat					= 0x1D8,		// UNHANDLED
				Ping							= 0x1DC,
				SetSheathed						= 0x1E0,
				PlayerMacroObsolete				= 0x1E3,		// UNHANDLED
				Ghost							= 0x1E5,		// UNHANDLED
				GmInvis							= 0x1E6,		// UNHANDLED
				GmBindOther						= 0x1E8,		// UNHANDLED
				GmSummon						= 0x1E9,		// UNHANDLED
				AuthSession						= 0x1ED,
				GmShowLabel						= 0x1EF,		// UNHANDLED
				PetCastSpell					= 0x1F0,		// UNHANDLED
				SaveGuildEmblem					= 0x1F1,		// UNHANDLED
				TabardVendorActivate			= 0x1F2,		// UNHANDLED
				ZoneUpdate						= 0x1F4,
				GmSetSecurityGroup				= 0x1F9,		// UNHANDLED
				GmNuke							= 0x1FA,		// UNHANDLED
				RandomRoll						= 0x1FB,		// UNHANDLED
				RWhoIsObsolete					= 0x1FD,		// UNHANDLED
				LookingForGroup					= 0x1FF,		// UNHANDLED
				SetLookingForGroup				= 0x200,		// UNHANDLED
				UnlearnSpell					= 0x201,		// UNHANDLED
				UnlearnSkill					= 0x202,		// UNHANDLED
				Decharge						= 0x204,		// UNHANDLED
				GmTicketCreate					= 0x205,		// UNHANDLED
				GmTicketUpdateText				= 0x207,		// UNHANDLED
				RequestAccountData				= 0x20A,		// UNHANDLED
				UpdateAccountData				= 0x20B,		// UNHANDLED
				GmTeach							= 0x20F,		// UNHANDLED
				GmCreateItemTarget				= 0x210,		// UNHANDLED
				GmTicketGetTicket				= 0x211,		// UNHANDLED
				UnlearnTalents					= 0x213,		// UNHANDLED
				CorpseQuery						= 0x216,		// UNHANDLED
				GmTicketDeleteTicket			= 0x217,		// UNHANDLED
				GmTicketSystemStatus			= 0x21A,
				SpiritHealerActivate			= 0x21C,		// UNHANDLED
				SetStatCheat					= 0x21D,		// UNHANDLED
				SkillBuyStep					= 0x21F,		// UNHANDLED
				XpCheat							= 0x221,		// UNHANDLED
				CharacterPointCheat				= 0x223,		// UNHANDLED
				ChatIgnored						= 0x225,		// UNHANDLED
				GmVision						= 0x226,		// UNHANDLED
				ServerCommand					= 0x227,		// UNHANDLED
				GmSilence						= 0x228,		// UNHANDLED
				GmRevealTo						= 0x229,		// UNHANDLED
				GmResurrect						= 0x22A,		// UNHANDLED
				GmSummonMob						= 0x22B,		// UNHANDLED
				GmMoveCorpse					= 0x22C,		// UNHANDLED
				GmFreeze						= 0x22D,		// UNHANDLED
				GmUberInvis						= 0x22E,		// UNHANDLED
				GmRequestPlayerInfo				= 0x22F,		// UNHANDLED
				GuildRank						= 0x231,		// UNHANDLED
				GuildAddRank					= 0x232,		// UNHANDLED
				GuildDelRank					= 0x233,		// UNHANDLED
				GuildSetPublicNote				= 0x234,		// UNHANDLED
				GuildSetOfficerNote				= 0x235,		// UNHANDLED
				ClearExploration				= 0x237,		// UNHANDLED
				MailSend						= 0x238,		
				MailGetList						= 0x23A,
				BattlefieldList					= 0x23C,		// UNHANDLED
				BattlefieldJoin					= 0x23E,		// UNHANDLED
				TaxiClearNode					= 0x241,		// UNHANDLED
				TaxiEnableNode					= 0x242,		// UNHANDLED
				MailGetBody						= 0x243,	// Unsure - seen this op code listed as CMSG_ITEM_TEXT_QUERY, need research
				MailTakeMoney					= 0x245,
				MailTakeItem					= 0x246,
				MailMarkAsRead					= 0x247,
				MailReturnToSender				= 0x248,
				MailDelete						= 0x249,
				MailCreateItemText				= 0x24A,
				LearnTalent						= 0x251,
				TogglePvP						= 0x253,
				AuctionHello					= 0x255,		// UNHANDLED
				AuctionSellItem					= 0x256,		// UNHANDLED
				AuctionRemoveItem				= 0x257,		// UNHANDLED
				AuctionListItems				= 0x258,		// UNHANDLED
				AuctionListOwnerItems			= 0x259,		// UNHANDLED
				AuctionPlaceBid					= 0x25A,		// UNHANDLED
				AuctionListBidderItems			= 0x264,		// UNHANDLED
				SetAmmo							= 0x268,		// UNHANDLED
				SetActiveMover					= 0x26A,		// UNHANDLED
				PetCancelAura					= 0x26B,		// UNHANDLED
				PlayerAICheat					= 0x26C,		// UNHANDLED
				CancelAutoRepeatSpell			= 0x26D,		// UNHANDLED
				GmAccountOnline					= 0x26E,		// UNHANDLED
				ListStabledPets					= 0x26F,		// UNHANDLED
				StablePet						= 0x270,		// UNHANDLED
				UnstablePet						= 0x271,		// UNHANDLED
				BuyStableSlot					= 0x272,		// UNHANDLED
				StableRevivePet					= 0x274,		// UNHANDLED
				StableSwapPet					= 0x275,		// UNHANDLED
				QuestPushResult					= 0x276,		// UNHANDLED
				RequestPetInfo					= 0x279,		// UNHANDLED
				FarSight						= 0x27A,		// UNHANDLED
				EnableDamageLog					= 0x27D,		// UNHANDLED
				GroupChangeSubGroup				= 0x27E,		// UNHANDLED
				RequestPartyMemberStats			= 0x27F,
				GroupSwapSubGroup				= 0x280,		// UNHANDLED
				ResetFactionCheat				= 0x281,		// UNHANDLED
				AutoStoreBankItem				= 0x282,		// UNHANDLED
				AutoBankItem					= 0x283,		// UNHANDLED
				MailQueryNextTime				= 0x284,
				SetDurabilityCheat				= 0x287,		// UNHANDLED
				SetPvPRankCheat					= 0x288,		// UNHANDLED
				AddPvPMedalCheat				= 0x289,		// UNHANDLED
				DelPvPMedalCheat				= 0x28A,		// UNHANDLED
				SetPvPTitle						= 0x28B,		// UNHANDLED
				GroupRaidConvert				= 0x28E,
				GroupAssistentLeader			= 0x28F,
				BuyBackItem						= 0x290,
				MeetingStoneJoin				= 0x292,		// UNHANDLED
				MeetingStoneCheat				= 0x294,		// UNHANDLED
				MeetingStoneInfo				= 0x296,		// UNHANDLED
				GmTicketSystemToggle			= 0x29A,		// UNHANDLED
				CancelGrowthItem				= 0x29B,		// UNHANDLED
				LootRoll						= 0x2A0,		// UNHANDLED
				LootMasterGive					= 0x2A3,		// UNHANDLED
				RepairItem						= 0x2A8,
				TalentWipeConfirm				= 0x2AA,		// UNHANDLED
				SummonResponse					= 0x2AC,		// UNHANDLED
				MoveToggleGravityCheat			= 0x2AD,		// UNHANDLED
				MoveFeatherFall					= 0x2B0,		// UNHANDLED
				MoveWaterWalk					= 0x2B1,		// UNHANDLED
				MsgSelfRes						= 0x2B3,		// UNHANDLED
				RunScript						= 0x2B5,		// UNHANDLED
				ToggleHelm						= 0x2B9,
				ToggleCloak						= 0x2BA,
				SetExploration					= 0x2BE,		// UNHANDLED
				SetActionBarToggles				= 0x2BF,
				DeleteGuildCharter				= 0x2C0,		// UNHANDLED
				PetitionRename					= 0x2C1,		// UNHANDLED
				ItemNameQuery					= 0x2C4,
				CharRename						= 0x2C7,
				MoveSplineDone					= 0x2C9,		// UNHANDLED
				MoveFallReset					= 0x2CA,
				RequestRaidInfo					= 0x2CD,		// UNHANDLED
				MoveTimeSkipped					= 0x2CE,
				MoveFeatherFallAck				= 0x2CF,	// ACK
				MoveWaterWalkAck				= 0x2D0,	// ACK
				MoveNotActiveMover				= 0x2D1,		// UNHANDLED
				BattlefieldStatus				= 0x2D3,		// UNHANDLED
				BattlefieldPort					= 0x2D5,		// UNHANDLED
				InspectHonorStats				= 0x2D6,		// UNHANDLED
				BattleMasterHello				= 0x2D7,		// UNHANDLED
				MoveStartSwimCheat				= 0x2D8,		// UNHANDLED
				MoveStopSwimCheat				= 0x2D9,		// UNHANDLED
				ForceWalkSpeedChangeAck			= 0x2DB,	// ACK
				ForceSwimBackSpeedChangeAck		= 0x2DD,	// ACK
				ForceTurnRateChangeAck			= 0x2DF,	// ACK
				PvPLogData						= 0x2E0,		// UNHANDLED
				LeaveBattlefield				= 0x2E1,		// UNHANDLED
				AreaSpiritHealerQuery			= 0x2E2,		// UNHANDLED
				AreaSpiritHealerQueue			= 0x2E3,		// UNHANDLED
				AreaSpiritHealerTime			= 0x2E4,		// UNHANDLED
				GmUnteach						= 0x2E5,		// UNHANDLED
				WardenData						= 0x2E7,		// UNHANDLED
				BattlegroundPlayerPositions		= 0x2E9,		// UNHANDLED
				PetStopAttack					= 0x2EA,		// UNHANDLED
				BattleMasterJoin				= 0x2EE,		// UNHANDLED
				PetUnlearn						= 0x2F0,		// UNAHNDLED
				PetSpellAutoCast				= 0x2F3,		// UNHANDLED
				MiniGameMove					= 0x2F8,		// UNHANDLED
				GuildInfoText					= 0x2FC,		// UNHANDLED
				GmNukeAccount					= 0x30F,		// UNHANDLED
				GmDestroyCorpse					= 0x310,		// UNHANDLED
				GmDestroyOnlineCorpse			= 0x311,		// UNHANDLED
				ActivateTaxiExpress				= 0x312,		// UNHANDLED
				DebugActionsStart				= 0x315,		// UNHANDLED
				DebugActionsStop				= 0x316,		// UNHANDLED
				SetFactionInactive				= 0x317,		// UNHANDLED
				SetWatchedFaction				= 0x318,		// UNHANDLED
				MsgMoveTimeSkipped				= 0x319,	// TODO: There is also CMSG_MOVE_TIME_SKIPPED (0x2CE), this here is MSG_MOVE_TIME_SKIPPED?
				SetExplorationAll				= 0x31B,		// UNHANDLED
				ResetInstances					= 0x31D,		// UNHANDLED
				RaidTargetUpdate				= 0x321,
				RaidReadyCheck					= 0x322,
				LuaUsage						= 0x323,		// UNHANDLED
				GmUpdateTicketStatus			= 0x327,		// UNHANDLED
				SetDungeonDifficulty			= 0x329,
				GmSurveySubmit					= 0x32A,		// UNHANDLED
				IgnoreKnockbackCheat			= 0x32C,		// UNHANDLED
				DelayGhostTeleport				= 0x32E,		// UNHANDLED
				ChatFiltered					= 0x331,		// UNHANDLED
				LotteryQueryObsolete			= 0x334,		// UNHANDLED
				BuyLotteryTicketObsolete		= 0x336,		// UNHANDLED
				GmResetInstanceLimit			= 0x33C,		// UNHANDLED
				MoveFlightAck					= 0x340,	// ACK
				MoveSetCanFlyAck				= 0x345,	// ACK
				MoveSetFly						= 0x346,
				SocketGems						= 0x347,		// UNHANDLED
				ArenaTeamCreate					= 0x348,		// UNHANDLED
				UpdateArenaTeamObsolete			= 0x34A,		// UNHANDLED
				ArenaTeamQuery					= 0x34B,		// UNHANDLED
				ArenaTeamRoster					= 0x34D,		// UNHANDLED
				ArenaTeamInvite					= 0x34F,		// UNHANDLED
				ArenaTeamAccept					= 0x351,		// UNHANDLED
				ArenaTeamDecline				= 0x352,		// UNHANDLED
				ArenaTeamLeave					= 0x353,		// UNHANDLED
				ArenaTeamRemove					= 0x354,		// UNHANDLED
				ArenaTeamDisband				= 0x355,		// UNHANDLED
				ArenaTeamLeader					= 0x356,		// UNHANDLED
				BattleMasterJoinArena			= 0x358,		// UNHANDLED
				MoveStartAscend					= 0x359,
				MoveStopAscend					= 0x35A,
				LfgSetAutoJoin					= 0x35C,		// UNHANDLED
				LfgClearAutoJoin				= 0x35D,		// UNHANDLED
				LfmSetAutoFill					= 0x35E,		// UNHANDLED
				LfmClearAutoFill				= 0x35F,		// UNHANDLED
				AcceptLfgMatch					= 0x360,		// UNHANDLED
				DeclineLfgMatch					= 0x361,		// UNHANDLED
				CancelPendingLfg				= 0x362,		// UNHANDLED
				ClearLookingForGroup			= 0x363,		// UNHANDLED
				ClearLookingForMore				= 0x364,		// UNHANDLED
				SetLookingForMore				= 0x365,		// UNHANDLED
				SetLfgComment					= 0x366,		// UNHANDLED
				SetTitle						= 0x374,		// UNHANDLED
				CancelMountAura					= 0x375,		// UNHANDLED
				InspectArenaTeams				= 0x377,		// UNHANDLED
				CancelTempEnchantment			= 0x379,		// UNHANDLED
				CheatSetHonorCurrency			= 0x37B,		// UNHANDLED
				CheatSetArenaCurrency			= 0x37C,		// UNHANDLED
				MoveSetFlightSpeedCheat			= 0x37D,		// UNHANDLED
				MoveSetFlightSpeed				= 0x37E,		// UNHANDLED
				MoveSetFlightBackSpeedCheat		= 0x37F,		// UNHANDLED
				MoveSetFlightBackSpeed			= 0x380,		// UNHANDLED
				ForceFlightSpeedChangeAck		= 0x382,	// ACK
				ForceFlightBackSpeedChangeAck	= 0x384,	// ACK
				MaelstromInvalidateCache		= 0x387,		// UNHANDLED
				SetTaxiBenchmarkMode			= 0x389,		// UNHANDLED
				RealmSplit						= 0x38C,
				MoveChangeTransport				= 0x38D,
				PartyAssignment					= 0x38E,		// UNHANDLED
				TimeSyncResponse				= 0x391,
				SendLocalEvent					= 0x392,		// UNHANDLED
				SendGeneralTrigger				= 0x393,		// UNHANDLED
				SendCombatTrigger				= 0x394,		// UNHANDLED
				MaelstromGmSentMail				= 0x395,		// UNHANDLED
				ActivePvPCheat					= 0x399,		// UNHANDLED
				CheatDumpItemsDebugOnly			= 0x39A,		// UNHANDLED
				VoiceSetTalkerMutedRequest		= 0x3A1,		// UNHANDLED
				MoveStartDescend				= 0x3A7,
				IgnoreRequiremensCheat			= 0x3A8,		// UNHANDLED
				//MoveSetRunSpeed					= 0x3AB,		// UNHANDLED
				//MoveUpdateCanFly					= 0x3AD,		// UNHANDLED
				RaidReadyCheckConfirm			= 0x3AE,		// UNHANDLED
				VoiceSessionEnable				= 0x3AF,
				GmWhisper						= 0x3B1,		// UNHANDLED
				GmGearRating					= 0x3B3,		// UNHANDLED
				CommentatorEnable				= 0x3B4,		// UNHANDLED
				CommentatorGetMapInfo			= 0x3B6,		// UNHANDLED
				CommentatorGetPlayerInfo		= 0x3B8,		// UNHANDLED
				CommentatorEnterInstance		= 0x3BB,		// UNHANDLED
				CommentatorExitInstance			= 0x3BC,		// UNHANDLED
				CommentatorInstanceCommand		= 0x3BD,		// UNHANDLED
				//BotDetected						= 0x3BF			// UNHANDLED
				CheatPlayerLogin				= 0x3C1,		// UNHANDLED
				CheatPlayerLookup				= 0x3C2,		// UNHANDLED
				RaidReadyCheckFinished			= 0x3C5,
				Complain						= 0x3C6,		// UNHANDLED
				GmShowComplaints				= 0x3C9,		// UNHANDLED
				GmUnsquelch						= 0x3CA,		// UNHANDLED
				ChannelSilenceVoice				= 0x3CB,		// UNHANDLED
				ChannelSilenceAll				= 0x3CC,		// UNHANDLED
				TargetCast						= 0x3CF,		// UNHANDLED
				TargetScriptCast				= 0x3D0,		// UNHANDLED
				ChannelDisplayList				= 0x3D1,		// UNHANDLED
				SetActiveVoiceChannel			= 0x3D2,		// UNHANDLED
				GetChannelMemberCount			= 0x3D3,
				ChannelVoiceOn					= 0x3D5,		// UNHANDLED
				ChannelVoiceOff					= 0x3D6,		// UNHANDLED
				DebugListTargets				= 0x3D7,		// UNHANDLED
				AddVoiceIgnore					= 0x3DA,		// UNHANDLED
				DelVoiceIgnore					= 0x3DB,		// UNHANDLED
				PartySilence					= 0x3DC,		// UNHANDLED
				NotifyPartySquelch				= 0x3DE,		// UNHANDLED
				ReportPvPAfk					= 0x3E3,		// UNHANDLED
				GuildBankerActivate				= 0x3E5,		// UNHANDLED
				GuildBankQueryTabs				= 0x3E6,		// UNHANDLED
				GuildBankList					= 0x3E7,		// UNHANDLED
				GuildBankSwapItems				= 0x3E8,		// UNHANDLED
				GuildBankBuyTab					= 0x3E9,		// UNHANDLED
				GuildBankUpdateTab				= 0x3EA,		// UNHANDLED
				GuildBankDepositMoney			= 0x3EB,		// UNHANDLED
				GuildBankWithdrawMoney			= 0x3EC,		// UNHANDLED
				GuildBankLogQuery				= 0x3ED,		// UNHANDLED
				SetChannelWatch					= 0x3EF,		// UNHANDLED
				ClearChannelWatch				= 0x3F2,		// UNHANDLED
				SetTitleSuffix					= 0x3F6,		// UNHANDLED
				SpellClick						= 0x3F7,		// UNHANDLED
				GmCharacterRestore				= 0x3F9,		// UNHANDLED
				GmCharacterSave					= 0x3FA,		// UNHANDLED
				GuildPermissions				= 0x3FC,		// UNHANDLED
				GuildBankMoneyWithdrawn			= 0x3FD,		// UNHANDLED
				GuildEventLogQuery				= 0x3FE,		// UNHANDLED
				MaelstromRenameGuild			= 0x3FF,		// UNHANDLED
				GetMirrorImageData				= 0x400,		// UNHANDLED
				IgnoreDimishingReturnsCheat		= 0x404,		// UNHANDLED
				KeepAlive						= 0x406,		// UNHANDLED
				OptOutOfLoot					= 0x408,
				QueryGuildBankText				= 0x409,		// UNHANDLED
				SetGuildBankText				= 0x40A,		// UNHANDLED
				SetGrantableLevels				= 0x40B,		// UNHANDLED
				GrantLevel						= 0x40C,		// UNHANDLED
				ReferAFriend					= 0x40D,		// UNHANDLED
				GmChangeArenaRating				= 0x40E,		// UNHANDLED
				DeclineChannelInvite			= 0x40F,		// UNHANDLED
				GroupActionThrottled			= 0x410,		// UNHANDLED
				TotemDestroyed					= 0x413,		// UNHANDLED
				ExpireRaidInstance				= 0x414,		// UNHANDLED
				NoSpellVariance					= 0x415,		// UNHANDLED
				QuestgiverStatusMultipleQuery	= 0x416,
				SetPlayerDeclinedNames			= 0x418,		// UNHANDLED
				QueryServerBuckData				= 0x41A,		// UNHANDLED
				ClearServerBuckData				= 0x41B,		// UNHANDLED
				AcceptLevelGrant				= 0x41F			// UNHANDLED
			};
		}

		/// Enumerates possible OP codes which the server can send to the client.
		/// OP codes taken from the MaNGOS project: http://www.getmangos.eu
		namespace server_packet
		{
			enum
			{
				TriggerCinematic			= 0x0FA,
				CharCreate					= 0x03A,
				CharEnum					= 0x03B,
				CharDelete					= 0x03C,
				NewWorld					= 0x03E,
				TransferPending				= 0x03F,
				TransferAborted				= 0x040,
				CharacterLoginFailed		= 0x041,
				LoginSetTimeSpeed			= 0x042,
				LogoutResponse				= 0x04C,
				LogoutComplete				= 0x04D,
				LogoutCancelAck				= 0x04F,
				NameQueryResponse			= 0x051,
				PetNameQueryResponse		= 0x053,
				ItemQuerySingleResponse		= 0x058,
				ItemQueryMultipleResponse	= 0x059,
				QuestQueryResponse			= 0x05D,
				GameObjectQueryResponse		= 0x05F,
				CreatureQueryResponse		= 0x061,
				WhoResponse					= 0x063,
				ContactList					= 0x067,
				FriendStatus				= 0x068,
				GroupInvite					= 0x06F,
				GroupCancel					= 0x071,
				GroupDecline				= 0x074,
				GroupUninvite				= 0x077,
				GroupSetLeader				= 0x079,
				GroupDestroyed				= 0x07C,
				GroupList					= 0x07D,
				PartyMemberStats			= 0x07E,
				PartyCommandResult			= 0x07F,
				MessageChat					= 0x096,
				UpdateObject				= 0x0A9,
				DestroyObject				= 0x0AA,
				MoveTeleport				= 0x0C5,
				MoveTeleportAck				= 0x0C7,
				MoveSetRunSpeed				= 0x0CD,
				MoveSetRunBackSpeed			= 0x0CF,
				MoveSetWalkSpeed			= 0x0D1,
				MoveSetSwimSpeed			= 0x0D3,
				MoveSetSwimBackSpeed		= 0x0D5,
				MoveSetTurnRate				= 0x0D8,
				MonsterMove					= 0x0DD,
				MoveWaterWalk				= 0x0DE,
				MoveLandWalk				= 0x0DF,
				ForceRunSpeedChange			= 0x0E2,
				ForceRunBackSpeedChange		= 0x0E4,
				ForceSwimSpeedChange		= 0x0E6,
				ForceMoveRoot				= 0x0E8,
				ForceMoveUnroot				= 0x0EA,
				MoveRoot					= 0x0EC,
				MoveUnroot					= 0x0ED,
				MoveHeartBeat				= 0x0EE,
				MoveKnockBack				= 0x0EF,	// Sent ONLY to affected client
				MoveKnockBack2				= 0x0F1,	// Sent to other clients that are not affected
				MoveFeatherFall				= 0x0F2,
				MoveNormalFall				= 0x0F3,
				MoveSetHover				= 0x0F4,	// Force packet
				MoveUnsetHover				= 0x0F5,	
				MoveHover					= 0x0F7,	// Packet for other players (viewer)
				TutorialFlags				= 0x0FD,
				Emote						= 0x103,
				TextEmote					= 0x105,
				InventoryChangeFailure		= 0x112,
				TradeStatus					= 0x120,   //Trade
				TradeStatusExtended			= 0x121,   //Trade
				InitializeFactions			= 0x122,
				SetProficiency				= 0x127,
				ActionButtons				= 0x129,
				InitialSpells				= 0x12A,
				LearnedSpell				= 0x12B,
				SupercededSpell				= 0x12C,
				CastFailed					= 0x130,
				SpellStart					= 0x131,
				SpellGo						= 0x132,
				SpellFailure				= 0x133,
				SpellCooldown				= 0x134,
				CooldownEvent				= 0x135,
				UpdateAuraDuration			= 0x137,
				ChannelStart				= 0x139,
				ChannelUpdate				= 0x13A,
				AiReaction					= 0x13C,
				AttackStart					= 0x143,
				AttackStop					= 0x144,
				AttackSwingNotInRange		= 0x145,
				AttackSwingBadFacing		= 0x146,
				AttackSwingNotStanding		= 0x147,
				AttackSwingDeadTarget		= 0x148,
				AttackSwingCantAttack		= 0x149,
				AttackerStateUpdate			= 0x14A,
				SpellHealLog				= 0x150,
				SpellEnergizeLog			= 0x151,
				BindPointUpdate				= 0x155,
				ResurrectRequest			= 0x15B,
				LootResponse				= 0x160,
				LootReleaseResponse			= 0x161,
				LootRemoved					= 0x162,
				LootMoneyNotify				= 0x163,
				LootItemNotify				= 0x164,
				LootClearMoney				= 0x165,
				ItemPushResult				= 0x166,
				PetSpells					= 0x179,
				GossipMessage				= 0x17D,
				GossipComplete				= 0x17E,
				QuestgiverStatus			= 0x183,
				QuestgiverQuestList			= 0x185,
				QuestgiverQuestDetails		= 0x188,
				QuestgiverRequestItems		= 0x18B,
				QuestgiverOfferReward		= 0x18D,
				QuestgiverQuestComplete		= 0x191,
				QuestlogFull				= 0x195,
				QuestupdateComplete			= 0x198,
				QuestupdateAddKill			= 0x199,
				QuestupdateAddItem			= 0x19A,		// Unused?
				ListInventory				= 0x19F,
				SellItem					= 0x1A1,
				TrainerList					= 0x1B1,
				TrainerBuySucceeded			= 0x1B3,
				TrainerBuyFailed			= 0x1B4,
				Notification				= 0x1CB,
				PlayedTime					= 0x1CD,
				LogXPGain					= 0x1D0,
				MinimapPing					= 0x1D5,
				Pong						= 0x1DD,
				ClearCooldown				= 0x1DE,
				LevelUpInfo					= 0x1D4,
				SpellDelayed				= 0x1E2,
				AuthChallenge				= 0x1EC,
				AuthResponse				= 0x1EE,
				PlaySpellVisual				= 0x1F3,
				CompressedUpdateObject		= 0x1F6,
				PlaySpellImpact				= 0x1F7,
				ExplorationExperience		= 0x1F8,
				EnvironmentalDamageLog		= 0x1FC,
				AccountDataTimes			= 0x209,
				ChatWrongFaction			= 0x219,
				GmTicketSystemStatus		= 0x21B,
				SetRestStart				= 0x21E,
				LoginVerifyWorld			= 0x236,
				MailSendResult				= 0x239,
				MailListResult				= 0x23B,
				MailSendBody				= 0x244,
				SpellLogMiss				= 0x24B,
				PeriodicAuraLog				= 0x24E,
				SpellDamageShield			= 0x24F,
				SpellNonMeleeDamageLog		= 0x250,
				SetFlatSpellModifier		= 0x266,
				SetPctSpellModifier			= 0x267,
				MailQueryNextTime			= 0x284,
				MailReceived				= 0x285,
				StandStateUpdate			= 0x29D,
				LootStartRoll				= 0x2A1,
				SpellFailedOther			= 0x2A6,
				ChatPlayerNotFound			= 0x2A9,
				DurabilityDamageDeath		= 0x2BD,
				InitWorldStates				= 0x2C2,
				ItemNameQueryResponse		= 0x2C5,
				CharRename					= 0x2C8,
				PlaySound					= 0x2D2,
				ForceWalkSpeedChange		= 0x2DA,
				ForceSwimBackSpeedChange	= 0x2DC,
				ForceTurnRateChange			= 0x2DE,
				AddonInfo					= 0x2EF,
				PartyMemberStatsFull		= 0x2F2,
				MoveTimeSkipped				= 0x319,
				InvalidatePlayer			= 0x31C,
				RaidTargetUpdate			= 0x321,
				RaidReadyCheck				= 0x322,
				SetDungeonDifficulty		= 0x329,
				Motd						= 0x33D,
				MoveSetCanFly				= 0x343,
				MoveUnsetCanFly				= 0x344,
				SetFlightSpeed				= 0x37E,
				SetFlightBackSpeed			= 0x380,
				ForceFlightSpeedChange		= 0x381,
				ForceFlightBackSpeedChange	= 0x383,
				TimeSyncReq					= 0x390,
				UpdateComboPoints			= 0x39D,
				SetExtraAuraInfo			= 0x3A4,
				SetExtraAuraInfoNeedUpdate	= 0x3A5,
				ClearExtraAuraInfo			= 0x3A6,
				RaidReadyCheckConfirm		= 0x3AE,
				RaidReadyCheckFinished		= 0x3C5,
				FeatureSystemStatus			= 0x3C8,
				QuestgiverStatusMultiple	= 0x417,
				UnlearnSpells				= 0x41D
			};
		}
	}
}