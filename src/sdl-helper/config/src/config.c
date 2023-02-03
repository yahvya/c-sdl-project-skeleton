#include "../headers/config.h"

void printApplicationConfig(App* application){
    printWindowConfig(&application->window);
}

App newApplication(Window applicationWindow){
    return (App){
        .window = applicationWindow
    };
}