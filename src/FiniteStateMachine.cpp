#include "FiniteStateMachine.h"

namespace GBEAR {

FiniteStateMachine::FiniteStateMachine() {
	currentStateID = STATE_NULL;
	nextStateID = STATE_NULL;
	currentState = NULL;
}

// call this whenever; the FSM won't actually change state until the end
// of the loop
void FiniteStateMachine::set_next_state(int newState) {
    nextStateID = newState;
}

// this should only be called at the end of the game's main loop.
void FiniteStateMachine::change_state() {
    if (nextStateID != STATE_NULL) {
        delete currentState;
        // get_new_state should be overriden by a subclass and
        // return a pointer to a new GameState
        currentState = get_new_state(nextStateID);
        currentStateID = nextStateID;
        nextStateID = STATE_NULL;
    }
}

int FiniteStateMachine::get_current_state() {
	return currentStateID;
}
}
