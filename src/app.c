#include "./sdl-helper/application-manager/headers/application.h"
#include "./sdl-helper/window-manager/headers/window.h"
#include "./sdl-helper/component-manager/headers/component.h"
#include "./sdl-helper/config/headers/config.h"

#include <stdio.h>

typedef enum{HEIMDALL_IMAGE}MyComponentsIds;

/**
 * application d'exemple
*/
int main(int argc,char* argv[]){
    
    App application;

    // initialisation de la sdl
    if(!initSDL(SDLH_DEFAULT,SDLH_DEFAULT) ) return 1;
    
    // création de l'application
    newApplication(
        &application,
        newWindow("Example application",900,400,true,255,255,255,SDLH_DEFAULT),
        newCallableList(NULL,NULL,NULL)
    );

    // initialisation
    if(!initApplication(&application) ){
        quitSDL();

        return 1;
    }

    // création de la description du premier composant
    putComponentDescriptorIn(&application.componentsDescriptor,SDLH_COMPONENT_IMAGE("../resources/baby-groot.png",0,0,900,400,HEIMDALL_IMAGE,true) );

    // création des composants
    Component* components[] = {
        // loadLastComponent(&application,SDLH_COMPONENT_IMAGE("../resources/heimdall.jpg",200,200,200,100,HEIMDALL_IMAGE,false) ),
        loadLastComponent(&application,SDLH_COMPONENTD_NONE)
    };

    // ajout du premier composant avec un descripteur qui ne sera pas changé
    addComponentToApplication(&application,components);
    // lancement de l'application
    runApplication(&application);
    // fin et libération des ressources de l'application
    endApplication(&application);

    // libération des ressources de la sdl
    quitSDL();

    return 0;
}