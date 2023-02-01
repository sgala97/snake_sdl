#include <iostream>

#include <SDL2/SDL.h>

#include "init.hpp"
#include "RenderWindow.hpp"
#include "funciones.hpp"
#include "snake.hpp"
#include "coin.hpp"

// screen size
const int WIDTH = 1000; 
const int HEIGHT = 1000;  

int main(int argc, char* args[]){
    if (!init()) return 1;
    RenderWindow window("titulo", HEIGHT, WIDTH, SDL_WINDOW_SHOWN);
    if(!window.isCreated())
    {
        std::cout << "Error SDL" << SDL_GetError << std::endl;
        return 1;
    }
    SDL_Event *event = new SDL_Event();
    bool quit = false;
    bool pooled;

    Snake snake(WIDTH, HEIGHT, 20, 12);

    Coin coin(20, WIDTH, HEIGHT);
    int count = 1;

    int countSpeed = 1;
    int speed = 80;
    while(!quit){
        pooled = false;
        SDL_Delay(speed);
        while(SDL_PollEvent(event) != NULL){
            if(event->type == SDL_QUIT)
            {
                quit = true;
            }
            else if( event->type == SDL_KEYDOWN && !pooled)
            {
                //Select surfaces based on key press
                switch( event->key.keysym.sym )
                {
                    case SDLK_UP:
                        snake.setMove(up);
                        pooled = true;
                    break;

                    case SDLK_DOWN:
                        snake.setMove(down);
                        pooled = true;
                    break;

                    case SDLK_LEFT:
                        snake.setMove(left);
                        pooled = true;
                    break;

                    case SDLK_RIGHT:
                        snake.setMove(right);
                        pooled = true;
                    break;

                    default:
                    break;
                }
            }
        }
        if(count == 0)
        {
            coin.generate();
        }
        count = (count + 1) % 30;

        if(countSpeed == 0)
        {
            if(speed > 10) speed = speed - 5;
            countSpeed++;
        }
        SDL_SetRenderDrawColor( window.getRender(), 0x33, 0x2C, 0x50, 0x00 );
        window.clear();
        if(snake.isGettingCoin(coin)) 
        {
            countSpeed = (countSpeed + 1) % 6;

        }
        else
        {
            snake.move();
        }

        if(snake.dead()) break;
        snake.draw(window.getRender());
        coin.draw(window.getRender());
        window.update();
    }
    close();
    return 0;
}
