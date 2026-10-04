Mossdeep_City_Gym_Elevator_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Mossdeep_City_Gym_Elevator_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Mossdeep_City_Gym_Elevator_OnFrame
	.byte 0

Mossdeep_City_Gym_Elevator_OnWarp:
	map_script_2 VAR_TEMP_1, 0, LavaridgeTown_Gym_Movement_FaceUp
	.2byte 0

Mossdeep_City_Gym_Elevator_OnFrame:
	map_script_2 VAR_TEMP_0, 0, Mossdeep_City_Gym_Elevator_Movement_EventScript_EnterElevator
	.2byte 0

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Mossdeep_City_Gym_Elevator_Movement_EventScript_EnterElevator::
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_MOSSDEEP_RECEPTIONIST_ELEVATOR, Mossdeep_City_Gym_Elevator_Movement_AttendantEnter
	applymovement LOCALID_PLAYER, Mossdeep_City_Gym_Elevator_Movement_PlayerEnter
	waitmovement 0
	special BufferBattleTowerElevatorFloors
	waitse
	special MoveElevator
	delay 48	
	applymovement LOCALID_MOSSDEEP_RECEPTIONIST_ELEVATOR, Mossdeep_City_Gym_Elevator_Movement_AttendantExit
	applymovement LOCALID_PLAYER, Mossdeep_City_Gym_Elevator_Movement_PlayerExit
	waitmovement 0
	call Mossdeep_City_Gym_Elevator_EventScript_WarpToNextRoom
	end

Mossdeep_City_Gym_Elevator_EventScript_WarpToNextRoom::
	warp MAP_MOSSDEEP_CITY_GYM_CORRIDOR, 8, 2
	waitstate
	return

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Mossdeep_City_Gym_Elevator_Movement_AttendantEnter:
	walk_up
	walk_right
	face_down
	step_end

Mossdeep_City_Gym_Elevator_Movement_PlayerEnter:
	walk_up
	walk_up
	face_down
	step_end

Mossdeep_City_Gym_Elevator_Movement_AttendantExit:
	walk_down
	walk_down
	set_invisible
	step_end

Mossdeep_City_Gym_Elevator_Movement_PlayerExit:
	walk_right
	walk_down
	walk_down
	step_end

