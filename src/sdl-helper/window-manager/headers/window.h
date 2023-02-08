#if !defined(SDLH_WINDOW_H)
#define SDLH_WINDOW_H
    #include <stdbool.h>
    
    #include "../../util/headers/free.h"
    #include "./structs.h"
    #include "../../application-manager/headers/application.h"

    /**
     * @brief flags qui seront ajoutés lors d' linitialisation d'une fenêtre
    */
    #define SDLH_OBLIGATORY_FLAGS SDL_WINDOW_HIDDEN

    /**
     * @brief affiche la configuration de la fenêtre
     * @param windowConfiguration configuration de la fenêtre
    */
    void printWindowConfig(Window* windowConfiguration);

    /**
     * @brief créer une structure de fenêtre
     * @attention à appeller statiquement dans le programme
     * @param windowName nom de la fenêtre
     * @param windowWidth largeur de la fenêtre
     * @param windowHeight heuteur de la fenêtre
     * @param isResizable définis si la fenêtre peut  être redimensionné
     * @param backgroundR quantité de rouge composant la couleur de fond 
     * @param backgroundG quantité de vert composant la couleur de fond 
     * @param backgroundB quantité de bleue composant la couleur de fond 
     * @param flags les FLAG sdl de la fenêtre ou SDLH_DEFAULT par défaut SDLH_WINDOW_DEFAULT_FLAGS
     * @return la structure
    */
    Window newWindow(char* windowName,int windowWidth,int windowHeight,bool isResizable,int backgroundR,int backgroundG,int backgroundB,Uint32 flags);

    /**
     * @brief initialise la fenêtre de l'application
     * @param application
     * @return si l'initialisation a réussi
    */
    bool initApplicationWindow(App* application);

    /**
     * @brief lance et gère la boucle de la fenêtre
    */
    void manageWindow(App* application);
#endif