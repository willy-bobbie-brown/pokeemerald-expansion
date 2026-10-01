LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LavaridgeTown_Gym_1F_OnWarp
	.byte 0

LavaridgeTown_Gym_1F_OnFrame:
	map_script_2 VAR_CONTEST_HALL_STATE, 2, LavaridgeTown_Gym_EventScript_CheckContestResult
	.2byte 0

LavaridgeTown_Gym_1F_OnWarp:
	map_script_2 VAR_TEMP_1, 0, LavaridgeTown_Gym_Movement_FaceUp
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
	closemessage
	releaseall
	applymovement LOCALID_RECEPTIONIST, LavaridgeTown_Gym_Movement_ReceptionistStepBack
    waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Gym_Movement_WalkToDoorLeft
    waitmovement 0
    opendoor 4, 5
    waitdooranim
    applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Gym_Movement_WalkThroughDoor
    waitmovement 0
	call LavaridgeTown_Gym_EventScript_WarpToBattleHall
	waitstate
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
	goto LavaridgeTown_Gym_EventScript_ReceptionistDoorSequence

LavaridgeTown_Gym_EventScript_ReceptionistDoorSequence::
    closemessage
    releaseall
    applymovement LOCALID_RECEPTIONIST, LavaridgeTown_Gym_Movement_ReceptionistStepBack
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Gym_Movement_WalkToDoorRight
    waitmovement 0
    opendoor 12, 5
    waitdooranim
    applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Gym_Movement_WalkThroughDoor
    waitmovement 0
    setvar VAR_CONTEST_HALL_STATE, 1
	special SetContestTrainerGfxIds
	call LilycoveCity_ContestLobby_EventScript_SetPlayerGfx
	call LavaridgeTown_Gym_EventScript_WarpToContestHall
    waitstate
    end

LavaridgeTown_Gym_Movement_ReceptionistStepBack:
    face_down
    lock_facing_direction
    walk_up
	unlock_facing_direction
	face_right
	lock_facing_direction
    walk_left
    unlock_facing_direction
    step_end

LavaridgeTown_Gym_Movement_WalkToDoorRight:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

LavaridgeTown_Gym_Movement_WalkToDoorLeft:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Gym_Movement_WalkThroughDoor:
	walk_up
	step_end

LavaridgeTown_Gym_EventScript_WarpToBattleHall::
	warp MAP_LAVARIDGE_TOWN_GYM_B1F, 4, 9
	return

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

LavaridgeTown_Gym_Movement_FaceUp::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
    end

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

LavaridgeTown_Gym_Text_LostContest:
	.string "I'm so sorry, but you failed\n"
	.string "to impress our audience.\p"
	.string "Better luck next time!$"

LavaridgeTown_Gym_Text_GoodLuck:
	.string "Great, you are all registered\n"
	.string "for the POKéMON CONTEST!\p"
	.string "Please head through the door\n"
	.string "behind me on your right.\p"
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
	.string "Please head through the door\n"
	.string "behind me on your left.\p"
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