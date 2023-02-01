#include "coin.hpp"
Coin::Coin(int unit, int width, int height)
{
    srand(time(NULL));
    this->height = height;
    this->unit = unit;
    this->width = width;
}

void Coin::draw(SDL_Renderer* render)
{
    for(auto it = coins.begin(); it != coins.end(); it++)
    {
        SDL_SetRenderDrawColor( render, 0x46, 0x87, 0x8f, 0xFF );
        SDL_RenderFillRect(render, &(*it));
    }
}

void Coin::generate()
{
    if(coins.size() < 5)
    {
        bool n = true;
        SDL_Rect coin;
        while(n)
        {
            coin.h = unit;
            coin.w = unit;
            coin.x = (rand() % (width/unit))* unit;
            coin.y = (rand() % (height/unit))* unit;
            if(!isCoin(coin.x, coin.y)) n = false;
        }
        coins.push_back(coin);
    }
}

bool Coin::isGetCoin(int x, int y)
{
    for(auto it = coins.begin(); it != coins.end(); it++)
    {
        if(it->x == x && it->y == y) 
        {
            coins.erase(it);
            return true;
        }
    }
    return false;
}

bool Coin::isCoin(int x, int y)
{
    for(auto it = coins.begin(); it != coins.end(); it++)
    {
        if(it->x == x && it->y == y) return true;
    }
    return false;
}