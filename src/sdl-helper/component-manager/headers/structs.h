#if !defined(SDLH_COMPONENTSMGR_STRUCT)
#define SDLH_COMPONENTSMGR_STRUCT

    #include <SDL2/SDL.h>

    /**
     * @brief représente un descritpeur de type NONE
    */
    #define SDLH_COMPONENTD_NONE (ComponentDescriptor){.type = NONE}

    /**
     * @brief représente un descripteur d'image
     * @param imagePath chemin de l'image
    */
    #define SDHL_COMPONENT_IMAGE(imagePath,componentX,componentY,width,height) (ComponentDescriptor){\
            .type = IMAGE,\
            .componentData.path = imagePath,\
            .componentTmpRect = {.x = componentX,.y = componentY,.w = width,.h = height}\
        }

    /**
     * @enum ComponentType
     * @param NONE pas de composant
     * @param IMAGE représente une image
    */
    typedef enum{
        NONE,
        IMAGE = 0,
        COMPONENT_MAX = 1
    }ComponentType;

    /**
     * @struct Component
     * @param type type du composant
     * @param component le composant
    */
    typedef struct{
        ComponentType type;
        void* component;
        SDL_Rect rect;
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
    */
    typedef struct{
        ComponentType type;
        ComponentDataUnion componentData;
        SDL_Rect componentTmpRect;
        int countOfComponentToLoad;
    }ComponentDescriptor;
#endif