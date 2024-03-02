Common_EventScript_FlyingTaxi::
	lock
	faceplayer
	compare VAR_FLYING_TAXI, FLYING_TAXI_UNAVAILABLE
	goto_if_eq EventScript_FlyingTaxi_Unavailable
	compare VAR_FLYING_TAXI, FLYING_TAXI_FIRST_USE
	goto_if_eq EventScript_FlyingTaxi_FirstUse
	goto EventScript_FlyingTaxi_Available


EventScript_FlyingTaxi_Unavailable:
	switch VAR_TEMP_F
	case 0, EventScript_FlyingTaxi_Unavailable_RandomiseReason
	case 1, EventScript_FlyingTaxi_Unavailable_Reason
	case 2, EventScript_FlyingTaxi_Unavailable_Reason
	case 3, EventScript_FlyingTaxi_Unavailable_Reason
	case 4, EventScript_FlyingTaxi_Unavailable_Reason
	case 5, EventScript_FlyingTaxi_Unavailable_Reason
    
EventScript_FlyingTaxi_Unavailable_Reason:
	msgbox gText_FlyingTaxi_Unavailable, MSGBOX_DEFAULT
	closemessage
    release
	end

EventScript_FlyingTaxi_Unavailable_RandomiseReason:
	random 5
	copyvar VAR_TEMP_F, VAR_RESULT
	addvar VAR_TEMP_F, 1
	goto EventScript_FlyingTaxi_Unavailable


EventScript_FlyingTaxi_FirstUse:
	setvar VAR_FLYING_TAXI, FLYING_TAXI_AVAILABLE
	msgbox gText_FlyingTaxi_FirstUse, MSGBOX_YESNO
    compare VAR_RESULT, YES
	goto_if_eq EventScript_FlyingTaxi_OpenMap
	msgbox gText_FlyingTaxi_Goodbye, MSGBOX_DEFAULT
    closemessage
    release
	end


EventScript_FlyingTaxi_Available:
	msgbox gText_FlyingTaxi_Available, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_FlyingTaxi_OpenMap
	msgbox gText_FlyingTaxi_Goodbye, MSGBOX_DEFAULT
    closemessage
    release
	end

EventScript_FlyingTaxi_OpenMap:
	msgbox gText_FlyingTaxi_WhereToGo, MSGBOX_DEFAULT
	setvar VAR_FLYING_TAXI, FLYING_TAXI_IN_USE
    closemessage
    release
	special FieldLoadFlyMap
    end
    

