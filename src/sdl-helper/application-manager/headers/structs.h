#if !defined(APPLICATION_MGR_STRUCTS)
#define APPLICATION_MGR_STRUCTS
    #include "../../window-manager/headers/structs.h"
    #include "../../component-manager/headers/structs.h"
    #include "../../util/headers/structs.h"

    /**
     * @struct CallableList
     * @param toCallOnClose fonction à appeller à la fermeture de la fenêtre, doit renvoyer si la fenêtre peut être fermé reçois App*
     * @param manageEvent fonction à appeller pour la gestion d'un évenement reçois SDl_Event*
     * @param placeComponents fonction à appeller pour placer les composants reçois App*
    */
    typedef struct{
        bool (*toCallOnClose)(void*);
        void (*manageEvent)(void*);
        void (*placeComponents)(void*);
    }CallableList;

    /**
     * @struct App
     * @brief représente les données permettant la gestion d'une application
     * @param window les données sur la fenêtre
     * @param actionsList liste des fonctions à appeller pour la gestion d'évenements
     * @param components la liste des composants
     * @param componentsDescriptor le descripteur internes des composants
    */
    typedef struct{
        Window window;
        CallableList actionsList;
        ComponentDescriptor componentsDescriptor;
        bool exit;
        ToFree *components[SDLH_COMPONENT_MAX];
    }App;
#endif