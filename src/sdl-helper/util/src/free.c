#include "../headers/free.h"
#include "../../component-manager/headers/component.h"
#include <SDL2/SDL.h>
#include <stdlib.h>

struct ToFree* addElementToFree(struct ToFree* baseList,void* toFreeAfter){
    struct ToFree* elementToFree = malloc(sizeof(struct ToFree) );

    if(elementToFree != NULL){
        elementToFree->toFree = toFreeAfter;
        elementToFree->nextElementToFree = baseList;
        
        return elementToFree;
    }

    return baseList;
}

void freeList(struct ToFree* toFree,void (*freeCallable)(void*) ){
    if(toFree != NULL){
        freeList(toFree->nextElementToFree,freeCallable);

        if(freeCallable != NULL) 
            freeCallable(toFree->toFree);
        else
            free(toFree->toFree);
        
        free(toFree);
    }
}

void freeSDLImage(void* imageData){
    SDL_FreeSurface((SDL_Surface*) imageData);
}