#include "../headers/component.h"
#include "../headers/component-creator.h"
#include <stdlib.h>

void putComponentDescriptorIn(ComponentDescriptor* componentDescriptor,ComponentDescriptor toChangeAfter){
    componentDescriptor->type = toChangeAfter.type;
    componentDescriptor->preserveScale = toChangeAfter.preserveScale;
    componentDescriptor->componentData = toChangeAfter.componentData;
    componentDescriptor->componentTmpRect.x = toChangeAfter.componentTmpRect.x;
    componentDescriptor->componentTmpRect.y = toChangeAfter.componentTmpRect.y;
    componentDescriptor->componentTmpRect.w = toChangeAfter.componentTmpRect.w;
    componentDescriptor->componentTmpRect.h = toChangeAfter.componentTmpRect.h;
    componentDescriptor->componentId = toChangeAfter.componentId;
}

/**
 * @brief charge un composant
 * @param application l'application
 * @param componentDescriptor le descritpeur du composant à charger
 * @return l'adresse du composant chargé ou NULL
*/
void* loadComponentElement(App* application,ComponentDescriptor* componentDescriptor){
    switch(componentDescriptor->type){
        case SDLH_IMAGE: return loadImage(SDL_GetRenderer(application->window.window),componentDescriptor->componentData.path); break;

        default: return NULL;
    }
}

Component* loadLastComponent(App* application,ComponentDescriptor toChangeAfter){
    Component* component = NULL;

    if(application->componentsDescriptor.type != SDLH_NONE){
        component = malloc(sizeof(Component) );

        if(component != NULL){
            component->component = loadComponentElement(application,&application->componentsDescriptor);

            // libération de l'allocation en cas d'échec de récupération sinon incrémentation du nombre de composants chargés avant appel à l'ajout dans l'application
            if(component->component == NULL){
                free(component);

                component = NULL;
            }
            else{
                component->type = application->componentsDescriptor.type;
                component->componentId = application->componentsDescriptor.componentId;
                component->preserveScale = application->componentsDescriptor.preserveScale;
                component->rect.x = application->componentsDescriptor.componentTmpRect.x;
                component->rect.y = application->componentsDescriptor.componentTmpRect.y;
                component->rect.w = application->componentsDescriptor.componentTmpRect.w;
                component->rect.h = application->componentsDescriptor.componentTmpRect.h;

                application->componentsDescriptor.countOfComponentToLoad++;
            }       
        }
    }

    if(toChangeAfter.type != SDLH_NONE) putComponentDescriptorIn(&application->componentsDescriptor,toChangeAfter);

    return component;
};