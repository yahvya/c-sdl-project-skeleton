#include "../../config/headers/config.h"
#include "../../window-manager/headers/window.h"
#include "../../util/headers/free.h"
#include "../../config/headers/config.h"
#include "../headers/application.h"

#include <string.h>

bool initSDL(Uint32 sdlFlags,Uint32 sdlImageFlags){
    bool success = SDL_Init(sdlFlags == SDLH_DEFAULT ? SDLH_SDL_DEFAULT_FLAGS : sdlFlags) == 0;

    if(success){
        success = IMG_Init(sdlImageFlags == SDLH_DEFAULT ? SDLH_SDLIMAGE_DEFAULT_FLAGS : sdlImageFlags);

        if(!success) SDL_Quit();
    }

    return success;
}

void quitSDL(){
    SDL_Quit();
    IMG_Quit();
}

App* printApplicationConfig(App* application){
    printWindowConfig(&application->window);

    return application;
}

App* newApplication(App* application,Window applicationWindow,CallableList applicationActionList){
    application->window = applicationWindow;
    application->actionsList = applicationActionList;
    application->exit = false;
    application->components[SDLH_IMAGE] = NULL;
    application->componentsDescriptor.countOfComponentToLoad = 0;
    application->componentsDescriptor.type = SDLH_NONE;
    application->componentsDescriptor.componentId = SDLH_NOID;

    return application;
}

App* cloneApplication(App* toClone,App* newApp){
    return (App*) memcpy(newApp,toClone,sizeof(App) );   
}

CallableList newCallableList(bool (*toCallOnClose)(void*),void (*manageEvent)(void*),void (*placeComponents)(void*) ){
    return (CallableList) {
        .toCallOnClose = toCallOnClose,
        .manageEvent = manageEvent,
        .placeComponents = placeComponents
    };
}

bool initApplication(App* application){
    return initApplicationWindow(application);
}

bool runApplication(App* application){
    manageWindow(application);
    
    return true;
}

void endApplication(App* application){
    freeList(application->components[SDLH_IMAGE],freeSDLImage);
}

void addComponentToApplication(App* application,Component** components){
    for(;application->componentsDescriptor.countOfComponentToLoad > 0; application->componentsDescriptor.countOfComponentToLoad--){
        Component* component = components[application->componentsDescriptor.countOfComponentToLoad - 1];

        if(component == NULL || component->type == SDLH_NONE || component->type == SDLH_COMPONENT_MAX) continue;

        application->components[component->type] = addElementToFree(application->components[component->type],component);
    }
}