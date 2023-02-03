cmake_minimum_required(VERSION 3.2)

add_subdirectory(src/sdl-helper)

add_executable(app src/app.c)

target_link_libraries(app 
    SDL_HELPER_CONFIG
    SDL_HELPER_WINDOW_MANAGER
    SDL_HELPER_APPLICATION_MANAGER
    ${SDL2_INCLUDE_DIRS}
    ${SDL2TTF_INCLUDE_DIRS}
    ${SDL2_LIBRARIES} 
    ${SDL2TTF_LIBRARIES}
    ${SDL2_LIBRARIES} 
    ${SDL2IMAGE_LIBRARIES}
)