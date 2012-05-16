/*
 * FiniteStateMachine.h
 *
 *  Created on: Feb 9, 2012
 *      Author: Harry
 */

#ifndef FINITESTATEMACHINE_H_
#define FINITESTATEMACHINE_H_

#include "SDL/SDL.h"
#include "GameState.h"

class FiniteStateMachine {
public:
	FiniteStateMachine();
    virtual ~FiniteStateMachine() = 0;
	virtual void set_next_state(int newState);
	virtual void change_state();
	virtual GameState get_current_state();
private:
	GameState *currentState;
	int currentStateID;
	int nextStateID;
};

#endif /* FINITESTATEMACHINE_H_ */
