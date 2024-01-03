#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "iostream"
#include "screen.h"

class StartScreen : public Screen {
public:

    StartScreen(SDL_Renderer* renderer);
    ~StartScreen();
    bool close_win()override;
    void handleEvents()override;

    void update()override;

    void render(SDL_Renderer* renderer)override;
    bool svch_screen()override;

    bool ismouseoverbutton(int x, int y);
    void buttonclick();
    int info()override;
private:
    bool is_running;

    bool swi_scr = false;

    SDL_Texture* backgroundImage, * button;
    //SDL_Rect bg;
    SDL_Rect buton;
};