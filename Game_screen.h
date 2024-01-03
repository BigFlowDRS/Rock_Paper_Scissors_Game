#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "iostream"
#include "string"
#include "screen.h"
#include "text.h"
#include "logic.h"

class Gameplay_een : public Screen {
public:
    bool is_running;

    Gameplay_een(SDL_Renderer* renderer);
    ~Gameplay_een();

    bool close_win()override;

    bool svch_screen()override;

    void handleEvents() override;

    void update() override;

    int ismouseoverbutton(int x, int y);

    int info()override;


    void render(SDL_Renderer* renderer)override;

private:
    bool swi_scr = false;
    int round = 5;
    int player_score = 0, com_score = 0, player_cho, com_cho;
    bool process_moving=true;


    SDL_Texture* backgroundImage;
    //Text* text_plyr,*text_com;
    //Text* round_res_text;
    SDL_Texture* but1tex, * but2tex, * but3tex, *play_move, *com_move;
    SDL_Rect b1, b2, b3, mp,mc;
    std::string round_result = " ";
};