FortreeCity_Gym_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_3F_OnTransition
	.byte 0

FortreeCity_Gym_3F_OnTransition::
	goto_if_set FLAG_BEAT_BRANDON_1, FortreeCity_Gym_3F_EventScript_BrandonGone
	end

FortreeCity_Gym_3F_EventScript_Brandon::
	lock
	faceplayer
	trainerbattle_single TRAINER_BRANDON_PRE, FortreeCity_Gym_3F_Text_BrandonIntro, FortreeCity_Gym_3F_Text_BrandonDefeat, FortreeCity_Gym_3F_EventScript_BrandonFirstDefeated, NO_MUSIC

FortreeCity_Gym_3F_EventScript_BrandonFirstDefeated::
	msgbox FortreeCity_Gym_3F_Text_BrandonFirstDefeated, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_BEAT_BRANDON_1
	playse SE_EXIT
	removeobject LOCALID_BRANDON_3F
	waitse
	release
	end

FortreeCity_Gym_3F_EventScript_BrandonGone::
	removeobject LOCALID_BRANDON_3F
	end

FortreeCity_Gym_3F_Text_BrandonIntro:
	.string "{PLAYER}!\n"
	.string "Welcome to THE PYRAMID!\p"
	.string "Wahahahaha!\p"
	.string "I hope you didn't get lost\n"
	.string "on your way up!\p"
	.string "Let me tell you how this is\n"
	.string "gonna work.\p"
	.string "We're going to battle 2 times.\n"
	.string "If you can beat me both times,\l"
	.string "I'll hand over the FEATHER BADGE.\p"
	.string "I hope you're ready.$"

FortreeCity_Gym_3F_Text_BrandonDefeat:
	.string "Wahahahaha!$"

FortreeCity_Gym_3F_Text_BrandonFirstDefeated:
	.string "Now you've REALLY got me fired up!\p"
	.string "I'll be waiting for you\n"
	.string "at the top of THE PYRAMID.\p"
	.string "Next one won't be so easy.$"