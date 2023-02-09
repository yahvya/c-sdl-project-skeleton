#if !defined(SDLH_COMPONENT_LOADER_H)
#define SDLH_COMPONENT_LOADER_H
    #include "./structs.h"

    /**
     * @brief charge une image
     * @param renderer le renderer de la fenêtre
     * @param imgPath le chemin de l'image
     * @return SDL_Texture
    */
    SDL_Texture* loadImage(SDL_Renderer* renderer,char* imgPath);
#endif