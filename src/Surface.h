#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

namespace GBEAR {

class Surface {
public:
    SDL_Surface *load(std::string);
    void apply(int, int, SDL_Surface*, SDL_Surface*);
};

}
