#include "SDL.h"
#include "SDL_image.h"
#include "iostream"
#include "start.h"
#include "Game_screen.h"
#include "rps.h"
#include "SDL_ttf.h"
#include "score_screen.h"

rps::rps() : window(nullptr), renderer(nullptr), currentScreen(nullptr), is_running(true), sr(0) {}

void rps::init(const char* title, int x, int y, int width, int height, Uint32 flags) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(title, x, y, width, height, flags);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (TTF_Init() == -1) {
        std:: cout << "failed to ttf" << std::endl;
    }
    currentScreen = new StartScreen(renderer);
    sr = 0;
    is_running = true;
}

void rps::handleEvents() {
    currentScreen->handleEvents();
    is_running = currentScreen->close_win();


    if (currentScreen->svch_screen()) {
        sr++;
        sr %= 3;
        switchScreens();
        std::cout << "switsh_screen_detect" << std::endl;
    }

}

void rps::update() {
    currentScreen->update();
}

void rps::render() {
    SDL_RenderClear(renderer);

    currentScreen->render(renderer);

    SDL_RenderPresent(renderer);
}

void rps::clean() {
    delete currentScreen;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

bool rps::running() const {
    return is_running;
}

void rps::switchScreens() {
    
    std::cout << "in_SS" << std::endl;


    if (sr == 1) {
        std::cout << "cur_to_gp" << std::endl;
        delete currentScreen;
        currentScreen = nullptr;
        currentScreen = new Gameplay_een(renderer);
    }
    else if (sr == 2) {
        int i = currentScreen->info();
        delete currentScreen;
        currentScreen = nullptr;
        currentScreen = new ScoreScreen(renderer,i);
    }
    else if (sr == 0) {
        delete currentScreen;
        currentScreen = nullptr;
        currentScreen = new StartScreen(renderer);
    }
    else {
        std::cout << "sr_logic_error" << std::endl;
    }
}