/*
 * Button.h
 *
 *  Created on: Feb 12, 2012
 *      Author: Harry
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "SDL/SDL.h"
#include <string>

class Button {
public:
    enum State {
        NORMAL,
        ACTIVE,
        PRESSED
    };
	virtual Button(int x, int y, std::string message);
	virtual ~Button();
    virtual bool check_hover(int x, int y);
	virtual void render();
	virtual void change_state(State newState);
	virtual State get_state();
private:
	SDL_Surface *normal, *active, *pressed, *text;
	SDL_Rect mask;
	State current_state;
};

#endif /* BUTTON_H_ */
