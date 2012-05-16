/*
 * Button.h
 *
 *  Created on: Feb 12, 2012
 *      Author: Harry
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "SDL/SDL.h"

namespace GBEAR {

class Button {
public:
    enum State {
        NORMAL,
        ACTIVE,
        PRESSED
    };
	Button(int x, int y);
	virtual ~Button();
    bool check_hover(int x, int y);
	virtual void render(SDL_Surface *screen);
	virtual void change_state(State newState);
	virtual State get_state();
private:
	SDL_Surface *normal, *active, *pressed, *text;
	SDL_Rect mask;
	State current_state;
};

}

#endif /* BUTTON_H_ */
