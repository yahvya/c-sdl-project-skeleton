#include "./sdl-helper/application-manager/headers/application.h"
#include "./sdl-helper/window-manager/headers/window.h"
#include "./sdl-helper/component-manager/headers/component.h"
#include "./sdl-helper/config/headers/config.h"

#include <stdio.h>

/**
 * exemple application
*/
int main(int argc,char* argv[]){
    if(!initSDL(SDLH_DEFAULT,SDLH_DEFAULT) ) return 1;

    App application;
    
    newApplication(
        &application,
        newWindow("Example application",900,400,true,30,30,30,SDLH_DEFAULT),
        newCallableList(NULL,NULL)
    );

    if(!initApplication(&application) ) return 1;

    application.componentsDescriptor.type = IMAGE;
    application.componentsDescriptor.componentData.path = "../resources/heimdall.jpg";
    application.componentsDescriptor.componentTmpRect.x = 0;
    application.componentsDescriptor.componentTmpRect.y = 0;
    application.componentsDescriptor.componentTmpRect.w = 200;
    application.componentsDescriptor.componentTmpRect.h = 200;

    addComponentToApplication(&application,loadComponent(&application,SDLH_COMPONENTD_NONE) );

    runApplication(&application);
    endApplication(&application);

    quitSDL();

    return 0;
}