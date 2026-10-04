Mossdeep_City_Gym_BattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Mossdeep_City_Gym_BattleRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Mossdeep_City_Gym_BattleRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Mossdeep_City_Gym_BattleRoom_OnFrame
	.byte 0

Mossdeep_City_Gym_BattleRoom_OnTransition::
	setflag FLAG_TEMP_HIDE_FOLLOWER
	setflag FLAG_HIDE_MOSSDEEP_TRAINER_1
	setflag FLAG_HIDE_MOSSDEEP_TRAINER_2
	setflag FLAG_HIDE_MOSSDEEP_TRAINER_3
	setflag FLAG_HIDE_ANABEL
	end

Mossdeep_City_Gym_BattleRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, LavaridgeTown_Gym_Movement_FaceUp
	.2byte 0

Mossdeep_City_Gym_BattleRoom_OnFrame::
	map_script_2 VAR_TEMP_0, 0, Mossdeep_City_Gym_BattleRoom_EventScript_EnterBattleRoom
	map_script_2 VAR_TEMP_0, 1, Mossdeep_City_Gym_BattleRoom_EventScript_FightTrainer1
	map_script_2 VAR_TEMP_0, 2, Mossdeep_City_Gym_BattleRoom_EventScript_FightTrainer2
	map_script_2 VAR_TEMP_0, 3, Mossdeep_City_Gym_BattleRoom_EventScript_FightTrainer3
	map_script_2 VAR_TEMP_0, 4, Mossdeep_City_Gym_BattleRoom_EventScript_FightAnabel
	.2byte 0

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Mossdeep_City_Gym_BattleRoom_EventScript_EnterBattleRoom::
	lock
	applymovement LOCALID_MOSSDEEP_RECEPTIONIST_BATTLEROOM, Mossdeep_City_Gym_BattleRoom_Movement_ReceptionistTurns
	applymovement LOCALID_PLAYER, Mossdeep_City_Gym_BattleRoom_Movement_PlayerWalkIntoBattleRoom
	waitmovement 0
	setvar VAR_TEMP_0, 1

Mossdeep_City_Gym_BattleRoom_EventScript_FightTrainer1::
	clearflag FLAG_HIDE_MOSSDEEP_TRAINER_1
	addobject LOCALID_MOSSDEEP_TRAINER_1, MAP_MOSSDEEP_CITY_GYM_BATTLE_ROOM
	applymovement LOCALID_MOSSDEEP_TRAINER_1, Mossdeep_City_Gym_BattleRoom_Movement_TrainerWalkIntoBattleRoom
	waitmovement 0
	call MossdeepCity_Gym_BattleRoom_EventScript_Clifford
	applymovement LOCALID_MOSSDEEP_TRAINER_1, Mossdeep_City_Gym_BattleRoom_Movement_TrainerWalkOutOfBattleRoom
	waitmovement 0
	setflag FLAG_HIDE_MOSSDEEP_TRAINER_1
	playse SE_EXIT
	removeobject LOCALID_MOSSDEEP_TRAINER_1
	waitse
	delay 48
	setvar VAR_TEMP_0, 2

Mossdeep_City_Gym_BattleRoom_EventScript_FightTrainer2::
	clearflag FLAG_HIDE_MOSSDEEP_TRAINER_2
	addobject LOCALID_MOSSDEEP_TRAINER_2, MAP_MOSSDEEP_CITY_GYM_BATTLE_ROOM
	applymovement LOCALID_MOSSDEEP_TRAINER_2, Mossdeep_City_Gym_BattleRoom_Movement_TrainerWalkIntoBattleRoom
	waitmovement 0
	call MossdeepCity_Gym_BattleRoom_EventScript_Nicholas
	applymovement LOCALID_MOSSDEEP_TRAINER_2, Mossdeep_City_Gym_BattleRoom_Movement_TrainerWalkOutOfBattleRoom
	waitmovement 0
	setflag FLAG_HIDE_MOSSDEEP_TRAINER_2
	playse SE_EXIT
	removeobject LOCALID_MOSSDEEP_TRAINER_2
	waitse
	delay 48
	setvar VAR_TEMP_0, 3

Mossdeep_City_Gym_BattleRoom_EventScript_FightTrainer3::
	clearflag FLAG_HIDE_MOSSDEEP_TRAINER_3
	addobject LOCALID_MOSSDEEP_TRAINER_3, MAP_MOSSDEEP_CITY_GYM_BATTLE_ROOM
	applymovement LOCALID_MOSSDEEP_TRAINER_3, Mossdeep_City_Gym_BattleRoom_Movement_TrainerWalkIntoBattleRoom
	waitmovement 0
	call MossdeepCity_Gym_BattleRoom_EventScript_Macey
	applymovement LOCALID_MOSSDEEP_TRAINER_3, Mossdeep_City_Gym_BattleRoom_Movement_TrainerWalkOutOfBattleRoom
	waitmovement 0
	setflag FLAG_HIDE_MOSSDEEP_TRAINER_3
	playse SE_EXIT
	removeobject LOCALID_MOSSDEEP_TRAINER_3
	waitse
	delay 48
	setvar VAR_TEMP_0, 4

Mossdeep_City_Gym_BattleRoom_EventScript_FightAnabel::
	clearflag FLAG_HIDE_ANABEL
	addobject LOCALID_ANABEL, MAP_MOSSDEEP_CITY_GYM_BATTLE_ROOM
	applymovement LOCALID_ANABEL, Mossdeep_City_Gym_BattleRoom_Movement_TrainerWalkIntoBattleRoom
	waitmovement 0
	goto MossdeepCity_Gym_EventScript_TateAndLiza


MossdeepCity_Gym_BattleRoom_EventScript_Clifford::
	trainerbattle_no_intro TRAINER_TERRY, MossdeepCity_Gym_Text_CliffordDefeat
	return

MossdeepCity_Gym_BattleRoom_EventScript_Nicholas::
	trainerbattle_no_intro TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasDefeat
	return

MossdeepCity_Gym_BattleRoom_EventScript_Macey::
	trainerbattle_no_intro TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyDefeat
	return

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Mossdeep_City_Gym_BattleRoom_Movement_ReceptionistTurns:
	face_up
	step_end

Mossdeep_City_Gym_BattleRoom_Movement_PlayerWalkIntoBattleRoom:
	walk_up
	walk_left
	walk_up
	walk_up
	face_right
	step_end

Mossdeep_City_Gym_BattleRoom_Movement_TrainerWalkIntoBattleRoom:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	face_left
	step_end

Mossdeep_City_Gym_BattleRoom_Movement_TrainerWalkOutOfBattleRoom:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
MossdeepCity_Gym_Text_CliffordDefeat:
	.string "Please help us.$"


MossdeepCity_Gym_Text_NicholasDefeat:
	.string "I WANNA GO HOME!$"


MossdeepCity_Gym_Text_MaceyDefeat:
	.string "I don't wanna be here anymore.$"