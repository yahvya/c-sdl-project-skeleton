#if !defined(SDLH_WMG_STRUCTS)
#define SDLH_WMG_STRUCTS

    #include <SDL2/SDL.h>
    #include <stdbool.h>
    
    /**
     * @brief nombre de caractères maximum dans le nom d'une fenêtre
    */
    #define WINDOW_TITLE_MAX_LENGTH 200

    /**
     * @brief flags par défaut d'une fenêtre en plus des flags obligatoires
     * @param SDL_WINDOW_RESIZABLE
    */
    #define SDLH_WINDOW_DEFAULT_FLAGS (SDL_WINDOW_RESIZABLE)

    /**
     * @brief configuration par défaut d'une fenêtre
    */
    #define SDLH_WINDOW_DEFAULT_CONFIG {\
            .windowName = "Default window title",\
            .windowWidth = 300,\
            .windowHeight = 400,\
            .windowBackgroundColor = {255, 255, 255},\
            .isResizable = true,\
            .centered = true,\
            .flags = SDLH_WINDOW_DEFAULT_FLAGS,\
            .window = NULL\
        }

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
        Uint32 flags;
        SDL_Window* window;
    }Window;
#endif