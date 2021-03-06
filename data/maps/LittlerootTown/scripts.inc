LittlerootTown_MapScripts:: @ 81E7DCB
	map_script ON_TRANSITION, LittlerootTown_MapScript1_1E7DDB
	map_script ON_FRAME, Ryu_HaremEventCheck
	.byte 0

Ryu_HaremEventCheck::
	map_script_2 VAR_RYU_PARTNER_COUNT, 5, Ryu_HaremEvent
	.2byte 0

	
LRT_CheckMagmaWarp::
	setvar VAR_TEMP_7, 0
	compare VAR_RYU_MAGMA, 570
	goto_if_ne ryu_end
	warpsilent MAP_LRT_BIRCH_LAB_MAGMA_EVENT, 0, 6, 12
	waitstate

LittlerootTown_MapScript1_1E7DDB: @ 81E7DDB
	call Common_EventScript_SetupRivalGfxId
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	call RyuCheckForWellTravelledAch
	end
	
LRT_FollowerTest::
	lock
	fadescreen FADE_TO_BLACK
	drawfullscreenimage SCENEBGMINNIE
	msgbox LRT_FollowerMinnie MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne LRT_CancelFollower
	closemessage
	goto_if_set FLAG_RYU_HAS_FOLLOWER, LRT_AlreadyHasFollower
	setflag FLAG_RYU_HIDE_MINNIE
	setflag FLAG_RYU_RECRUITED_MINNIE
	ach give ACH_NEW_REGION_WHO_DIS
	removeobject 4
	createfollower OBJ_EVENT_GFX_TWIN, RyuFollowerSelectNPCScript, 1
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	release
	end

LRT_AlreadyHasFollower::
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	msgbox LRT_AlreadyFollowerMsg
	closemessage
	release
	end

LRT_AlreadyFollowerMsg:
	.string "{COLOR LIGHT_RED}{SHADOW RED}But you already have a friend\nwith you...$"
	
LRT_CancelFollower::
	msgbox LRT_NoFollower
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	closemessage
	end
	
LRT_MinnieScript::
	msgbox LRT_FollowerHeal MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq LRT_RemoveMinnie
	closemessage
	end

facingMsg:
	.string "You're facing direction {STR_VAR_2}!$"

LRT_RemoveMinnie:
	msgbox LRT_MinnieLeave
	closemessage
	destroyfollower
	clearflag FLAG_RYU_HIDE_MINNIE
	msgbox RyuFollowerLeavesService
	clearflag FLAG_RYU_HAS_FOLLOWER
	release
	end

LRT_MinnieLeave:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Minnie: Okay! Have fun!$"
	
LRT_FollowerMinnie:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Hi! I'm Minnie!\nMy sister guards the exit.\pI'm a bodyguard. Can I come with you?$"
	
LRT_NoFollower::
	.string "{COLOR LIGHT_RED}{SHADOW RED}Okay!\nLet me know if you change your mind!$"
	
LRT_FollowerHeal:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Minnie: Do you want me to leave?$"
	
LRT_BirchLabSignNormal::
	special RyuDevCheck
	compare VAR_RESULT, 69
	goto_if_eq LRT_SealedChamber
	msgbox BirchsLabSign MSGBOX_SIGN
	release
	end
	
LRT_SealedChamber:
	warpteleport MAP_SEALED_CHAMBER_OUTER_ROOM, 0, 0, 0
	release
	end
	
LRT_sign::
	msgbox LittlerootSign MSGBOX_SIGN
	release
	end
	
LittlerootSign:
	.string "Littleroot Town\pThe town of humble beginnings.$"

BirchsLabSign: @ 81E8D69
	.string "Prof. Birch's Pokémon Lab$"
	
LRT_LittleGirlChatter::
	lock
	faceplayer
	msgbox LRT_LittleGirl MSGBOX_DEFAULT
	release
	end
	
LRT_LittleGirl:
	.string "Cute Girl: {COLOR LIGHT_RED}{SHADOW RED}Hi! I'm on guard duty!\nDon't go outside without friends, okay?$"

LRT_PreventLeave::
	goto_if_set FLAG_RYU_MET_RIVAL_LITTLEROOT, ryu_end
	lock
	faceplayer
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, LRT_StepRight
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, FEMALE
	goto_if_eq LRT_cantLeaveFemale
	msgbox LRT_Girl_PreventLeave MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, LRT_CantLeave
	applymovement 1, LRT_StepLeft
	waitmovement 0
	release
	end
	
LRT_cantLeaveFemale:
	msgbox LRT_Girl_PreventLeaveFemale MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, LRT_CantLeave
	applymovement 1, LRT_StepLeft
	waitmovement 0
	release
	end
	
LRT_Girl_PreventLeaveFemale:
	.string "Cute Girl: {COLOR LIGHT_RED}{SHADOW RED}Um! Lady!\pIt's dangerous to go out there\nwithout Pokémon to protect you!$"
	
	
LRT_StepLeft:
	walk_left
	walk_in_place_down
	step_end

LRT_StepRight:
	walk_right
	walk_in_place_right
	step_end

LRT_Girl_PreventLeave:
	.string "Cute Girl: {COLOR LIGHT_RED}{SHADOW RED}Um! Mister!\pIt's dangerous to go out there\nwithout Pokémon to protect you!$"
	
LRT_CantLeave:
	walk_down
	walk_down
	step_end

LRT_BrendansHouseSign:: @ 81E818F
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LRT_PlayerHouseSign
	goto LRT_RivalHouseSign
	end
	
LRT_DawnsHouseSign::
	lockall
	checkplayergender
	compare VAR_RESULT, FEMALE
	goto_if_eq LRT_PlayerHouseSign
	goto LRT_RivalHouseSign
	end

LRT_RivalHouseSign:: @ 81E81A9
	msgbox LRT_RIVALHOUSESIGNMSG, MSGBOX_DEFAULT
	releaseall
	end

LRT_PlayerHouseSign:: @ 81E81B2
	msgbox LRT_PLAYERHOUSESIGNMSG, MSGBOX_DEFAULT
	releaseall
	end
	
LRT_PLAYERHOUSESIGNMSG:
	.string "{PLAYER}'s House$"
	
LRT_RIVALHOUSESIGNMSG:
	.string "{RIVAL}'s House$"

LRT_GameStartInfoMsg:
	.string "New Game Flags and Variables Set.$"
	
LRT_StopGoingSouth::
	getpartysize
	compare VAR_RESULT, 0
	goto_if_eq LRT_StopPlayer
	release
	end

LRT_StopPlayer::
	msgbox LRT_CantExitSouthYet MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepUp
	waitmovement 0
	release
	end
	
LRT_CantExitSouthYet:
	.string "You have no Pokémon, you probably\ndon't want to go down here yet.$"
	
LRT_BoyChatter::
	lock
	faceplayer
	msgbox LRT_BC1 MSGBOX_DEFAULT
	release
	end
	
LRT_BC1:
	.string "Young Boy: Science is amazing!\p" 
	.string "People these days can modify data\n" 
	.string "within a regular game to create\l" 
	.string "a whole new experience!$"
	
LRT_FatManChatter::
	lock
	faceplayer
	msgbox LRT_FM1 MSGBOX_DEFAULT
	closemessage
	fadenewbgm MUS_DUMMY
	delay 230
	fadedefaultbgm
	msgbox LRT_FM2 MSGBOX_DEFAULT
	closemessage
	release
	end

Pidgey_NPC::
	lock
	faceplayer
	msgbox Pidgey_NPCText MSGBOX_ONELINE
	closemessage
	release
	end

Pidgey_NPCText:
    .string "Hello my name is Pidgey.\p"
    .string "I'm not actually a Pidgey but that's\p"
    .string "what most people on Discord call me!\p"
    .string "I added this NPC as an easter egg\p"
    .string "without the permission of Ryuhouji!\p"
    .string "Anyways I wanted to know if this\p"
    .string "would slip under his radar or not.\p"
    .string "If you see this message chances are\p"
    .string "that it did.$"

LRT_FM1:
    .string "Man: It's hard to take a nap out\n"
    .string "here. I keep hearing the Pokémon\p"
    .string "that professor has preserved south\n"
    .string "of town making noises all the time\l"
    .string "Listen!$"
	
LRT_FM2:
    .string "Did you hear them? It's distracting\n"
    .string "right? Well anyways, bye!$"

@HAREM EVENT=======================================================================================
Ryu_HaremEvent::
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, LRT_Cam1
	waitmovement OBJ_EVENT_ID_CAMERA
	goto_if_set FLAG_RYU_HAREM_EVENT_COMPLETED, ryu_end
	lockall
	checkplayergender
	compare VAR_RESULT, FEMALE
	call_if_eq Ryu_HaremEventMale
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq Ryu_HaremEventFemale
	msgbox LRT_Harem_Outro
	closemessage
	additem ITEM_SHINY_CHARM
	closemessage
	delay 60
	fadescreen FADE_TO_BLACK
	@drawfullscreenimage SCENEBGHAREM
	setflag FLAG_RYU_HAREM_EVENT_COMPLETED
	setflag FLAG_RYU_HIDE_HAREM_EVENT_NPCS
	setflag FLAG_RYU_HIDE_HAREM_EVENT_BRENDAN
	setflag FLAG_RYU_HIDE_HAREM_EVENT_DAWN
	removeobject 4
	removeobject 6
	removeobject 8
	removeobject 9
	removeobject 12
	@clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	msgbox LRT_HAREM_END_RIVALMSG
	closemessage
	applymovement 7, RivalToLab
	applymovement 10, RivalToLab
	waitmovement 7
	waitmovement 10
	removeobject 7
	removeobject 10
	setvar VAR_RYU_PARTNER_COUNT, 10 @Finished harem event.
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
	special SpawnCameraObject
	release
	end
	
LRT_HAREM_END_RIVALMSG:
	.string "{RIVAL}:{COLOR LIGHT_RED}{SHADOW RED} Don't forget to take one\n"
	.string "of us with you to battle from\l"
	.string "time to time!$"

LRT_HAREM_INTRO:
    .string "{RIVAL}:{COLOR LIGHT_RED}{SHADOW RED} We all love you, and in\n"
    .string "return, you've shown us all love.\p"
    .string "We got together to get you a gift.$"
	
LRT_Harem_Outro:
    .string "{RIVAL}:{COLOR LIGHT_RED}{SHADOW RED} It's a Shiny Charm.$"
	
LRT_HAREM_INTRO_Shelly:
    .string "Shelly:{COLOR LIGHT_RED}{SHADOW RED} It's an incredibly rare\n"
    .string "artifact imported from Kalos.$"
	
LRT_HAREM_INTRO_Lanette:
    .string "Lanette:{COLOR LIGHT_RED}{SHADOW RED} I researched for Hours to\n"
    .string "track it down!$"
	
LRT_HAREM_INTRO_Lana:
    .string "Lana:{COLOR LIGHT_RED}{SHADOW RED} I went to Kanto to fill out the\n"
    .string "paperwork to have it shipped here!$"

LRT_HAREM_INTRO_Nurse:
	.string "Joy:{COLOR LIGHT_RED}{SHADOW RED} I contacted my sisters in Kalos\nto speak with port authority and\lexpedite the export!$"

LRT_HAREM_INTRO_Rival:
    .string "{RIVAL}:{COLOR LIGHT_RED}{SHADOW RED} We hope you like it!\p"
    .string "You gave us your all, so we\n"
    .string "returned the favor!$"

LRT_Cam1:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LRT_Cam2:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
LRT_Harem_AlsoMinnie::
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq MinnieToMalePlayer
	checkplayergender
	compare VAR_RESULT, FEMALE
	call_if_eq MinnieToFemalePlayer
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	playse SE_PIN
	msgbox AlsoMinnieMsg
	closemessage
	goto_if_unset FLAG_RYU_MINNIE_GAME_CLEAR, ryu_return
	applymovement 4, MinnieDiag1
	waitmovement 4
	playse SE_W204
	applymovement 4, Common_Movement_HeartEmote
	waitmovement 4
	msgbox MinnieHugsPlayer
	closemessage
	applymovement 4, MinnieDiagFromPlayer
	waitmovement 4
	playse SE_PIN
	applymovement 6, Common_Movement_ExclamationMark
	applymovement 8, Common_Movement_ExclamationMark
	applymovement 9, Common_Movement_ExclamationMark
	applymovement 10, Common_Movement_ExclamationMark
	applymovement 12, Common_Movement_ExclamationMark
	applymovement 7, Common_Movement_ExclamationMark
	waitmovement 7
	msgbox AlsoChampionMinnieMsg
	closemessage
	return

MinnieToMalePlayer::
	applymovement 4, MinnieToMalePlayerMV
	waitmovement 4
	return

MinnieToMalePlayerMV:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_diag_southeast
	face_down
	step_end

MinnieToFemalePlayer::
	applymovement 4, MinnieToFemalePlayerMV
	waitmovement 4
	return

MinnieToFemalePlayerMV:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_diag_southeast
	face_down
	step_end

MinnieDiagFromPlayer:
	walk_diag_northwest
	face_down
	step_end

MinnieDiag1:
	walk_diag_southeast
	face_up
	step_end

AlsoMinnieMsg:
    .string "Minnie: {COLOR LIGHT_RED}{SHADOW RED}Hey! don't forget about me!\p"
    .string "You didn't treat me like a little\n"
	.string "kid, and took me with you on your\l"
	.string "adventures!\p"
	.string "I had a lot of fun!$"

AlsoChampionMinnieMsg:
	.string "Minnie: {COLOR LIGHT_RED}{SHADOW RED}We even beat the big boss\n"
	.string "together!\p"
	.string "I'll never forget that!\p"
	.string "I wish I could stay with you\n"
	.string "like the others, but, It's okay!\p"
	.string "When I get older, we can do\n"
	.string "even more!$"

MinnieHugsPlayer:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Minnie suddenly jumps on you\n"
	.string " and gives a big bear hug.)$"
	
MinnieToGroup:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_diag_southeast
	face_right
	emote_exclamation_mark
	step_end
	
RivalToLab:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Ryu_HaremEventMale::
	msgbox LRT_HAREM_INTRO
	closemessage
	applymovement 9, ShellyToDawn
	waitmovement 9
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox LRT_HAREM_INTRO_Shelly
	closemessage
	applymovement 8, LanaToDawn
	waitmovement 8
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox LRT_HAREM_INTRO_Lana
	closemessage
	applymovement 6, LanetteToDawn
	waitmovement 6
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox LRT_HAREM_INTRO_Lanette
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 12, NurseToDawn
	waitmovement 12
	applymovement OBJ_EVENT_ID_CAMERA, LRT_Cam2
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	applymovement 10, Common_Movement_FaceRight
	msgbox LRT_HAREM_INTRO_Nurse
	closemessage
	call_if_set FLAG_RYU_RECRUITED_MINNIE, LRT_Harem_AlsoMinnie
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 10, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox LRT_HAREM_INTRO_Rival
	closemessage
	return
	
Ryu_HaremEventFemale::
	msgbox LRT_HAREM_INTRO
	closemessage
	applymovement 6, LanetteToBrendan
	waitmovement 6
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox LRT_HAREM_INTRO_Lanette
	closemessage
	applymovement 12, NurseToBrendan
	waitmovement 12
	applymovement 10, Common_Movement_FaceLeft
	msgbox LRT_HAREM_INTRO_Nurse
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 8, LanaToBrendan
	waitmovement 8
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox LRT_HAREM_INTRO_Lana
	closemessage
	applymovement 9, ShellyToBrendan
	waitmovement 9
	applymovement OBJ_EVENT_ID_CAMERA, LRT_Cam2
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox LRT_HAREM_INTRO_Shelly
	closemessage
	call_if_set FLAG_RYU_RECRUITED_MINNIE, LRT_Harem_AlsoMinnie
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement 7, Common_Movement_FaceLeft
	waitmovement 7
	msgbox LRT_HAREM_INTRO_Rival
	return
	
LanetteToDawn:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	face_left
	step_end

NurseToDawn:
	walk_up
	walk_up
	face_left
	step_end

LanaToDawn:
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_right
	face_down
	step_end
	
ShellyToDawn:
	walk_up
	walk_up
	face_up
	step_end
	
LanetteToBrendan:
	walk_up
	walk_up
	walk_up
	face_right
	step_end

NurseToBrendan:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	face_right
	step_end

LanaToBrendan:
	walk_up
	walk_up
	face_up
	step_end
	
ShellyToBrendan:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	face_down
	step_end


	

	
	
	
	
	
	
	
	
	
	
	
