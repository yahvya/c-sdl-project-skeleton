#include "../headers/window-component-manager.h"
#include <SDL2/SDL.h>

/**
 * @brief affiche la liste d'image sur le renderer
 * @param application l'application
 * @param images la liste des images
 * @param renderer le renderer sur lequel affiché les images
*/
void placeImages(App* application,ToFree* images,SDL_Renderer* renderer){
    if(images != NULL){
        Component* imageComponent = (Component*) images->toFree;

        if(imageComponent->preserveScale){
            // récupération de la taille de la fenêtre
            int windowWidth;
            int windowHeight;

            SDL_GetWindowSize(application->window.window,&windowWidth,&windowHeight);

            // calcul de la nouvelle taille de l'image
            SDL_Rect newRect = {
                .x = imageComponent->rect.x,
                .y = imageComponent->rect.y,
                .w = (windowWidth - application->window.windowWidth) + imageComponent->rect.w,
                .h = (windowHeight - application->window.windowHeight) + imageComponent->rect.h
            };

            SDL_RenderCopy(renderer,(SDL_Texture*) imageComponent->component,NULL,&newRect);
        }
        else SDL_RenderCopy(renderer,(SDL_Texture*) imageComponent->component,NULL,&imageComponent->rect);

        placeImages(application,images->nextElementToFree,renderer);
    }
}

void placeComponents(App* application){
    placeImages(application,application->components[SDLH_IMAGE],SDL_GetRenderer(application->window.window) );
}