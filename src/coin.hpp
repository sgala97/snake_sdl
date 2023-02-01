#ifndef COIN
#define COIN
#pragma once

#include <vector>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>

class Coin{
    private:
        std::vector<SDL_Rect> coins;
        int unit, width, height;
    
    public:
        Coin(int unit, int width, int height);
        void draw(SDL_Renderer* render);
        void generate();
        bool isGetCoin(int x, int y);
        bool isCoin(int x, int y);
};

#endif