INCLUDE(FindPkgConfig)                                                                                          
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)                                                            
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image >= 2.0.0)                                          
set(CMAKE_CXX_STANDARD 17)        
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

project(SdlHelper)

add_subdirectory(src/sdl-helper)

add_executable(app src/app.c)

target_link_libraries(app 
    SDL_HELPER_WINDOW_MANAGER
    SDL_HELPER_APPLICATION_MANAGER
    SDL_HELPER_COMPONENT_MANAGER
    SDL_HELPER_UTIL
    SDL_HELPER_WINDOW_MANAGER
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_LIBRARIES} 
    ${SDL2TTF_INCLUDE_DIRS}
    ${SDL2TTF_LIBRARIES}
    ${SDL2IMAGE_INCLUDE_DIRS}
    ${SDL2IMAGE_LIBRARIES}
)

    