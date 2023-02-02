#if !defined SDL_HELPER_WINDOW_CONFIG_H
#define SDL_HELPER_WINDOW_CONFIG_H
    #include <SDL2/SDL.h>
    #include "./config.h"

    /**
     * @struct WindowConfig
     * @brief représente la configuration d'une fenêtre
     * @param windowWidth largeur de la fenêtre
     * @param windowHeight hauteur de la fenêtre 
    */
    typedef struct{
        int windowWidth;
        int windowHeight;
        SDL_Color windowBackgroundColor;
    }WindowConfig;
#endif