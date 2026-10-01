LavaridgeTown_Gym_Contest_Hall_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LavaridgeTown_Gym_Contest_Hall_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_Gym_Contest_Hall_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_Contest_Hall_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, LavaridgeTown_Gym_Contest_Hall_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, LavaridgeTown_Gym_Contest_Hall_OnReturn
	.byte 0

LavaridgeTown_Gym_Contest_Hall_OnWarp:
	map_script_2 VAR_CONTEST_HALL_STATE, 1, LavaridgeTown_Gym_Contest_Hall_EventScript_SetContestObjects
	.2byte 0

LavaridgeTown_Gym_Contest_Hall_OnFrame:
	map_script_2 VAR_CONTEST_HALL_STATE, 1, LavaridgeTown_Gym_Contest_Hall_EventScript_Contest
	.2byte 0

LavaridgeTown_Gym_Contest_Hall_OnTransition:
	call LavaridgeTown_Gym_Contest_Hall_EventScript_ReadyContestMusic
	setvar VAR_TEMP_0, 1
	call LavaridgeTown_Gym_Contest_Hall_EventScript_AddRandomAudienceMembers
	end

LavaridgeTown_Gym_Contest_Hall_OnResume:
	call_if_eq VAR_TEMP_9, 1, LavaridgeTown_Gym_Contest_Hall_EventScript_ReShowAudience
	end

LavaridgeTown_Gym_Contest_Hall_OnReturn:
	special LoadLinkContestPlayerPalettes
	end

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

LavaridgeTown_Gym_Contest_Hall_EventScript_SetContestObjects::
	special LoadLinkContestPlayerPalettes
	hideobjectat LOCALID_PLAYER, MAP_LITTLEROOT_TOWN
	call LavaridgeTown_Gym_Contest_Hall_EventScript_CreateAudience
	end

LavaridgeTown_Gym_Contest_Hall_EventScript_CreateAudience::
	call LavaridgeTown_Gym_Contest_Hall_EventScript_CreateMasterContestAudience
	return

@ 5 lines commented out because sprite overflow error
LavaridgeTown_Gym_Contest_Hall_EventScript_CreateMasterContestAudience::
	createvobject OBJ_EVENT_GFX_BEAUTY, 0, 2, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_MAN_5, 1, 2, 4, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_HIKER, 2, 2, 7, 3, DIR_EAST
@	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 3, 2, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_MANIAC, 4, 1, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_WOMAN_5, 6, 1, 5, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_WOMAN_4, 7, 1, 6, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 9, 1, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 10, 12, 3, 3, DIR_WEST
@	createvobject OBJ_EVENT_GFX_WOMAN_2, 11, 12, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WOMAN_3, 12, 12, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_BEAUTY, 13, 12, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_FISHERMAN, 14, 13, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F, 15, 13, 4, 3, DIR_WEST
@	createvobject OBJ_EVENT_GFX_MAN_4, 17, 13, 6, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 18, 13, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_DEVON_EMPLOYEE, 19, 13, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_POKEFAN_M, 20, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_CAMPER, 21, 6, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_MAN_3, 22, 7, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 24, 11, 2, 3, DIR_SOUTH
@	createvobject OBJ_EVENT_GFX_SAILOR, 25, 3, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 4, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 27, 5, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 28, 9, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 10, 9, 3, DIR_NORTH
@	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 30, 11, 9, 3, DIR_NORTH
	return

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

LavaridgeTown_Gym_Contest_Hall_EventScript_Contest::
	call ContestHall_EventScript_DoContest
	call LavaridgeTown_Gym_Contest_Hall_EventScript_ExitWarp
	end

LavaridgeTown_Gym_Contest_Hall_EventScript_ExitWarp::
	turnobject LOCALID_PLAYER, DIR_NORTH
	warp MAP_LAVARIDGE_TOWN_GYM_1F, 8, 10
	waitstate
	end

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

LavaridgeTown_Gym_Contest_Hall_EventScript_ReadyContestMusic::
	call ContestHall_EventScript_TryWaitForLink
	special GetContestMultiplayerId
	call_if_eq VAR_RESULT, 0, LavaridgeTown_Gym_Contest_Hall_EventScript_SaveContestMusicPlayer1
	call_if_eq VAR_RESULT, 1, LavaridgeTown_Gym_Contest_Hall_EventScript_SaveContestMusicPlayer2
	call_if_eq VAR_RESULT, 2, LavaridgeTown_Gym_Contest_Hall_EventScript_SaveContestMusicPlayer3
	call_if_eq VAR_RESULT, 3, LavaridgeTown_Gym_Contest_Hall_EventScript_SaveContestMusicPlayer4
	call_if_eq VAR_RESULT, 4, LavaridgeTown_Gym_Contest_Hall_EventScript_SaveContestMusic
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_SaveContestMusicPlayer1::
	savebgm MUS_LINK_CONTEST_P1
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_SaveContestMusicPlayer2::
	savebgm MUS_LINK_CONTEST_P2
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_SaveContestMusicPlayer3::
	savebgm MUS_LINK_CONTEST_P3
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_SaveContestMusicPlayer4::
	savebgm MUS_LINK_CONTEST_P4
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_SaveContestMusic::
	savebgm MUS_B_DOME
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_AddRandomAudienceMembers::
	call LavaridgeTown_Gym_Contest_Hall_EventScript_GetRandomAudienceGfxId
	call LavaridgeTown_Gym_Contest_Hall_EventScript_SetRandomAudienceGfx
	goto_if_lt VAR_TEMP_0, 8, LavaridgeTown_Gym_Contest_Hall_EventScript_AddRandomAudienceMembers
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_GetRandomAudienceGfxId::
	setvar VAR_RESULT, 32
	special GenerateContestRand
	addvar VAR_RESULT, 1
	switch VAR_RESULT
	case 1, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceNinjaBoy
	case 2, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceTwin
	case 3, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceBoy1
	case 4, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceGirl1
	case 5, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceGirl2
	case 6, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceLittleBoy
	case 7, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceGirl
	case 8, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceBoy3
	case 9, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceGirl3
	case 10, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceRichBoy
	case 11, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceFatMan
	case 12, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudiencePokefanF
	case 13, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceMan1
	case 14, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceWoman2
	case 15, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceExpertM
	case 16, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceExpertF
	case 17, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudiencePokefanM
	case 18, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceWoman4
	case 19, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceCook
	case 20, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceLass
	case 21, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceOldWoman
	case 22, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceCamper
	case 23, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudiencePicnicker
	case 24, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceMan3
	case 25, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceWoman5
	case 26, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceYoungster
	case 27, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceBugCatcher
	case 28, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudiencePsychicM
	case 29, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceSchoolKidM
	case 30, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceBlackBelt
	case 31, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceBeauty
	case 32, LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceScientist1
	end

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceNinjaBoy::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_NINJA_BOY
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceTwin::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_TWIN
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceBoy1::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BOY_1
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceGirl1::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_GIRL_1
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceGirl2::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_GIRL_2
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceLittleBoy::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_LITTLE_BOY
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceGirl::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_LITTLE_GIRL
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceBoy3::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BOY_3
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceGirl3::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_GIRL_3
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceRichBoy::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_RICH_BOY
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceFatMan::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_FAT_MAN
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudiencePokefanF::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_POKEFAN_F
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceMan1::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_MAN_1
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceWoman2::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_WOMAN_2
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceExpertM::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_EXPERT_M
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceExpertF::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_EXPERT_F
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudiencePokefanM::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_POKEFAN_M
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceWoman4::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_WOMAN_4
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceCook::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_COOK
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceLass::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_LASS
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceOldWoman::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_OLD_WOMAN
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceCamper::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_CAMPER
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudiencePicnicker::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_PICNICKER
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceMan3::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_MAN_3
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceWoman5::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_WOMAN_5
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceYoungster::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_YOUNGSTER
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceBugCatcher::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BUG_CATCHER
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudiencePsychicM::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_PSYCHIC_M
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceSchoolKidM::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_SCHOOL_KID_M
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceBlackBelt::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BLACK_BELT
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceBeauty::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BEAUTY
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_RandomAudienceScientist1::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_SCIENTIST_1
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_SetRandomAudienceGfx::
	switch VAR_TEMP_0
	case 1, LavaridgeTown_Gym_Contest_Hall_EventScript_SetRandomAudience1
	case 2, LavaridgeTown_Gym_Contest_Hall_EventScript_SetRandomAudience2
	case 3, LavaridgeTown_Gym_Contest_Hall_EventScript_SetRandomAudience3
	case 4, LavaridgeTown_Gym_Contest_Hall_EventScript_SetRandomAudience4
	case 5, LavaridgeTown_Gym_Contest_Hall_EventScript_SetRandomAudience5
	case 6, LavaridgeTown_Gym_Contest_Hall_EventScript_SetRandomAudience6
	case 7, LavaridgeTown_Gym_Contest_Hall_EventScript_SetRandomAudience7
	end

LavaridgeTown_Gym_Contest_Hall_EventScript_SetRandomAudience1::
	copyvar VAR_OBJ_GFX_ID_4, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_SetRandomAudience2::
	copyvar VAR_OBJ_GFX_ID_5, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_SetRandomAudience3::
	copyvar VAR_OBJ_GFX_ID_6, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_SetRandomAudience4::
	copyvar VAR_OBJ_GFX_ID_7, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_SetRandomAudience5::
	copyvar VAR_OBJ_GFX_ID_8, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_SetRandomAudience6::
	copyvar VAR_OBJ_GFX_ID_9, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

LavaridgeTown_Gym_Contest_Hall_EventScript_SetRandomAudience7::
	copyvar VAR_OBJ_GFX_ID_A, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

LavaridgeTown_Gym_Contest_Hall_EventScript_ReShowAudience::
	call LavaridgeTown_Gym_Contest_Hall_EventScript_CreateAudience
	return