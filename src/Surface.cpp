#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "glowingbear/Surface.h"

namespace GBEAR {

// SDL_Surface *Surface::load
// takes a filename as a string, and returns a pointer to an SDL_Surface
// which is optimized somehow -- has the right BPP or something.
SDL_Surface *Image::load(std::string filename) {
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load(filename.c_str());

    if (loadedImage != NULL) {
        optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
        SDL_FreeSurface(loadedImage);
    }
    return optimizedImage;
}

// void Surface::apply
// Applies +source+ onto +destination+ at position (+x+, +y+)
void Surface::apply(int x, int y, SDL_Surface *source, SDL_Surface *destination) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(source, NULL, destination, &offset);
}

}

