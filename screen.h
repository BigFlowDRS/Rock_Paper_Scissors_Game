#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "iostream"

class Screen {
public:
    virtual bool close_win() = 0;
    virtual void handleEvents() = 0;
    virtual void update() = 0;
    virtual void render(SDL_Renderer* renderer) = 0;
    //virtual ~Screen() {}
    virtual bool svch_screen() = 0;
    virtual int info() = 0;

private:

};
