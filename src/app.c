#include "./sdl-helper/config/headers/config.h"

int main(int argc,char* argv[]){
    App application = APPLICATION_DEFAULT_CONFIG;

    printApplicationConfig(&application);

    return 0;
}