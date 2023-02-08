#if !defined(SDLH_COMPONENT_LOADER_H)
#define SDLH_COMPONENT_LOADER_H
    #include "./structs.h"

    /**
     * @brief charge une image
     * @return la structure représentant l'image ou NULL
    */
    SDL_Surface* loadImage(char* imgPath);
#endif