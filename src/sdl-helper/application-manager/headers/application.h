#if !defined(SDLH_APPLICATION_H)
#define SDLH_APPLICATION_H
    #include <stdbool.h>
    #include "./structs.h"
    #include <SDL2/SDL_image.h>

    /**
     * @brief flags par défaut de sdl
     * @param SDL_INIT_VIDEO
     * @param SDL_INIT_AUDIO
    */
    #define SDLH_SDL_DEFAULT_FLAGS SDL_INIT_VIDEO | SDL_INIT_AUDIO

    /**
     * @brief flags par défaut de sdl image
     * @param IMG_INIT_JPG
     * @param IMG_INIT_PNG
    */
    #define SDLH_SDLIMAGE_DEFAULT_FLAGS IMG_INIT_JPG | IMG_INIT_PNG

    /**
     * @brief configuration par défaut d'une application
     * @attention components are not init to NULL
    */
    #define APPLICATION_DEFAULT_CONFIG {\
        .window = SDLH_WINDOW_DEFAULT_CONFIG,\
        .actionsList = NULL,\
        .exit = false,\
        .componentsDescriptor = {.countOfComponentToLoad = 0,.type = NONE}\
    }

    /**
     * @brief affiche la configuration d'une application
     * @param application adresse de la structure de l'application
     * @returns l'application
    */
    App* printApplicationConfig(App* application);

    /**
     * @brief il rempli la structure de l'application
     * @param application l'application
     * @param applicationWindow la fenêtre de l'application
     * @param applicationActionList liste des fonctions qui seront appellés
     * @return l'application
    */
    App* newApplication(App* application,Window applicationWindow,CallableList applicationActionList);

    /**
     * @brief clone les paramètres actuelles de l'application dans la nouvelle
     * @attention les élements présent par adresse seront aussi copié
     * @param toClone l'application à cloné
     * @param newApp la nouvelle application
     * @returns la nouvelle application
    */
    App* cloneApplication(App* toClone,App* newApp);

    /**
     * @brief créer une structure d'actions
     * @details les fonctions peuvent être NULL
     * @details toCallOnClose recevra l'application
     * @attention à appeller statiquement dans le programme
     * @param toCallOnClose fonction à appeller à la fermeture de la fenêtre
     * @param manageEvent fonction pour gérer les évenements non traités à l'interne du helper
     * @param placeComponents fonction pour placer les composants, remplace la fonction par défaut du helper
     * @return la structure
    */
    CallableList newCallableList(bool (*toCallOnClose)(void*),void (*manageEvent)(void*),void (*placeComponents)(void*) );

    /**
     * @brief initialise la sdl et retourne si l'initialisation à réussi
     * @attention à appeller une fois au début du programme
     * @param flags flags à initialisé, si SDLH_DEFAULT alors flags par défaut SDLH_SDL_DEFAULT_FLAGS
     * @return vrai si réussi sinon faux
    */
    bool initSDL(Uint32 sdlFlags,Uint32 sdlImageFlags);

    /**
     * @brief quitte sdl
     * @attention à appeller une fois toutes les applications fermés
    */
    void quitSDL(void);

    /**
     * @brief initialise les données à initialiser dans l'application
     * @param application l'application
     * @returns vrai si toutes les initialisations ont réussi sinon faux
    */
    bool initApplication(App* application);

    /**
     * @brief lance l'application (bloquant pour le processus actuel)
     * @return si l'application s'est normalement arrêté
    */
    bool runApplication(App* application);

    /**
     * @brief libère les ressource de l'application
     * @param application
    */
    void endApplication(App* application);

    /**
     * @brief ajoute un composant à l'application
     * @attention to count the number of arguments, the internal counter of the application component descriptor is used
     * @param application l'application
     * @param components tableau d'adresses de composants à ajouter
    */
    void addComponentToApplication(App* application,Component** components);
#endif