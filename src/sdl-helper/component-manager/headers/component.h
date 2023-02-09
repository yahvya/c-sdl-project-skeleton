#if !defined(SDLH_COMPONENT_H)
#define SDLH_COMPONENT_H
    #include "./structs.h"
    #include "../../application-manager/headers/application.h"

    /**
     * @brief crée le dernier composant décris dans le descripteur de l'application
     * @attention this function if the component is loaded successfuly increment the internal counter of the descriptor
     * @param application l'application
     * @param toChangeAfter si type non NONE alors les champs utiles seront mis à jour dans le descripteur interne de l'application
     * @returns le composant ou NULL si échec de création
    */
    Component* loadLastComponent(App* application,ComponentDescriptor toChangeAfter);

    /**
     * @brief met dans compononentDescriptor les valeurs de toChangeAfter
     * @param componentDescriptor la composant à remplir
     * @param toChangeAfter le composant à placer dans componentDescriptor
    */
    void putComponentDescriptorIn(ComponentDescriptor* componentDescriptor,ComponentDescriptor toChangeAfter);
#endif