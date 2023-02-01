#include "snake.hpp"

Snake::Snake(int width, int height, int unit, int size){
    srand (time(NULL));
    direction = (Direction)(rand() % 4);
    this->width = width;
    this->height = height;
    this->unit = unit;

    SDL_Rect inicio;
    inicio.h = unit;
    inicio.w = unit;
    inicio.x = (rand() % (width/unit))* unit;
    inicio.y = (rand() % (height/unit))* unit;
    body.push_back(inicio);
    for(int i = 0; i < size-1; i++)
    {
        grow();
    }
}

void Snake::move(){
    SDL_Rect newBody = body.front();
    switch (direction)
    {
    case up:
        newBody.y =( height +((body[0].y - unit) % height)) % height;  
    break;
    
    case down:
        newBody.y =( height +((body[0].y + unit) % height)) % height;  
    break;

    case right:
        newBody.x =( width +((body[0].x + unit) % width)) % width;  
    break;

    case left:
        newBody.x =( width +((body[0].x - unit) % width)) % width;  
    break;

    default:
        break;
    }
    newBody.h = unit;
    newBody.w = unit;
    body.insert(body.begin(), newBody);
    body.pop_back();
}

void Snake::draw(SDL_Renderer* render)
{
    unsigned char color = 0x94;
    unsigned char color2 = 0xe3;
    unsigned char color3 = 0x45;
    for(auto it = body.begin(); it != body.end(); it++)
    {
        SDL_SetRenderDrawColor( render, color, color2, color3, 0xFF );
        SDL_RenderFillRect(render, &(*it));
        color3 += 10;
    }
}

void Snake::grow()
{
    SDL_Rect newBody = body.front();
    switch (direction)
    {
    case up:
        newBody.y =( height +((body[0].y - unit) % height)) % height;  
    break;
    
    case down:
        newBody.y =( height +((body[0].y + unit) % height)) % height;  
    break;

    case right:
        newBody.x =( width +((body[0].x + unit) % width)) % width;  
    break;

    case left:
        newBody.x =( width +((body[0].x - unit) % width)) % width;  
    break;

    default:
        break;
    }
    newBody.h = unit;
    newBody.w = unit;
    body.insert(body.begin(), newBody);
}

void Snake::setMove(Direction direction)
{
    switch (this->direction)
    {
        case up:
            if(direction!=down) this->direction = direction;
        break;
    
        case down:
            if(direction!=up) this->direction = direction;
        break;

        case right:
            if(direction!=left) this->direction = direction;
        break;

        case left:
            if(direction!=right) this->direction = direction;
        break;

        default:
        break;
    }
}

void Snake::printArray()
{
    for(auto it = body.begin(); it != body.end(); it++)
    {
        std::cout << it->x << " " << it->y << std::endl;
    }
}

bool Snake::dead()
{
    for(int i = 3; i<body.size(); i++)
    {
        if(body[0].x == body[i].x && body[0].y == body[i].y)
        {
            return true;
        }
    }
    return false;
}

bool Snake::isGettingCoin(Coin &coin)
{
    int x = body.front().x;
    int y = body.front().y;
    if(coin.isGetCoin(x, y))
    {
        grow();
        return true;
    }
    return false;
}