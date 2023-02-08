#include "../../config/headers/config.h"
#include "../../window-manager/headers/window.h"
#include "../../util/headers/free.h"
#include "../../config/headers/config.h"
#include "../headers/application.h"

#include <stdarg.h>
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
    application->components[IMAGE] = NULL;
    application->componentsDescriptor.countOfComponentToLoad = 0;

    return application;
}

App* cloneApplication(App* toClone,App* newApp){
    return (App*) memcpy(newApp,toClone,sizeof(App) );   
}

CallableList newCallableList(bool (*toCallOnClose)(void*),void (*manageEvent)(void*) ){
    return (CallableList) {
        .toCallOnClose = toCallOnClose,
        .manageEvent = manageEvent
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
    freeList(application->components[IMAGE],freeSDLImage);
}

void addComponentToApplication(App* application,...){
    va_list argsList;

    va_start(argsList,application);

    // ajout des composants
    for(;application->componentsDescriptor.countOfComponentToLoad > 0; application->componentsDescriptor.countOfComponentToLoad--){
        Component* component = va_arg(argsList,Component*);

        if(component == NULL || component->type == NONE || component->type == COMPONENT_MAX) continue;

        application->components[component->type] = addElementToFree(application->components[component->type],component);
    }

    va_end(argsList);
}