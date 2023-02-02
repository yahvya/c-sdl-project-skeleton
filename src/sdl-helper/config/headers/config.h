#if !defined(SDL_HELPER_CONFIG_H)
#define SDL_HELPER_CONFIG_H

    #include "./window-config.h"

    /**
     * @brief configuration par défaut d'une application
    */
    #define APPLICATION_DEFAULT_CONFIG {\
        .windowConfig = {300,400,{255, 255, 255} },\
    }

    /**
     * @struct App
     * @brief représente les données permettant la gestion d'une application
     * @memberof WindowConfig
    */
    typedef struct{
        WindowConfig windowConfig;
    }App;

    /**
     * @brief affiche la configuration d'une application
     * @param application
    */
    void printApplicationConfig(App* application);
#endif