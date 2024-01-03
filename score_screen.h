#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "iostream"
#include "screen.h"
#include "string"

class ScoreScreen : public Screen {
private:
    std::string announce;
    SDL_Texture* backgroundImage;
    SDL_Texture* quit_button, * replay_button;
    SDL_Rect qb, rb;
    bool is_running, swi_scr = false;

public:
	ScoreScreen(SDL_Renderer* renderer,int info);
	~ScoreScreen();
    bool close_win()override;

    int info()override;


    bool svch_screen()override;

    void handleEvents() override;

    void update() override;

    void render(SDL_Renderer* renderer)override;

    int ismouseoverbutton(int x, int y);
};
