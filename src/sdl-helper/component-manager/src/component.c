#include "../headers/component.h"
#include "../headers/component-creator.h"
#include <stdlib.h>

/**
 * @brief met dans compononentDescriptor les valeurs de toChangeAfter
 * @param componentDescriptor la composant à remplir
 * @param toChangeAfter le composant à placer dans componentDescriptor
*/
void putComponentDescriptorIn(ComponentDescriptor* componentDescriptor,ComponentDescriptor toChangeAfter){
    componentDescriptor->type = toChangeAfter.type;
    componentDescriptor->componentData = toChangeAfter.componentData;
}

/**
 * @brief charge un composant
 * @param componentDescriptor le descritpeur du composant à charger
 * @return l'adresse du composant chargé ou NULL
*/
void* loadComponentElement(ComponentDescriptor* componentDescriptor){
    switch(componentDescriptor->type){
        case IMAGE: return loadImage(componentDescriptor->componentData.path); break;
    }

    return NULL;
}

Component* loadComponent(App* application,ComponentDescriptor toChangeAfter){
    Component* component = NULL;

    if(application->componentsDescriptor.type != NONE){
        component = malloc(sizeof(Component) );

        if(component != NULL){
            component->component = loadComponentElement(&application->componentsDescriptor);

            // libération de l'allocation en cas d'échec de récupération sinon incrémentation du nombre de composants chargés avant appel à l'ajout dans l'application
            if(component->component == NULL){
                free(component);

                component = NULL;
            }
            else{
                component->type = application->componentsDescriptor.type;
                component->rect.x = application->componentsDescriptor.componentTmpRect.x;
                component->rect.y = application->componentsDescriptor.componentTmpRect.y;
                component->rect.w = application->componentsDescriptor.componentTmpRect.w;
                component->rect.h = application->componentsDescriptor.componentTmpRect.h;

                application->componentsDescriptor.countOfComponentToLoad++; 
            }       
        }
    }

    if(toChangeAfter.type != NONE) putComponentDescriptorIn(&application->componentsDescriptor,toChangeAfter);

    return component;
};