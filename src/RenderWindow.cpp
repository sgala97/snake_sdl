#include "RenderWindow.hpp"

RenderWindow::RenderWindow(char* title, int height, int width, int flags) 
    : window(NULL), render(NULL)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, width, height, flags ); 
    if (window != NULL)
    {
        render = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    }
}

bool RenderWindow::isCreated()
{
    if(window == NULL || render == NULL)
    {
        return false;
    }
    return true;
}

SDL_Window* RenderWindow::getWindow(){
    return window;
}

void RenderWindow::update()
{
    SDL_RenderPresent(render);
}
void RenderWindow::clear()
{
    SDL_RenderClear(render);
}
void RenderWindow::copyTexture(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* desRect)
{
    SDL_RenderCopy( render, texture,  srcRect, desRect);
}

SDL_Renderer* RenderWindow::getRender(){
    return render;
}

RenderWindow::~RenderWindow()
{
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
}
