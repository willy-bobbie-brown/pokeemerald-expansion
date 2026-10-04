Mossdeep_City_Gym_Corridor_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Mossdeep_City_Gym_Corridor_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Mossdeep_City_Gym_Corridor_OnFrame
	.byte 0

Mossdeep_City_Gym_Corridor_OnWarp:
	.2byte 0

Mossdeep_City_Gym_Corridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, Mossdeep_City_Gym_Corridor_Movement_EventScript_EnterCorridor
	.2byte 0

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Mossdeep_City_Gym_Corridor_Movement_EventScript_EnterCorridor::
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_MOSSDEEP_RECEPTIONIST_CORRIDOR, Mossdeep_City_Gym_Corridor_Movement_AttendantWalkDownCorridor
	applymovement LOCALID_PLAYER, Mossdeep_City_Gym_Corridor_Movement_PlayerWalkDownCorridor
	waitmovement 0
	opendoor 15, 1
	waitdooranim
	applymovement LOCALID_MOSSDEEP_RECEPTIONIST_CORRIDOR, Mossdeep_City_Gym_Corridor_Movement_AttendantWalkThroughDoor
	applymovement LOCALID_PLAYER, Mossdeep_City_Gym_Corridor_Movement_PlayerWalkThroughDoor
	waitmovement 0
	call Mossdeep_City_Gym_Corridor_EventScript_WarpToNextRoom
	end

Mossdeep_City_Gym_Corridor_EventScript_WarpToNextRoom::
	warp MAP_MOSSDEEP_CITY_GYM_BATTLE_ROOM, 4, 8
	waitstate
	return

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Mossdeep_City_Gym_Corridor_Movement_AttendantWalkDownCorridor:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

Mossdeep_City_Gym_Corridor_Movement_PlayerWalkDownCorridor:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Mossdeep_City_Gym_Corridor_Movement_AttendantWalkThroughDoor:
	walk_up
	set_invisible
	step_end

Mossdeep_City_Gym_Corridor_Movement_PlayerWalkThroughDoor:
	walk_right
	walk_up
	step_end