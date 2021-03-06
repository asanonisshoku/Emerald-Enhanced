FortreeCity_Gym_MapScripts:: @ 82165AB
	.byte 0


FortreeCity_Gym_EventScript_Winona:: @ 82165C8
    lock
    faceplayer
	setflag FLAG_RYU_BOSS_SCALE
    special checkbadgecount
    switch VAR_RESULT
	case 0, WINONA1
	case 1, WINONA1
	case 2, WINONA1
	case 3, WINONA2
	case 4, WINONA2
	case 5, WINONA3
	case 6, WINONA3
	case 7, WINONA4
	case 8, WINONA4
	end

FortreeCity_Gym_EventScript_WinonaDefeated:: @ 82165FD
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	release
	end

FG_Reset::
	setvar VAR_TEMP_8, 6
	special checkbadgecount
	compare VAR_RESULT, 8
	call_if_eq RyuTier8GymMegaStoneReward
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	cleartrainerflag TRAINER_WINONA_1
	cleartrainerflag TRAINER_WINONA_2
	cleartrainerflag TRAINER_WINONA_3
	cleartrainerflag TRAINER_WINONA_4
	clearflag FLAG_RYU_BOSS_SCALE
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	goto_if_set FLAG_RYU_HARDCORE_MODE, RyuScripts_HardcoreGymReward
	call_if_set FLAG_RYU_NUZLOCKEMODE, RyuHealedGym
	call_if_unset FLAG_RYU_GYM6HANDOUT, RyuGymItemReward6
	call Ryu_CheckForPartnerReward
	release
	end

WINONA1::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreBattle, FortreeCity_Gym_Text_WinonaDefeat, FG_Reset
	release
	end

WINONA2::
	trainerbattle_single TRAINER_WINONA_2, FortreeCity_Gym_Text_WinonaPreBattle, FortreeCity_Gym_Text_WinonaDefeat, FG_Reset
	release
	end

WINONA3::
	trainerbattle_single TRAINER_WINONA_3, FortreeCity_Gym_Text_WinonaPreBattle, FortreeCity_Gym_Text_WinonaDefeat, FG_Reset
	release
	end

WINONA4::
	goto_if_set FLAG_RYU_HAS_FOLLOWER, FG_FollowerMatch
    goto_if_set FLAG_RYU_DS_HAS_PARTNER FG_PartnerQuery
	trainerbattle_single TRAINER_WINONA_4, FortreeCity_Gym_Text_WinonaPreBattle, FortreeCity_Gym_Text_WinonaDefeat, FG_Reset
	release
	end

FG_PartnerQuery::
    msgbox RyuPartnerMultiText MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq FG_RelDialog
	goto FG_NoRelGymBattle
	return
	
	
FG_RelDialog::
	call RyuPartnerBattleMultichoice
	compare VAR_0x8008, TRAINER_REL_SHELLY
	goto_if_eq FG_GymBattleIntroShelly
	compare VAR_0x8008, TRAINER_REL_DAWN
	goto_if_eq FG_GymBattleIntroDawn
	compare VAR_0x8008, TRAINER_REL_BRENDAN
	goto_if_eq FG_GymBattleIntroBrendan
	compare VAR_0x8008, TRAINER_REL_LANA
	goto_if_eq FG_GymBattleIntroLana
	compare VAR_0x8008, TRAINER_REL_LANETTE
	goto_if_eq FG_GymBattleIntroLanette
	compare VAR_0x8008, TRAINER_REL_COURTNEY_2
	goto_if_eq FG_GymBattleIntroCourtney
	compare VAR_0x8008, TRAINER_REL_NURSE
	goto_if_eq FG_GymBattleIntroJoy
	goto FG_NoRelGymBattle
	
FG_NoRelGymBattle::
	trainerbattle_single TRAINER_WINONA_4, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_Text_WinonaPostBattle, FG_Reset
	release
	end

FG_FollowerMatch::
	msgbox FortreeCity_Gym_Text_WinonaDefeat
	closemessage
	call RyuFollowerAllySelector
	choose_mons
	compare VAR_RESULT, FALSE
	goto_if_eq FG_ChooseValidMons
	multi_2_vs_1 TRAINER_WINONA_4, FortreeCity_Gym_Text_WinonaPostBattle, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	goto FG_Reset
	end
	
FG_NoRelationship1::
	msgbox Ryu_NOREL MSGBOX_DEFAULT
	closemessage
	goto FG_RelDialog
	
FG_GymBattleIntroShelly::
	msgbox Ryu_PlayerCalledShelly MSGBOX_DEFAULT
	closemessage
	delay 30
	goto_if_unset FLAG_RYU_DS_SHELLY_PARTNERS, FG_NoRelationship1
	addobject 11
	playse SE_DOOR
	applymovement 11, FG_PartnerEnter
	waitmovement 0
	msgbox FG_SHELLY_INTRO MSGBOX_DEFAULT
	goto FG_AltGymBattle
	
FG_GymBattleIntroDawn::
	goto_if_unset FLAG_RYU_DS_DAWN_PARTNERS, FG_NoRelationship1
	msgbox Ryu_PlayerCalledDawn MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 9
	playse SE_DOOR
	applymovement 9, FG_PartnerEnter
	waitmovement 0
	msgbox FG_DAWN_INTRO MSGBOX_DEFAULT
	goto FG_AltGymBattle
	
FG_GymBattleIntroBrendan::
	goto_if_unset FLAG_RYU_DS_BRENDAN_PARTNERS, FG_NoRelationship1
	msgbox Ryu_PlayerCalledBrendan MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 10
	playse SE_DOOR
	applymovement 10, FG_PartnerEnter
	waitmovement 0
	msgbox FG_BRENDAN_INTRO MSGBOX_DEFAULT
	goto FG_AltGymBattle
	
FG_GymBattleIntroLana::
	goto_if_unset FLAG_RYU_DS_LEAF_PARTNERS, FG_NoRelationship1
	msgbox Ryu_PlayerCalledLana MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 12
	playse SE_DOOR
	applymovement 12, FG_PartnerEnter
	waitmovement 12
	msgbox FG_LEAF_INTRO MSGBOX_DEFAULT
	goto FG_AltGymBattle
	
FG_GymBattleIntroLanette::
	goto_if_unset FLAG_RYU_DS_LANETTE_PARTNERS, FG_NoRelationship1
	msgbox Ryu_PlayerCalledLanette MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 13
	playse SE_DOOR
	applymovement 13, FG_PartnerEnter
	waitmovement 13
	msgbox FG_LANETTE_INTRO MSGBOX_DEFAULT
	goto FG_AltGymBattle

FG_GymBattleIntroCourtney::
	goto_if_unset FLAG_RYU_DS_COURTNEY_PARTNERS, FG_NoRelationship1
	msgbox Ryu_PlayerCalledCourtney MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 14
	playse SE_DOOR
	applymovement 14, FG_PartnerEnter
	waitmovement 0
	msgbox FG_COURTNEY_INTRO MSGBOX_DEFAULT
	goto FG_AltGymBattle

FG_GymBattleIntroJoy::
	goto_if_unset FLAG_RYU_DS_JOY_PARTNERS, FG_NoRelationship1
	msgbox Ryu_PlayerCalledJoy MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 15
	playse SE_DOOR
	applymovement 15, FG_PartnerEnter
	waitmovement 0
	msgbox FG_JOY_INTRO MSGBOX_DEFAULT
	goto FG_AltGymBattle
	
FG_AltGymBattle::
	msgbox FG_PreBattleText MSGBOX_DEFAULT
	choose_mons
	compare VAR_RESULT, FALSE
	goto_if_eq FG_ChooseValidMons
	multi_2_vs_1 TRAINER_WINONA_4, FG_DefeatText, VAR_0x8008, VAR_0x8009
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	goto FG_GymBattleEnd

FG_ChooseValidMons::
	msgbox EGC_NeedToChoose
	closemessage
	goto_if_set FLAG_RYU_HAS_FOLLOWER, FG_FollowerMatch
	goto FG_AltGymBattle
	
FG_GymBattleEnd::
	compare VAR_0x8008, TRAINER_REL_DAWN
	goto_if_eq FG_GymBattleEndDawn
	compare VAR_0x8008, TRAINER_REL_SHELLY
	goto_if_eq FG_GymBattleEndShelly
	compare VAR_0x8008, TRAINER_REL_BRENDAN
	goto_if_eq FG_GymBattleEndBrendan
	compare VAR_0x8008, TRAINER_REL_LANA
	goto_if_eq FG_GymBattleEndLeaf
	compare VAR_0x8008, TRAINER_REL_LANETTE
	goto_if_eq FG_GymBattleEndLanette
	compare VAR_0x8008, TRAINER_REL_COURTNEY_2
	goto_if_eq FG_GymBattleEndCourtney
	compare VAR_0x8008, TRAINER_REL_NURSE
	goto_if_eq FG_GymBattleEndJoy
	release
	end
	
FG_GymBattleEndShelly::
	msgbox FG_ShellyGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 11, FG_PartnerExit
	waitmovement 0
	playse SE_DOOR
	removeobject 11
	goto FG_Reset
	release
	end
	
FG_GymBattleEndDawn::
	msgbox FG_DawnGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 9, FG_PartnerExit
	waitmovement 0
	playse SE_DOOR
	removeobject 9
	goto FG_Reset
	release
	end
	
FG_GymBattleEndBrendan::
	msgbox FG_BrendanGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 10, FG_PartnerExit
	waitmovement 0
	playse SE_DOOR
	removeobject 10
	goto FG_Reset
	release
	end
	
FG_GymBattleEndLeaf::
	msgbox FG_LeafGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 12, FG_PartnerExit
	waitmovement 12
	playse SE_DOOR
	removeobject 12
	goto FG_Reset
	release
	end
	
FG_GymBattleEndLanette::
	msgbox FG_LanetteGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 13, FG_PartnerExit
	waitmovement 13
	playse SE_DOOR
	removeobject 13
	goto FG_Reset
	release
	end

FG_GymBattleEndCourtney::
	msgbox FG_CourtneyGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 14, FG_PartnerExit
	waitmovement 14
	playse SE_DOOR
	removeobject 14
	goto FG_Reset
	release
	end

FG_GymBattleEndJoy::
	msgbox DFG_JoyGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 15, DFG_PartnerExit
	waitmovement 15
	playse SE_DOOR
	removeobject 15
	goto DFG_Reset
	release
	end
	
FG_SHELLY_INTRO:
    .string "{COLOR LIGHT_RED}{SHADOW RED}This birdbrain should be\n"
    .string "a piece of cake. Let's go!$"
	
FG_DAWN_INTRO:
    .string "{COLOR LIGHT_RED}{SHADOW RED}She has some really cute\n"
    .string "Pokémon. It's fun to battle her!$"
	
FG_BRENDAN_INTRO:
    .string "{COLOR LIGHT_RED}{SHADOW RED}I don't have the greatest\n"
    .string "type matchups for this battle, but\l"
    .string "we should be fine. $"
	
FG_LEAF_INTRO:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Huh, I've never seen a flying\n"
    .string "type gym Leader before. This should\l"
    .string "be interesting!$"
	
FG_LANETTE_INTRO:
    .string "{COLOR LIGHT_RED}{SHADOW RED}This is certainly my\nwheelhouse. This'll be easy!$"

FG_COURTNEY_INTRO:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Canines have been man's hunting\ncompanions since the beginning of\ltime.\pThey're natural predators to flying\ntypes.$"

FG_JOY_INTRO:
	.string "{COLOR LIGHT_RED}{SHADOW RED}I always loved Winona's style.\nShe's very gentle!$"

FG_PreBattleText:
    .string "Winona: Oh, hi! I remember you. \n"
    .string "Looks like you brought a friend!\p"
    .string "Let us once again marvel at the\n"
    .string "grace of my flying types!$"
	
FG_DefeatText:
    .string "It seems you two are even more\n"
    .string "graceful when working together!\p"
    .string "It's a wonderful sight!$"
	
FG_ShellyGymBattleComplete:
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (Shelly blushes and turns away\n"
    .string " without a word)$"
	
FG_LeafGymBattleComplete:
    .string "{COLOR LIGHT_RED}{SHADOW RED}It must be because of how weak\n"
    .string "they are. Oh well, bye, {PLAYER}!$"
	
FG_DawnGymBattleComplete:
    .string "{COLOR LIGHT_RED}{SHADOW RED}That was really fun! Maybe\n"
    .string "I should go get an Altaria, they're\l"
    .string "so cuuuuute!$"
	
FG_BrendanGymBattleComplete:
    .string "{COLOR LIGHT_RED}{SHADOW RED}It worked out in the end.\n"
    .string "Nice seeing you again, Winona!\l"
    .string "I'll catch you guys later!$"

FG_CourtneyGymBattleComplete:
	.string "{COLOR LIGHT_RED}{SHADOW RED}It's a shame I couldn't take one\nhome to eat.$"

FG_LanetteGymBattleComplete:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(Lanette yawns)\p{COLOR LIGHT_RED}{SHADOW RED}Oh! the battle's over.$"

FG_JoyGymBattleComplete:
	.string "{COLOR LIGHT_RED}{SHADOW RED}I... feel a little bad...$"

FG_PartnerEnter:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_up
	step_end

FG_PartnerExit:
	walk_in_place_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

FortreeCity_Gym_EventScript_GiveAerialAce2:: @ 8216646
	additem ITEM_TM40
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM40
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce:: @ 821666A
	additem ITEM_TM40
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM40
	return

FortreeCity_Gym_EventScript_WinonaRematch:: @ 821668D
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared:: @ 82166A8
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredPreBattle, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo:: @ 82166BF
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoPreBattle, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint:: @ 82166D6
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintPreBattle, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley:: @ 82166ED
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyPreBattle, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto:: @ 8216704
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoPreBattle, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius:: @ 821671B
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusPreBattle, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide:: @ 8216732
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory:: @ 8216747
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue:: @ 8216751
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue:: @ 8216761
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified:: @ 8216771
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue:: @ 821677B
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice: @ 8216785
	.string "Yo, how's it going, Champion-\n"
	.string "bound {PLAYER}?\p"
	.string "Fortree Gym Leader Winona is\n"
	.string "a master of FLYING-type Pokémon.\p"
	.string "She's waiting at the back of this Gym,\n"
	.string "behind the rotating doors.\p"
	.string "She's waiting for new challengers\n"
	.string "who are trying to take wing!\p"
	.string "Okay, go for it!$"

FortreeCity_Gym_Text_GymGuidePostVictory: @ 821687D
	.string "You did it!\n"
	.string "You've achieved liftoff!$"

FortreeCity_Gym_Text_JaredPreBattle: @ 82168A2
	.string "Behold the elegant battle style of\n"
	.string "Bird Pokémon!$"

FortreeCity_Gym_Text_JaredDefeat: @ 82168D3
	.string "You…\n"
	.string "You're strong…$"

FortreeCity_Gym_Text_JaredPostBattle: @ 82168E7
	.string "A Trainer has to be smart to keep\n"
	.string "up with unexpected turns of events.\p"
	.string "Do you have the smarts to get to\n"
	.string "our Leader?$"

FortreeCity_Gym_Text_EdwardoPreBattle: @ 821695A
	.string "The lovers of Bird Pokémon aspire\n"
	.string "to join this Gym.\p"
	.string "As a member of the Fortree Gym,\n"
	.string "I'm not allowed to lose!$"

FortreeCity_Gym_Text_EdwardoDefeat: @ 82169C7
	.string "It was too much of a load for me\n"
	.string "to bear…$"

FortreeCity_Gym_Text_EdwardoPostBattle: @ 82169F1
	.string "The world is huge, and there are\n"
	.string "countless tough Trainers.\p"
	.string "I'm going to keep training and make\n"
	.string "myself even stronger.$"

FortreeCity_Gym_Text_FlintPreBattle: @ 8216A66
	.string "There's no need for Winona, our Gym\n"
	.string "Leader, to deal with you!\p"
	.string "I'm plenty good enough for you!$"

FortreeCity_Gym_Text_FlintDefeat: @ 8216AC4
	.string "Winona, I…\n"
	.string "I lost!$"

FortreeCity_Gym_Text_FlintPostBattle: @ 8216AD7
	.string "Winona is cute and she's strong.\n"
	.string "She's the ultimate Leader!\p"
	.string "Blush…$"

FortreeCity_Gym_Text_AshleyPreBattle: @ 8216B1A
	.string "Winona taught me personally!\n"
	.string "You can't beat me easily!$"

FortreeCity_Gym_Text_AshleyDefeat: @ 8216B51
	.string "I was beaten…$"

FortreeCity_Gym_Text_AshleyPostBattle: @ 8216B5F
	.string "Thanks to Winona, the people of\n"
	.string "Fortree can live without fear.$"

FortreeCity_Gym_Text_HumbertoPreBattle: @ 8216B9E
	.string "When Winona takes to battle, her face\n"
	.string "shines with beautiful determination…\p"
	.string "I'm not letting you witness that\n"
	.string "lovely sight!$"

FortreeCity_Gym_Text_HumbertoDefeat: @ 8216C18
	.string "Urk!\n"
	.string "I couldn't stop you.$"

FortreeCity_Gym_Text_HumbertoPostBattle: @ 8216C32
	.string "You'd better watch it!\n"
	.string "Don't get distracted staring at Winona\l"
	.string "or you'll go crashing down in a heap!$"

FortreeCity_Gym_Text_DariusPreBattle: @ 8216C96
	.string "You'd better know that there are all\n"
	.string "sorts of FLYING-type Pokémon.\p"
	.string "You do know that, right?$"

FortreeCity_Gym_Text_DariusDefeat: @ 8216CF2
	.string "You seem to know your stuff!$"

FortreeCity_Gym_Text_DariusPostBattle: @ 8216D0F
	.string "Sure, you beat me all right.\n"
	.string "But you'd better watch it! Our Leader\l"
	.string "Winona's Pokémon are all business.$"

FortreeCity_Gym_Text_WinonaPreBattle: @ 8216D75
	.string "I am Winona. I am the Leader of\n"
	.string "the Fortree Pokémon Gym.\p"
	.string "I have become one with Bird Pokémon\n"
	.string "and have soared the skies…\p"
	.string "However grueling the battle, we have\n"
	.string "triumphed with grace…\p"
	.string "Witness the elegant choreography\n"
	.string "of Bird Pokémon and I!$"

FortreeCity_Gym_Text_WinonaDefeat: @ 8216E60
	.string "Never before have I seen a Trainer\n"
	.string "command Pokémon with more grace\l"
	.string "than I…$"

FortreeCity_Gym_Text_ReceivedFeatherBadge: @ 8216EEC
	.string "{PLAYER} received the FEATHER badge\n"
	.string "from Winona.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis: @ 8216F17
	.string "With the Feather badge, all Pokémon up\n"
	.string "to LV 70, even those received through\l"
	.string "trades, will obey your every command.\p"
	.string "You will also be able to use\n"
	.string "the HM move Fly outside of battle.\p"
	.string "And this…\n"
	.string "This is a gift from me.$"

FortreeCity_Gym_Text_ExplainAerialAce: @ 8216FEC
	.string "TM40 contains Aerial Ace.\p"
	.string "Its speed…\n"
	.string "No Pokémon should be able to avoid it.\p"
	.string "… … … … … …$"

FortreeCity_Gym_Text_RegisteredWinona: @ 8217044
	.string "Registered Gym Leader Winona\n"
	.string "in the Pokénav.$"

FortreeCity_Gym_Text_WinonaPostBattle: @ 8217071
	.string "Though I fell to you, I will remain\n"
	.string "devoted to Bird Pokémon.$"

FortreeCity_Gym_Text_GymStatue: @ 82170AE
	.string "Fortree City Pokémon Gym$"

FortreeCity_Gym_Text_GymStatueCertified: @ 82170C7
	.string "Fortree City Pokémon Gym\p"
	.string "Winona's Certified Trainers:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch: @ 8217100
	.string "Winona: We humans can never escape\n"
	.string "gravity's pull on the ground.\p"
	.string "But by striving for excellence,\n"
	.string "we have the power to soar!\p"
	.string "You have scaled the pinnacle as\n"
	.string "the reigning Champion.\p"
	.string "Please, allow me to see your power\n"
	.string "at full flight!$"

FortreeCity_Gym_Text_WinonaRematchDefeat: @ 82171E6
	.string "I failed to reach your height again…$"

FortreeCity_Gym_Text_WinonaPostRematch: @ 821720B
	.string "Winona: Even though I have lost,\n"
	.string "the wings of my heart remain unbroken.\p"
	.string "I can rise and soar again and\n"
	.string "yet again.\p"
	.string "I am convinced of it!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons: @ 8217292
	.string "Winona: We humans can never escape\n"
	.string "gravity's pull on the ground.\p"
	.string "But by striving for excellence,\n"
	.string "we have the power to soar!\p"
	.string "You have scaled the pinnacle as\n"
	.string "the reigning Champion.\p"
	.string "Please, allow me to see your power\n"
	.string "at full flight!\p"
	.string "Oh, no… Do you have but one\n"
	.string "Pokémon with you?\p"
	.string "Please return with two Pokémon\n"
	.string "at the very least.$"
