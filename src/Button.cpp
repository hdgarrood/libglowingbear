#include "SDL/SDL.h"
#include "glowingbear/Button.h"
#include "glowingbear/Surface.h"
#include "glowingbear/geometry.h"

namespace GBEAR {

Button::Button(int x, int y) {
    normal = NULL;
    active = NULL;
    pressed = NULL;
    text = NULL;
    current_state = NORMAL;
}

Button::~Button() {
    SDL_FreeSurface(normal);
    SDL_FreeSurface(active);
    SDL_FreeSurface(pressed);
    SDL_FreeSurface(text);
}

bool Button::check_hover(int x, int y) {
    int relX = x - mask.x;
    int relY = y - mask.y;

    if ((relX > 0) && (relY > 0) && (relX < mask.w) && (relY < mask.h))
        return true;
    return false;
}

void Button::render(SDL_Surface *screen) {
    switch (current_state) {
    case NORMAL:
        Surface::apply(mask.x, mask.y, normal, screen);
        break;
    case ACTIVE:
        Surface::apply(mask.x, mask.y, active, screen);
        break;
    case PRESSED:
        Surface::apply(mask.x, mask.y, pressed, screen);
        break;
    }
    Point text_position;
    text_position.x = mask.x + ((mask.w - text->w) / 2);
    text_position.y = mask.y + ((mask.h - text->h) / 2);
    if (current_state == PRESSED) text_position.y += 5;
    Surface::apply(text_position.x, text_position.y, text, screen);
}

void Button::change_state(Button::State newState) {
    current_state = newState;
}

Button::State Button::get_state() {
    return current_state;
}
}
