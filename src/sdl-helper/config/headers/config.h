#if !defined(SDL_HELPER_CONFIG_H)
#define SDL_HELPER_CONFIG_H

    #include "./window-config.h"

    /**
     * @brief configuration par défaut d'une application
    */
    #define APPLICATION_DEFAULT_CONFIG {\
        .window = WINDOW_DEFAULT_CONFIG,\
    }

    /**
     * @struct App
     * @brief représente les données permettant la gestion d'une application
     * @param Window
    */
    typedef struct{
        Window window;
    }App;

    /**
     * @brief affiche la configuration d'une application
     * @param application adresse de la structure de l'application
    */
    void printApplicationConfig(App* application);

    /**
     * @brief crée une structure représentant l'application
     * @attention to call staticly not for dynamic allocation
     * @param applicationWindow
    */
    App newApplication(Window applicationWindow);
#endif