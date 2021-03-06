EverGrandeCity_HallOfFame_MapScripts:: @ 822982C
	map_script ON_FRAME, EverGrandeCity_HallOfFame_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_HallOfFame_OnWarp
	.byte 0

EverGrandeCity_HallOfFame_OnWarp: @ 8229837
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_HallOfFame_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_HallOfFame_EventScript_TurnPlayerNorth:: @ 8229841
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_HallOfFame_OnFrame: @ 8229846
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_HallOfFame_EventScript_EnterHallOfFame
	.2byte 0

EverGrandeCity_HallOfFame_EventScript_EnterHallOfFame:: @ 8229850
	call RyuResetFollowerPositionAR
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, AltHallofFame
	applymovement 1, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
	applymovement OBJ_EVENT_ID_FOLLOWER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox EverGrandeCity_HallOfFame_Text_HereWeHonorLeagueChampions, MSGBOX_DEFAULT
	closemessage
	applymovement 1, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
	applymovement OBJ_EVENT_ID_FOLLOWER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
	waitmovement 0
	delay 20
	applymovement 1, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox EverGrandeCity_HallOfFame_Text_LetsRecordYouAndYourPartnersNames, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
	delay 40
	setvar VAR_TEMP_1, 1
	call EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags
	callnative TryGiveLeetAch
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq EverGrandeCity_HallOfFame_EventScript_GameClearMale
	compare VAR_RESULT, FEMALE
	goto_if_eq EverGrandeCity_HallOfFame_EventScript_GameClearFemale
	end

AltHallofFame::
	applymovement 1, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
	applymovement OBJ_EVENT_ID_FOLLOWER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox EGC_HOF_Player1, MSGBOX_DEFAULT
	closemessage
	applymovement 1, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
	applymovement OBJ_EVENT_ID_FOLLOWER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
	waitmovement 0
	delay 20
	applymovement 1, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox EGC_HOF_Player2, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
	delay 40
	setvar VAR_TEMP_1, 1
	call EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags
	setflag FLAG_RYU_FIRST_GAME_CLEAR
	call RyuLegendary_GameClearResetLegends
	ach give ACH_HOENN_CHAMPION
	callnative TryGiveLeetAch
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq EverGrandeCity_HallOfFame_EventScript_GameClearMale
	compare VAR_RESULT, FEMALE
	goto_if_eq EverGrandeCity_HallOfFame_EventScript_GameClearFemale
	end

EverGrandeCity_HallOfFame_EventScript_GameClearMale:: @ 82298E9
	setflag FLAG_RYU_HIDE_REL_OBJECTS
	call_if_set FLAG_RYU_NUZLOCKEMODE, EGC_NLGameClear
	call_if_set FLAG_RYU_HARDCORE_MODE, EGC_HCGameClear
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	clearflag FLAG_RYU_WAYSTONE_DISABLED
	fadescreenspeed FADE_TO_BLACK, 24
	setflag FLAG_SYS_GAME_CLEAR
	special GameClear
	waitstate
	releaseall
	end

EverGrandeCity_HallOfFame_EventScript_GameClearFemale:: @ 82298F5
	setflag FLAG_RYU_HIDE_REL_OBJECTS
	call_if_set FLAG_RYU_NUZLOCKEMODE, EGC_NLGameClear
	call_if_set FLAG_RYU_HARDCORE_MODE, EGC_HCGameClear
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_DAWNS_HOUSE_2F
	clearflag FLAG_RYU_WAYSTONE_DISABLED
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	waitstate
	releaseall
	end

EGC_NLGameClear::
	clearflag FLAG_RYU_NUZLOCKEMODE
	setvar VAR_RYU_PRICE_MULTIPLIER, 1000
	setvar VAR_RYU_EXP_MULTIPLIER, 2000
	msgbox RyuGameClearedMsg MSGBOX_DEFAULT
	closemessage
	return

EGC_HCGameClear::
	clearflag FLAG_RYU_HARDCORE_MODE
	setvar VAR_RYU_PRICE_MULTIPLIER, 1000
	setvar VAR_RYU_EXP_MULTIPLIER, 2000
	goto_if_set FLAG_RYU_DEV_MODE, EGC_HCGameClearDev
	msgbox RyuGameClearedHCMessage
	return

EGC_HCGameClearDev::
	msgbox EGC_GameClearDevModeMsg
	return

EGC_GameClearDevModeMsg:
	.string "I would congratulate you, but\nyou are in dev mode.\pTry beating it without cheats!$"


RyuGameClearedHCMessage:
	.string "Holy shit! You actually managed\nto clear hardcore mode.\pI would very much like to see\nproof of this in the discord!$"


EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1: @ 8229901
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2: @ 8229908
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EverGrandeCity_HallOfFame_Text_HereWeHonorLeagueChampions: @ 822990E
	.string "Wallace: This room…\p"
	.string "This is where we keep records of\n"
	.string "Pokémon that prevailed through\l"
	.string "harsh battles.\p"
	.string "It is here that the League Champions\n"
	.string "are honored.$"

EverGrandeCity_HallOfFame_Text_LetsRecordYouAndYourPartnersNames: @ 82299A3
	.string "Wallace: Come on, let's record your\n"
	.string "name as a Trainer who triumphed over\l"
	.string "the Pokémon League, and the names of\l"
	.string "the partners who battled with you.$"

EGC_HOF_Player1:
	.string "Wallace: I see you had a challenger.\nEven if a challenger fails, the event\phas to be recorded in this database.\nThey're still honored for their attempt.$"
	
EGC_HOF_Player2:
	.string "Lets put your new data,\nas well as your challenger's data\pinto the system for the records.\pWe'll take care of the rest\lof the paper work.$"


