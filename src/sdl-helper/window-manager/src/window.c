#include "../headers/window.h"
#include "../../config/headers/config.h"
#include "../../application-manager/headers/application.h"

#include <stdio.h>
#include <string.h>

void printWindowConfig(Window* windowConfiguration){
    printf(
        "\n<< Configuration de la fenêtre >>\n"
        "\n\t<< Nom de la fenêtre (%s) >>\n"
        "\n\t<< Largeur (%d) >>\n"
        "\n\t<< Hauteur (%d) >>\n"
        "\n\t<< Couleur fond RGB(%d,%d,%d) >>\n"
        "\n\t<< Redimensionnable (%s) >>\n",
        windowConfiguration->windowName,
        windowConfiguration->windowWidth,
        windowConfiguration->windowHeight,
        windowConfiguration->windowBackgroundColor.r,
        windowConfiguration->windowBackgroundColor.g,
        windowConfiguration->windowBackgroundColor.b,
        windowConfiguration->isResizable ? "oui" : "non"
    );
}

Window newWindow(char* windowName,int windowWidth,int windowHeight,bool isResizable,int backgroundR,int backgroundG,int backgroundB,Uint32 flags){
    Window window = {
        .windowWidth = windowWidth,
        .windowHeight = windowHeight,
        .isResizable = isResizable,
        .windowBackgroundColor = {
            .r = backgroundR,
            .g = backgroundG,
            .b = backgroundB
        },
        .centered = true,
        .flags = flags == SDLH_DEFAULT ?  SDLH_WINDOW_DEFAULT_FLAGS | SDLH_OBLIGATORY_FLAGS : flags | SDLH_OBLIGATORY_FLAGS,
        .window = NULL
    };

    strncpy(window.windowName,windowName,sizeof(char) * WINDOW_TITLE_MAX_LENGTH - 1);

    return window;
}

bool initApplicationWindow(App* application){
    Window* applicationWindow = &application->window;

    // création de la fenêtre

    SDL_Window* window = SDL_CreateWindow(
        applicationWindow->windowName,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        applicationWindow->windowWidth,
        applicationWindow->windowHeight,
        applicationWindow->flags
    );  

    if(window == NULL) return false;

    // création du renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window,0,0);

    if(renderer == NULL){
        SDL_DestroyWindow(window);

        return false;
    }

    applicationWindow->window = window;

    return true;
}

void manageWindow(App* application){
    
    Window* windowManager = &application->window;

    SDL_ShowWindow(windowManager->window);

    SDL_Renderer* renderer = SDL_GetRenderer(windowManager->window);

    SDL_Event eventManager;

    // boucle de la fenêtre
    while(!application->exit){
        // gestion du fond
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(
            renderer,
            windowManager->windowBackgroundColor.r,
            windowManager->windowBackgroundColor.g,
            windowManager->windowBackgroundColor.b,
            255
        );

        SDL_RenderPresent(renderer);

        SDL_WaitEvent(&eventManager);

        // gestion des évenements et appel de fonctions correspondantes
        switch(eventManager.type){
            case SDL_QUIT:
                application->exit = application->actionsList.toCallOnClose != NULL ? application->actionsList.toCallOnClose(application) : true;
            ; break;

            default:
                // gestion des évenements par défaut
                if(application->actionsList.manageEvent != NULL) application->actionsList.manageEvent(&eventManager);
            ;
        }
    }
}