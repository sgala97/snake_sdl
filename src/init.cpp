#include "init.hpp"

bool init(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "Error SDL" << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

void close()
{
    SDL_Quit();
}


