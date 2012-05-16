#include "SDL/SDL.h"
#include <string>

namespace GBEAR {

class Surface {
public:
    static SDL_Surface *load(std::string);
    static void apply(int, int, SDL_Surface*, SDL_Surface*);
};

}

