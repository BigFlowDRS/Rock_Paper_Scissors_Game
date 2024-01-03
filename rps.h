#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "iostream"
#include "start.h"
#include "Game_screen.h"

class rps {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    Screen* currentScreen;
    bool is_running;


public:
    int sr;
    rps();

    void init(const char* title, int x, int y, int width, int height, Uint32 flags);

    void handleEvents();

    void update();

    void render();

    void clean();

    bool running() const;

    void switchScreens();
};
