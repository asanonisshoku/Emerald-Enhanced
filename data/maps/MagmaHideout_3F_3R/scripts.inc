MagmaHideout_3F_3R_MapScripts:: @ 823ACFF
	.byte 0
	
@===============================================================Aqua grunt fights here for magma event to keep organized

MH_AquaGrunt1::@F
	goto_if_set (TRAINER_FLAGS_START + TRAINER_GRUNT_SEAFLOOR_CAVERN_4), MH_AquaGruntDefeated
	multi_fixed_2_vs_1 TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Defeat, TRAINER_REL_COURTNEY_1, TRAINER_BACK_PIC_COURTNEY
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	settrainerflag TRAINER_GRUNT_SEAFLOOR_CAVERN_4
	goto MH_CheckGruntsDefeated
	release
	end

MH_AquaGrunt2::@M
	goto_if_set (TRAINER_FLAGS_START + TRAINER_GRUNT_SEAFLOOR_CAVERN_2), MH_AquaGruntDefeated
	multi_fixed_2_vs_1 TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Defeat, TRAINER_REL_COURTNEY_1, TRAINER_BACK_PIC_COURTNEY
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	settrainerflag TRAINER_GRUNT_SEAFLOOR_CAVERN_2
	goto MH_CheckGruntsDefeated
	release
	end
	
MH_AquaGrunt3::@M
	goto_if_set (TRAINER_FLAGS_START + TRAINER_GRUNT_SEAFLOOR_CAVERN_1), MH_AquaGruntDefeated
	multi_fixed_2_vs_1 TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Defeat, TRAINER_REL_COURTNEY_1, TRAINER_BACK_PIC_COURTNEY
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	settrainerflag TRAINER_GRUNT_SEAFLOOR_CAVERN_1
	goto MH_CheckGruntsDefeated
	release
	end
	
MH_AquaGrunt4::@F
	goto_if_set (TRAINER_FLAGS_START + TRAINER_GRUNT_25), MH_AquaGruntDefeated
	multi_fixed_2_vs_1 TRAINER_GRUNT_25, AquaHideout_B1F_Text_Grunt7Defeat, TRAINER_REL_COURTNEY_1, TRAINER_BACK_PIC_COURTNEY
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	settrainerflag TRAINER_GRUNT_25
	goto MH_CheckGruntsDefeated
	release
	end
	
MH_AquaGrunt5::@M
	goto_if_set (TRAINER_FLAGS_START + TRAINER_GRUNT_SEAFLOOR_CAVERN_3), MH_AquaGruntDefeated
	multi_fixed_2_vs_1 TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Defeat, TRAINER_REL_COURTNEY_1, TRAINER_BACK_PIC_COURTNEY
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	settrainerflag TRAINER_GRUNT_SEAFLOOR_CAVERN_3
	goto MH_CheckGruntsDefeated
	release
	end
	
MH_AquaGrunt6::@m
	goto_if_set (TRAINER_FLAGS_START + TRAINER_GRUNT_AQUA_HIDEOUT_3), MH_AquaGruntDefeated
	multi_fixed_2_vs_1 TRAINER_GRUNT_AQUA_HIDEOUT_3, AquaHideout_B1F_Text_Grunt3Defeat, TRAINER_REL_COURTNEY_1, TRAINER_BACK_PIC_COURTNEY
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	settrainerflag TRAINER_GRUNT_AQUA_HIDEOUT_3
	goto MH_CheckGruntsDefeated
	release
	end
	
MH_AquaGrunt7::@F
	goto_if_set (TRAINER_FLAGS_START + TRAINER_GRUNT_21), MH_AquaGruntDefeated
	multi_fixed_2_vs_1 TRAINER_GRUNT_21, AquaHideout_B1F_Text_Grunt5Defeat, TRAINER_REL_COURTNEY_1, TRAINER_BACK_PIC_COURTNEY
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	settrainerflag TRAINER_GRUNT_21
	goto MH_CheckGruntsDefeated
	release
	end
	
MH_AquaGrunt8::@m
	goto_if_set (TRAINER_FLAGS_START + TRAINER_GRUNT_4), MH_AquaGruntDefeated
	multi_fixed_2_vs_1 TRAINER_GRUNT_4, AquaHideout_B2F_Text_Grunt4Defeat, TRAINER_REL_COURTNEY_1, TRAINER_BACK_PIC_COURTNEY
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	settrainerflag TRAINER_GRUNT_4
	goto MH_CheckGruntsDefeated
	release
	end
	
MH_AquaGrunt9::@m
	goto_if_set (TRAINER_FLAGS_START + TRAINER_GRUNT_26), MH_AquaGruntDefeated
	multi_fixed_2_vs_1 TRAINER_GRUNT_26, AquaHideout_B2F_Text_Grunt8Defeat, TRAINER_REL_COURTNEY_1, TRAINER_BACK_PIC_COURTNEY
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	settrainerflag TRAINER_GRUNT_26
	goto MH_CheckGruntsDefeated
	release
	end
	
MH_AquaGrunt10::@F
	goto_if_set (TRAINER_FLAGS_START + TRAINER_GRUNT_22), MH_AquaGruntDefeated
	multi_fixed_2_vs_1 TRAINER_GRUNT_22, AquaHideout_B2F_Text_Grunt6Defeat, TRAINER_REL_COURTNEY_1, TRAINER_BACK_PIC_COURTNEY
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Ryu_PlayerLostTheGame
	settrainerflag TRAINER_GRUNT_22
	goto MH_CheckGruntsDefeated
	release
	end

MH_AquaGruntDefeated::
	goto MH_CheckGruntsDefeated
	release
	end

MH_CheckGruntsDefeated::
	goto_if_unset (TRAINER_FLAGS_START + TRAINER_GRUNT_SEAFLOOR_CAVERN_4), MH_GruntsNotDefeated
	goto_if_unset (TRAINER_FLAGS_START + TRAINER_GRUNT_SEAFLOOR_CAVERN_2), MH_GruntsNotDefeated
	goto_if_unset (TRAINER_FLAGS_START + TRAINER_GRUNT_SEAFLOOR_CAVERN_1), MH_GruntsNotDefeated
	goto_if_unset (TRAINER_FLAGS_START + TRAINER_GRUNT_25), MH_GruntsNotDefeated
	goto_if_unset (TRAINER_FLAGS_START + TRAINER_GRUNT_SEAFLOOR_CAVERN_3), MH_GruntsNotDefeated
	goto_if_unset (TRAINER_FLAGS_START + TRAINER_GRUNT_AQUA_HIDEOUT_3), MH_GruntsNotDefeated
	goto_if_unset (TRAINER_FLAGS_START + TRAINER_GRUNT_21), MH_GruntsNotDefeated
	goto_if_unset (TRAINER_FLAGS_START + TRAINER_GRUNT_4), MH_GruntsNotDefeated
	goto_if_unset (TRAINER_FLAGS_START + TRAINER_GRUNT_26), MH_GruntsNotDefeated
	goto_if_unset (TRAINER_FLAGS_START + TRAINER_GRUNT_22), MH_GruntsNotDefeated
	goto MH_GruntsDefeated

MH_GruntsDefeated::
	setvar VAR_RYU_MAGMA, 320
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FacePlayer
	waitmovement OBJ_EVENT_ID_FOLLOWER
	msgbox MH_CortneyConfirmsDone
	closemessage
	setflag FLAG_RYU_AQUA_IN_MAGMA_HIDEOUT_GRUNTS
	release
	end

MH_GruntsNotDefeated::
	playse SE_BIDORO
	waitse
	release
	end
