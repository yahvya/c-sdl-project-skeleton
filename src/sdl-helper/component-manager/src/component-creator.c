#include "../headers/component-creator.h"
#include "../headers/component.h"
#include <SDL2/SDL_image.h>

SDL_Texture* loadImage(SDL_Renderer* renderer,char* imgPath){
    return IMG_LoadTexture(renderer,imgPath);
}