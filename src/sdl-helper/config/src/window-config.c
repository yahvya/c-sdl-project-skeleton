#include <stdio.h>
#include <string.h>
#include "../headers/config.h"

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

Window newWindow(char windowName[WINDOW_TITLE_MAX_LENGTH],int windowWidth,int windowHeight,bool isResizable,int backgroundR,int backgroundG,int backgroundB){
    Window window = {
        .windowWidth = windowWidth,
        .windowHeight = windowHeight,
        .isResizable = isResizable,
        .windowBackgroundColor = {
            .r = backgroundR,
            .g = backgroundG,
            .b = backgroundB
        },
        .centered = true
    };

    strncpy(window.windowName,windowName,sizeof(char) * WINDOW_TITLE_MAX_LENGTH - 1);

    return window;
}