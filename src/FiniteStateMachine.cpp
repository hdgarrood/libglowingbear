/*
 * FiniteStateMachine.cpp
 *
 *  Created on: Feb 9, 2012
 *      Author: Harry
 */

#include "FiniteStateMachine.h"

Finite_State_Machine::Finite_State_Machine() {
	currentStateID = STATE_NULL;
	nextStateID = STATE_NULL;
	currentState = NULL;
}

void Finite_State_Machine::set_next_state(int newState) {
    nextStateID = newState;
}

void Finite_State_Machine::change_state() {
    if (nextStateID != STATE_NULL) {
        delete currentState;
        // the idea here is that a subclass will override the unordered
        // mapping of state IDs to classes to define which new state to
        // instantiate.
        
        currentStateID = nextStateID;
        nextStateID = STATE_NULL;
    }
}

int Finite_State_Machine::get_current_state() {
	return currentStateID;
}