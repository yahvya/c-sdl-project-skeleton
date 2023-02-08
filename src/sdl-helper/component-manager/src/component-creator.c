#include "../headers/component-creator.h"
#include "../headers/component.h"
#include <SDL2/SDL_image.h>
#include <stdlib.h>

SDL_Surface* loadImage(char* imgPath){
    return IMG_Load(imgPath);
}