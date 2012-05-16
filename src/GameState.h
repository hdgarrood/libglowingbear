#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "SDL/SDL.h"

namespace GBEAR {

class GameState
{
public:
    virtual void handle_events();
    virtual void do_logic() = 0;
    virtual void render() = 0;
    virtual ~GameState();
private:
    SDL_Event *event;
};

}

#endif /* GAMESTATE_H_ */
