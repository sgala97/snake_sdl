#ifndef SNAKE
#define SNAKE
#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "coin.hpp"

enum Direction{
    up, down, right, left
};

class Snake{
    private:
        std::vector<SDL_Rect> body;
        Direction direction;
        int width, height, unit;

    public:
        Snake(int width, int height, int unit, int size);
        void move();
        void draw(SDL_Renderer* render);
        void grow();
        void setMove(Direction direction);
        void printArray();
        bool dead();
        bool isGettingCoin(Coin &coin);
};

#endif

