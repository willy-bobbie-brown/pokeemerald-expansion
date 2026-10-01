LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_Gym_1F_OnFrame
	.byte 0

LavaridgeTown_Gym_1F_OnFrame:
	map_script_2 VAR_CONTEST_HALL_STATE, 2, LavaridgeTown_Gym_EventScript_CheckContestResult
	.2byte 0

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

LavaridgeTown_Gym_EventScript_CheckContestResult::
	lockall
	setvar VAR_CONTEST_HALL_STATE, 0
	compare VAR_0x8005, 3
	goto_if_ne LavaridgeTown_Gym_EventScript_LostContest
	setflag FLAG_WON_LAVARIDGE_CONTEST
	releaseall
	goto LavaridgeTown_Gym_EventScript_ReadyForLeader

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


LavaridgeTown_Gym_EventScript_ContestGatekeeper::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_EventScript_GymAlreadyCleared
	goto_if_set FLAG_WON_LAVARIDGE_CONTEST, LavaridgeTown_Gym_EventScript_ReadyForLeader
	msgbox LavaridgeTown_Gym_Text_MustWinContestFirst, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LavaridgeTown_Gym_EventScript_DeclineContest
	setvar VAR_CONTEST_RANK, CONTEST_RANK_NORMAL
	multichoice 15, 0, MULTI_CONTEST_TYPE, 1
	switch VAR_RESULT
	case 0, LavaridgeTown_Gym_EventScript_SetCoolContest
	case 1, LavaridgeTown_Gym_EventScript_SetBeautyContest
	case 2, LavaridgeTown_Gym_EventScript_SetCuteContest
	case 3, LavaridgeTown_Gym_EventScript_SetSmartContest
	case 4, LavaridgeTown_Gym_EventScript_SetToughContest
	case 5, LavaridgeTown_Gym_EventScript_DeclineContest
	release
	end

LavaridgeTown_Gym_EventScript_LostContest::
	msgbox LavaridgeTown_Gym_Text_LostContest, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_EventScript_GymAlreadyCleared::
	msgbox LavaridgeTown_Gym_Text_AlreadyBeatGym, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_EventScript_ReadyForLeader::
	msgbox LavaridgeTown_Gym_Text_YouEarnedYourShot, MSGBOX_DEFAULT
	clearflag FLAG_WON_LAVARIDGE_CONTEST
@	NEED TO SCRIPT WALKING ACTION FOR BATTLE // omitting next line for testing
    setvar VAR_LAST_TALKED, LOCALID_LAVARIDGE_GYM_LEADER
	goto LavaridgeTown_Gym_1F_EventScript_Flannery
	release
	end

LavaridgeTown_Gym_EventScript_DeclineContest::
	msgbox LavaridgeTown_Gym_Text_ComeBackWhenReady, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_EventScript_SetCoolContest::
	setvar VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_COOL
	goto LavaridgeTown_Gym_EventScript_ChooseContestMon

LavaridgeTown_Gym_EventScript_SetBeautyContest::
	setvar VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_BEAUTY
	goto LavaridgeTown_Gym_EventScript_ChooseContestMon

LavaridgeTown_Gym_EventScript_SetCuteContest::
	setvar VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_CUTE
	goto LavaridgeTown_Gym_EventScript_ChooseContestMon

LavaridgeTown_Gym_EventScript_SetSmartContest::
	setvar VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_SMART
	goto LavaridgeTown_Gym_EventScript_ChooseContestMon

LavaridgeTown_Gym_EventScript_SetToughContest::
	setvar VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_TOUGH
	goto LavaridgeTown_Gym_EventScript_ChooseContestMon

LavaridgeTown_Gym_EventScript_ChooseContestMon::
	msgbox LavaridgeTown_Gym_Text_EnterWhichPokemon, MSGBOX_DEFAULT
	choosecontestmon
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LavaridgeTown_Gym_EventScript_DeclineContest
	special TryEnterContestMon
	goto_if_eq VAR_RESULT, CANT_ENTER_CONTEST, LavaridgeTown_Gym_EventScript_DeclineContest
	goto_if_eq VAR_RESULT, CANT_ENTER_CONTEST_EGG, LavaridgeTown_Gym_EventScript_DeclineContest
	goto_if_eq VAR_RESULT, CANT_ENTER_CONTEST_FAINTED, LavaridgeTown_Gym_EventScript_DeclineContest
	msgbox LavaridgeTown_Gym_Text_GoodLuck, MSGBOX_DEFAULT
	closemessage
	releaseall
	setvar VAR_CONTEST_HALL_STATE, 1
	special SetContestTrainerGfxIds
	call LilycoveCity_ContestLobby_EventScript_SetPlayerGfx
	call LavaridgeTown_Gym_EventScript_WarpToContestHall
	waitstate
	end

LavaridgeTown_Gym_EventScript_WarpToContestHall::
	switch VAR_CONTEST_CATEGORY
	case CONTEST_CATEGORY_COOL, LavaridgeTown_Gym_EventScript_WarpCoolHall
	case CONTEST_CATEGORY_BEAUTY, LavaridgeTown_Gym_EventScript_WarpBeautyHall
	case CONTEST_CATEGORY_CUTE, LavaridgeTown_Gym_EventScript_WarpCuteHall
	case CONTEST_CATEGORY_SMART, LavaridgeTown_Gym_EventScript_WarpSmartHall
	case CONTEST_CATEGORY_TOUGH, LavaridgeTown_Gym_EventScript_WarpToughHall
	return

LavaridgeTown_Gym_EventScript_WarpCoolHall::
	warp MAP_LAVARIDGE_TOWN_GYM_CONTEST_HALL, 7, 5
	return

LavaridgeTown_Gym_EventScript_WarpBeautyHall::
	warp MAP_LAVARIDGE_TOWN_GYM_CONTEST_HALL, 7, 5
	return

LavaridgeTown_Gym_EventScript_WarpCuteHall::
	warp MAP_LAVARIDGE_TOWN_GYM_CONTEST_HALL, 7, 5
	return

LavaridgeTown_Gym_EventScript_WarpSmartHall::
	warp MAP_LAVARIDGE_TOWN_GYM_CONTEST_HALL, 7, 5
	return

LavaridgeTown_Gym_EventScript_WarpToughHall::
	warp MAP_LAVARIDGE_TOWN_GYM_CONTEST_HALL, 7, 5
	return

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
@	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

LavaridgeTown_Gym_Text_LostContest:
	.string "I'm so sorry, but you failed\n"
	.string "to impress our audience.\p"
	.string "Better luck next time!$"

LavaridgeTown_Gym_Text_GoodLuck:
	.string "Good luck!$"

LavaridgeTown_Gym_Text_EnterWhichPokemon:
	.string "Please select which POKéMON you\n"
	.string "would like to enter.$"

LavaridgeTown_Gym_Text_AlreadyBeatGym:
	.string "Congratulations on your triumphant\n"
	.string "victory over DOME ACE TUCKER.\p"
	.string "We hope to see you again soon!$"

LavaridgeTown_Gym_Text_YouEarnedYourShot:
	.string "Great job {PLAYER}!\n"
	.string "You have earned a chance to battle\l"
	.string "against our very own DOME ACE TUCKER.\p"
	.string "I hope you're ready.$"

LavaridgeTown_Gym_Text_MustWinContestFirst:
	.string "Hello!\n" 
	.string "Welcome to the BATTLE DOME.\p"
	.string "If you're wishing to challenge the\n"
	.string "leader of the facility,\l"
	.string "you must first prove yourself\l" 
	.string "in a POKéMON CONTEST.\p"
	.string "Would you like to register?$"

LavaridgeTown_Gym_Text_ComeBackWhenReady:
	.string "Let me know when you're ready.$"

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Welcome… No, wait.\p"
	.string "Puny TRAINER, how good to see you've\n"
	.string "made it here!\p"
	.string "I have been entrusted with the…\n"
	.string "No, wait.\p"
	.string "I am FLANNERY, and I'm the GYM\n"
	.string "LEADER here!\p"
	.string "Uh…\n"
	.string "Dare not underestimate me, though\l"
	.string "I have been LEADER only a short time!\p"
	.string "With skills inherited from my grand-\n"
	.string "father, I shall, uh…demonstrate the\l"
	.string "hot moves we have honed on this land!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "Oh…\n"
	.string "I guess I was trying too hard…\p"
	.string "I… I've only recently become\n"
	.string "a GYM LEADER.\p"
	.string "I tried too hard to be someone\n"
	.string "I'm not.\p"
	.string "I have to do things my natural way. If\n"
	.string "I don't, my POKéMON will be confused.\p"
	.string "Thanks for teaching me that.\n"
	.string "For that, you deserve this.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} received the HEAT BADGE\n"
	.string "from FLANNERY.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "If you have a HEAT BADGE, all POKéMON\n"
	.string "up to Level 50, even those you get in\l"
	.string "trades from other people, will obey\l"
	.string "you completely.\p"
	.string "And, it lets POKéMON use the HM move\n"
	.string "STRENGTH outside of battle.\p"
	.string "This is a token of my appreciation.\n"
	.string "Don't be shy about taking it!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "That TM50 contains OVERHEAT.\p"
	.string "That move inflicts serious damage on\n"
	.string "the opponent.\p"
	.string "But it also sharply cuts the SP. ATK\n"
	.string "of the POKéMON using it. It might not\l"
	.string "be suitable for longer battles.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "Registered GYM LEADER FLANNERY\n"
	.string "in the POKéNAV.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "Your power reminds me of someone…\p"
	.string "Oh! I know! You battle like NORMAN,\n"
	.string "the GYM LEADER of PETALBURG.$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "FLANNERY: Losing a battle isn't going\n"
	.string "to deflate me.\p"
	.string "I love POKéMON.\n"
	.string "I love to battle.\l"
	.string "And… I love this GYM!\p"
	.string "Let's exchange superhot moves\n"
	.string "in another battle!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "Whew!\n"
	.string "On the verge of eruption!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "FLANNERY: I lost the match,\n"
	.string "but I'm completely satisfied.\p"
	.string "It's not often I get to enjoy a battle\n"
	.string "this heated.\p"
	.string "Let's have another one like this\n"
	.string "again sometime!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "FLANNERY: Losing a battle isn't going\n"
	.string "to deflate me.\p"
	.string "I love POKéMON.\n"
	.string "I love to battle.\l"
	.string "And… I love this GYM!\p"
	.string "Let's exchange superhot moves\n"
	.string "in another battle!\p"
	.string "Oh, wait. Do you only have one POKéMON\n"
	.string "that can battle?\p"
	.string "I hate to say this, but when you come\n"
	.string "see me, bring at least two POKéMON.$"
