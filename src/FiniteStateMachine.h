#ifndef FINITESTATEMACHINE_H_
#define FINITESTATEMACHINE_H_

#include "SDL/SDL.h"
#include "glowingbear/GameState.h"

namespace GBEAR {

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

}

#endif /* FINITESTATEMACHINE_H_ */
