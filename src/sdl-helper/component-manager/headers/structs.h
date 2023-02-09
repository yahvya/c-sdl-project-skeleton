#if !defined(SDLH_COMPONENTSMGR_STRUCT)
#define SDLH_COMPONENTSMGR_STRUCT

    #include <SDL2/SDL.h>
    #include <stdbool.h>

    /**
     * @brief représente un composant sans id
    */
    #define SDLH_NOID -1 

    /**
     * @brief représente un descritpeur de type NONE
    */
    #define SDLH_COMPONENTD_NONE (ComponentDescriptor){.type = SDLH_NONE}

    /**
     * @brief représente un descripteur d'image
     * @param imagePath chemin de l'image
     * @param componentX position x de l'image
     * @param componentY position y de l'image
     * @param width largeur de l'image
     * @param height hauteur de l'image
     * @param componentGivenId l'id à affecter au composant ou SDLH_NOID
     * @param imagePreserveScale true si l'image se redimensionne avec l'écran
    */
    #define SDLH_COMPONENT_IMAGE(imagePath,componentX,componentY,width,height,componentGivenId,imagePreserveScale) (ComponentDescriptor){\
            .type = SDLH_IMAGE,\
            .componentId = componentGivenId,\
            .componentData.path = imagePath,\
            .componentTmpRect = {.x = componentX,.y = componentY,.w = width,.h = height},\
            .preserveScale = imagePreserveScale\
        }

    /**
     * @enum ComponentType
     * @param NONE pas de composant
     * @param IMAGE représente une image
    */
    typedef enum{
        SDLH_NONE = -1,
        SDLH_IMAGE = 0,
        SDLH_COMPONENT_MAX = 1
    }ComponentType;

    /**
     * @struct Component
     * @param type type du composant
     * @param component le composant
     * @param componentId id du composant donné par l'utilisateur
     * @param preserveScale défini si l'élement conserve l'échelle au redimensionnement de la fenêtre
    */
    typedef struct{
        ComponentType type;
        void* component;
        SDL_Rect rect;
        int componentId;
        bool preserveScale;
    }Component;

    typedef union{
        char* path;
    }ComponentDataUnion;

    /**
     * @struct ComponentDescriptor
     * @brief structure réutilisable après fonction loadComponent
     * @param type type du composant
     * @param componentData la donnée représentant ce qu'il y aura à charger
     * @param componentTmpRect dimensions et positions du composant
     * @param countOfComponentToLoad paramètres à initiliaser à 0
     * @param componentId un identifiant donné par l'utilisateur au composant 
     * @param preserveScale défini si l'élement conserve l'échelle au redimensionnement de la fenêtre
    */
    typedef struct{
        ComponentType type;
        ComponentDataUnion componentData;
        SDL_Rect componentTmpRect;
        int countOfComponentToLoad;
        int componentId;
        bool preserveScale;
    }ComponentDescriptor;
#endif