Route117_PokemonDayCare_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
	.byte 0

Route117_PokemonDayCare_OnTransition:
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
	end

Route117_PokemonDayCare_MoveDeleter_EventScript_MoveDeleter::
	lockall
	applymovement LOCALID_MOVE_DELETER_2, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route117_PokemonDayCare_MoveDeleter_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, Route117_PokemonDayCare_MoveDeleter_EventScript_ChooseMonAndMoveToForget
	case NO, Route117_PokemonDayCare_MoveDeleter_EventScript_ComeAgain
	releaseall
	end

Route117_PokemonDayCare_MoveDeleter_EventScript_ChooseMonAndMoveToForget::
	msgbox Route117_PokemonDayCare_MoveDeleter_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	chooseboxmon SELECT_PC_MON_MOVE_DELETER
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route117_PokemonDayCare_MoveDeleter_EventScript_ComeAgain
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, Route117_PokemonDayCare_MoveDeleter_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_MoveDeleter_EventScript_MonOnlyKnowsOneMove
	msgbox Route117_PokemonDayCare_MoveDeleter_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, Route117_PokemonDayCare_MoveDeleter_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox Route117_PokemonDayCare_MoveDeleter_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, Route117_PokemonDayCare_MoveDeleter_EventScript_TryForgetMove
	case NO, Route117_PokemonDayCare_MoveDeleter_EventScript_ComeAgain
	releaseall
	end

Route117_PokemonDayCare_MoveDeleter_EventScript_TryForgetMove::
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, Route117_PokemonDayCare_MoveDeleter_EventScript_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox Route117_PokemonDayCare_MoveDeleter_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

Route117_PokemonDayCare_MoveDeleter_EventScript_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox Route117_PokemonDayCare_MoveDeleter_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

Route117_PokemonDayCare_MoveDeleter_EventScript_EggCantForgetMoves::
	msgbox Route117_PokemonDayCare_MoveDeleter_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

Route117_PokemonDayCare_MoveDeleter_EventScript_ComeAgain::
	msgbox Route117_PokemonDayCare_MoveDeleter_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

Route117_PokemonDayCare_MoveDeleter_EventScript_LastMonWithSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox Route117_PokemonDayCare_MoveDeleter_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

Route117_PokemonDayCare_MoveDeleter_Text_ICanMakeMonForgetMove:
	.string "Uh…\n"
	.string "Oh, yes, I'm the MOVE DELETER.\p"
	.string "I can make POKéMON forget their moves.\p"
	.string "Would you like me to do that?$"

Route117_PokemonDayCare_MoveDeleter_Text_WhichMonShouldForget:
	.string "Which POKéMON should forget a move?$"

Route117_PokemonDayCare_MoveDeleter_Text_WhichMoveShouldBeForgotten:
	.string "Which move should be forgotten?$"

Route117_PokemonDayCare_MoveDeleter_Text_MonOnlyKnowsOneMove:
	.string "{STR_VAR_1} knows only one move\n"
	.string "so it can't be forgotten…$"

Route117_PokemonDayCare_MoveDeleter_Text_MonsMoveShouldBeForgotten:
	.string "Hm! {STR_VAR_1}'s {STR_VAR_2}?\n"
	.string "That move should be forgotten?$"

Route117_PokemonDayCare_MoveDeleter_Text_MonHasForgottenMove:
	.string "It worked to perfection!\p"
	.string "{STR_VAR_1} has forgotten\n"
	.string "{STR_VAR_2} completely.$"

Route117_PokemonDayCare_MoveDeleter_Text_ComeAgain:
	.string "Come again if there are moves that\n"
	.string "need to be forgotten.$"

Route117_PokemonDayCare_MoveDeleter_Text_EggCantForgetMoves:
	.string "What?\n"
	.string "No EGG should know any moves.$"

Route117_PokemonDayCare_MoveDeleter_Text_CantForgetSurf:
	.string "Hm!\p"
	.string "Your {STR_VAR_1} doesn't seem willing\n"
	.string "to forget SURF.$"

