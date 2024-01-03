#include "iostream"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "Game_screen.h"
#include "start.h"
#include "rps.h"

int main(int argc, char* argv[]) {

	rps RPS;
	RPS.init("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);

    while (RPS.running()) {
        RPS.handleEvents();
        RPS.update();
        RPS.render();
    }

    RPS.clean();

	return 0;
}