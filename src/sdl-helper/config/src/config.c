#include <stdio.h>
#include "../headers/config.h"

/**
 * @brief affiche la configuration de la fenêtre
 * @param windowConfiguration
*/
void printWindowConfig(WindowConfig* windowConfiguration){
    printf(
        "\n<< Configuration de la fenêtre >>\n"
        "\n\t<< Largeur (%d) >>\n"
        "\n\t<< Hauteur (%d) >>\n"
        "\n\t<< Couleur fond : RGB(%d,%d,%d) >>",
        windowConfiguration->windowWidth,
        windowConfiguration->windowHeight,
        windowConfiguration->windowBackgroundColor.r,
        windowConfiguration->windowBackgroundColor.g,
        windowConfiguration->windowBackgroundColor.b
    );
}

void printApplicationConfig(App* application){
    printWindowConfig(&application->windowConfig);
}
