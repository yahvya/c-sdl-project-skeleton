#include "./sdl-helper/config/headers/config.h"

int main(int argc,char* argv[]){
    // App application = APPLICATION_DEFAULT_CONFIG;

    App application = newApplication(
        newWindow("Nouvelle fenêtre",200,400,true,30,30,30)
    );

    printApplicationConfig(&application);

    return 0;
}