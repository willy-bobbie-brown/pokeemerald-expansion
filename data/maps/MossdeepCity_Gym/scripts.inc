MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnWarp
	.byte 0

MossdeepCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_1, 0, LavaridgeTown_Gym_Movement_FaceUp
	.2byte 0

MossdeepCity_Gym_OnTransition:
	end
@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

MossdeepCity_Gym_EventScript_Receptionist::
	lock
	msgbox MossdeepCiy_Gym_Text_Receptionist_Welcome, MSGBOX_DEFAULT
	msgbox MossdeepCiy_Gym_Text_Receptionist_Entry, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, 1
	goto_if_eq MossdeepCity_Gym_EventScript_LeadToElevator
	msgbox MossdeepCity_Gym_Text_Receptionist_Goodbye, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_LeadToElevator::
    lockall
    applymovement LOCALID_MOSSDEEP_RECEPTIONIST, MossdeepCity_Gym_Movement_ReceptionistWalkToDoor
    applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WalkToDoor
    waitmovement 0
    opendoor 12, 1
    waitdooranim
    applymovement LOCALID_MOSSDEEP_RECEPTIONIST, MossdeepCity_Gym_Movement_ReceptionistWalkThroughDoor
    applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WalkThroughDoor
    waitmovement 0
    warp MAP_MOSSDEEP_CITY_GYM_ELEVATOR, 1, 6
    waitstate
    releaseall
    end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

MossdeepCity_Gym_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MossdeepCity_Gym_Movement_ReceptionistWalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MossdeepCity_Gym_Movement_ReceptionistWalkThroughDoor:
	walk_up
	set_invisible
	step_end

MossdeepCity_Gym_Movement_WalkThroughDoor:
	walk_up
	walk_up
	step_end

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

MossdeepCiy_Gym_Text_Receptionist_Welcome:
	.string "Hello!\n"
	.string "Welcome to the BATTLE TOWER.\p"
	.string "If you would like to take on\n"
	.string "the gym challenge, I can assist you.\p"
	.string "Here at the BATTLE TOWER, you must\n"
	.string "win a series of matches before\l"
	.string "challenging the SALON MAIDEN.\p"
	.string "Once you start the challenge, you\n"
	.string "may not return until you have\l"
	.string "finished all the matches.$"

MossdeepCiy_Gym_Text_Receptionist_Entry:
	.string "Would you like take on the challenge?$"

MossdeepCity_Gym_Text_Receptionist_Goodbye:
	.string "Let me know when you would like to enter.$"

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.string "TATE: Hehehe… Were you surprised?\p"
	.string "LIZA: Fufufu… Were you surprised?\p"
	.string "TATE: That there are two GYM LEADERS?\n"
	.string "LIZA: That there are two GYM LEADERS?\p"
	.string "TATE: We're twins!\n"
	.string "LIZA: We're twins!\p"
	.string "TATE: We don't need to talk because…\n"
	.string "LIZA: We can each determine what…\p"
	.string "TATE: The other is thinking…\n"
	.string "LIZA: All in our minds!\p"
	.string "TATE: This combination of ours…\n"
	.string "LIZA: Can you beat it?$"

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.string "TATE: What?! Our combination…\n"
	.string "LIZA: Was shattered!\p"
	.string "TATE: It can't be helped. You've won…\n"
	.string "LIZA: So, in recognition, take this.$"

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.string "{PLAYER} received the MIND BADGE\n"
	.string "from TATE and LIZA.$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.string "TATE: The MIND BADGE enhances the\n"
	.string "SP. ATK and SP. DEF of POKéMON.\p"
	.string "LIZA: It also lets you use the HM move\n"
	.string "DIVE outside of battle.\p"
	.string "TATE: You should also take this, too.$"

MossdeepCity_Gym_Text_ExplainCalmMind:
	.string "TATE: That TM04 contains…\n"
	.string "LIZA: CALM MIND!\p"
	.string "TATE: It raises SP. ATK and…\n"
	.string "LIZA: It raises SP. DEF!\p"
	.string "TATE: It's a move that's perfect…\n"
	.string "LIZA: For PSYCHIC POKéMON!\p"
	.string "… … … … … …$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.string "Registered GYM LEADERS TATE & LIZA\n"
	.string "in the POKéNAV.$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.string "TATE: Looks like the bond between you\n"
	.string "and your POKéMON is far stronger than\l"
	.string "the bond that we share as twins.\p"
	.string "LIZA: You will become even stronger!\n"
	.string "We've battled you, so we know.$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.string "TATE: Hehehe… Were you surprised?\p"
	.string "LIZA: That there are two GYM LEADERS?\p"
	.string "TATE: Oops, you have only one…\n"
	.string "LIZA: POKéMON that can battle.\p"
	.string "TATE: We can't battle that way!\p"
	.string "LIZA: If you want to challenge us,\n"
	.string "bring some more POKéMON.$"

MossdeepCity_Gym_Text_GymStatue:
	.string "MOSSDEEP CITY POKéMON GYM$"

MossdeepCity_Gym_Text_GymStatueCertified:
	.string "MOSSDEEP CITY POKéMON GYM\p"
	.string "LIZA AND TATE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.string "TATE: POKéMON…\n"
	.string "LIZA: POKéMON…\p"
	.string "TATE: By changing the party's mix…\n"
	.string "LIZA: The battle style changes.\p"
	.string "TATE: But me…\n"
	.string "LIZA: But me…\p"
	.string "TATE: I'll always be with LIZA!\n"
	.string "LIZA: I'll always be with TATE!\p"
	.string "TATE: Our combination…\n"
	.string "LIZA: We'll show you again and again!$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.string "TATE: You and your POKéMON…\n"
	.string "LIZA: It's as if you were siblings!$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.string "TATE: You can knock us down,\n"
	.string "but we'll never stay down!\p"
	.string "LIZA: Because the two of us,\n"
	.string "we always support each other!$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.string "TATE: You're back again…\n"
	.string "LIZA: You're back again…\p"
	.string "TATE: To give us a rematch.\n"
	.string "LIZA: To give us a rematch.\p"
	.string "TATE: But…\n"
	.string "LIZA: For our match…\p"
	.string "TATE: You brought just one POKéMON!\n"
	.string "LIZA: You brought just one POKéMON!\p"
	.string "TATE: We need you to bring at least…\n"
	.string "LIZA: Two POKéMON when you come back.$"
