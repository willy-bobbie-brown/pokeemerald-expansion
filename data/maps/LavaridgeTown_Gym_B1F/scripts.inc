LavaridgeTown_Gym_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LavaridgeTown_Gym_B1F_OnWarp
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, LavaridgeTown_Gym_B1F_OnReturn
	.byte 0

LavaridgeTown_Gym_B1F_OnWarp:
	map_script_2 VAR_TEMP_1, 0, LavaridgeTown_Gym_B1F_EventScript_CreateAudienceAndFaceUp
	.2byte

LavaridgeTown_Gym_B1F_OnReturn:
	call LavaridgeTown_Gym_B1F_EventScript_CreateAudience
	end

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

LavaridgeTown_Gym_B1F_EventScript_CreateAudienceAndFaceUp::
	call LavaridgeTown_Gym_B1F_EventScript_CreateAudience
	call LavaridgeTown_Gym_Movement_FaceUp
	return

LavaridgeTown_Gym_B1F_EventScript_CreateAudience::
	createvobject OBJ_EVENT_GFX_WOMAN_2,      0, 0, 0,   3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_MAN_3,        1, 1, 1,   3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_MAN_4,        2, 0, 2,   3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_LITTLE_BOY_3, 3, 2, 2,   3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_WOMAN_1,      4, 3, 0,   3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_GIRL_1,       5, 5, 0,   3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_MAN_5,        6, 6, 0,   3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_LASS,         7, 6, 2,   3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_NINJA_BOY,    8, 6, 1,   3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_TWIN,         9, 7, 1,   3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_OLD_MAN,      10, 7, 2,  3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_OLD_WOMAN,    11, 8, 2,  3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_BEAUTY,       12, 9, 2,  3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_FAT_MAN,      13, 8, 1,  3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_CAMERAMAN,    14, 10, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_FISHERMAN,    15, 11, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_CAMPER,       16, 11, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_BLACK_BELT,   17, 12, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_WOMAN_3,      18, 13, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_EXPERT_F,     19, 14, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_EXPERT_M,     20, 15, 0, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_BOY_3,        21, 15, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_BOY_1,        22, 16, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_GIRL_2,       23, 18, 1, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_MAN_1,        24, 19, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_WOMAN_4,      25, 19, 0, 3, DIR_SOUTH
	return

LavaridgeTown_Gym_B1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_B1F_Text_FlanneryIntro, LavaridgeTown_Gym_B1F_Text_FlanneryDefeat, LavaridgeTown_Gym_B1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_B1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_B1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_B1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_B1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_B1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_B1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
@	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_B1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_B1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	warp MAP_LAVARIDGE_TOWN_GYM_1F, 8, 10
	waitstate
	end

LavaridgeTown_Gym_B1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_B1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_B1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_B1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_B1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_B1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_B1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_B1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_B1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

@ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

LavaridgeTown_Gym_B1F_Text_FlanneryIntro:
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

LavaridgeTown_Gym_B1F_Text_FlanneryDefeat:
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

LavaridgeTown_Gym_B1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} received the HEAT BADGE\n"
	.string "from FLANNERY.$"

LavaridgeTown_Gym_B1F_Text_ExplainHeatBadgeTakeThis:
	.string "If you have a HEAT BADGE, all POKéMON\n"
	.string "up to Level 50, even those you get in\l"
	.string "trades from other people, will obey\l"
	.string "you completely.\p"
	.string "And, it lets POKéMON use the HM move\n"
	.string "STRENGTH outside of battle.\p"
	.string "This is a token of my appreciation.\n"
	.string "Don't be shy about taking it!$"

LavaridgeTown_Gym_B1F_Text_ExplainOverheat:
	.string "That TM50 contains OVERHEAT.\p"
	.string "That move inflicts serious damage on\n"
	.string "the opponent.\p"
	.string "But it also sharply cuts the SP. ATK\n"
	.string "of the POKéMON using it. It might not\l"
	.string "be suitable for longer battles.$"

LavaridgeTown_Gym_B1F_Text_RegisteredFlannery:
	.string "Registered GYM LEADER FLANNERY\n"
	.string "in the POKéNAV.$"

LavaridgeTown_Gym_B1F_Text_FlanneryPostBattle:
	.string "Your power reminds me of someone…\p"
	.string "Oh! I know! You battle like NORMAN,\n"
	.string "the GYM LEADER of PETALBURG.$"

LavaridgeTown_Gym_B1F_Text_FlanneryPreRematch:
	.string "FLANNERY: Losing a battle isn't going\n"
	.string "to deflate me.\p"
	.string "I love POKéMON.\n"
	.string "I love to battle.\l"
	.string "And… I love this GYM!\p"
	.string "Let's exchange superhot moves\n"
	.string "in another battle!$"

LavaridgeTown_Gym_B1F_Text_FlanneryRematchDefeat:
	.string "Whew!\n"
	.string "On the verge of eruption!$"

LavaridgeTown_Gym_B1F_Text_FlanneryPostRematch:
	.string "FLANNERY: I lost the match,\n"
	.string "but I'm completely satisfied.\p"
	.string "It's not often I get to enjoy a battle\n"
	.string "this heated.\p"
	.string "Let's have another one like this\n"
	.string "again sometime!$"

LavaridgeTown_Gym_B1F_Text_FlanneryRematchNeedTwoMons:
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
