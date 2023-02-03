#if !defined SDL_HELPER_WINDOW_CONFIG_H
#define SDL_HELPER_WINDOW_CONFIG_H
    #include <SDL2/SDL.h>
    #include <stdbool.h>

    #include "./config.h"

    /**
     * @brief nombre de caractères maximum dans le nom d'une fenêtre
    */
    #define WINDOW_TITLE_MAX_LENGTH 200

    /**
     * @brief configuration par défaut d'une fenêtre
    */
    #define WINDOW_DEFAULT_CONFIG {"Default window title",300,400,{255, 255, 255},true,true}

    /**
     * @struct WindowConfig
     * @brief représente la configuration d'une fenêtre
     * @param windowWidth largeur de la fenêtre
     * @param windowHeight hauteur de la fenêtre 
     * @param windowBackgroundColor couleur de fond de la fenêtre
     * @param isResizable définis si la taille de la fenêtre peut être changé
    */
    typedef struct{
        char windowName[WINDOW_TITLE_MAX_LENGTH];
        int windowWidth;
        int windowHeight;
        SDL_Color windowBackgroundColor;
        bool isResizable;
        bool centered;
    }Window;

    /**
     * @brief affiche la configuration de la fenêtre
     * @param windowConfiguration configuration de la fenêtre
    */
    void printWindowConfig(Window* windowConfiguration);

    /**
     * @brief créer une structure de fenêtre
     * @attention to call staticly not for dynamic allocation
     * @param windowName nom de la fenêtre
     * @param windowWidth largeur de la fenêtre
     * @param windowHeight heuteur de la fenêtre
     * @param isResizable définis si la fenêtre peut  être redimensionné
     * @param backgroundR quantité de rouge composant la couleur de fond 
     * @param backgroundG quantité de vert composant la couleur de fond 
     * @param backgroundB quantité de bleue composant la couleur de fond 
    */
    Window newWindow(char* windowName,int windowWidth,int windowHeight,bool isResizable,int backgroundR,int backgroundG,int backgroundB);
#endif