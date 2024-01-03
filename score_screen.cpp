#include "SDL.h"
#include "SDL_image.h"
#include "iostream"
#include "score_screen.h"
#include "text.h"

ScoreScreen::ScoreScreen(SDL_Renderer* renderer,int info) {
	is_running = true;

	if (info == 1) {
		announce = "Player Wins";
	}
	else if (info == 2) {
		announce = "DRAW";
	}
	else {
		announce = "Computer Wins";
	}

	SDL_Surface* bg_img = IMG_Load("res/bg.png");
	backgroundImage = SDL_CreateTextureFromSurface(renderer, bg_img);

	SDL_Surface* qb_img = IMG_Load("res/quit_button.png");
	SDL_Surface* rp_img = IMG_Load("res/home_button.png");

	quit_button = SDL_CreateTextureFromSurface(renderer, qb_img);
	replay_button = SDL_CreateTextureFromSurface(renderer, rp_img);

	SDL_FreeSurface(bg_img);
	SDL_FreeSurface(qb_img);
	SDL_FreeSurface(rp_img);

	
	qb.w = 242*1.5;
	qb.h = 64*1.5;
	qb.x = 852-qb.w/2;
	qb.y = 500;

	rb.w = 242 * 1.5;
	rb.h = 64 *1.5;
	rb.x = 426-rb.w/2;
	rb.y = 500;
}

ScoreScreen::~ScoreScreen() {
	SDL_DestroyTexture(backgroundImage);
	SDL_DestroyTexture(quit_button);
	SDL_DestroyTexture(replay_button);
}

bool ScoreScreen::svch_screen() {
	return swi_scr;
}

int ScoreScreen::info() {
	return 0;
	
}

bool ScoreScreen::close_win() {
	return is_running;
}

int ScoreScreen::ismouseoverbutton(int x, int y) {
	if (x >= qb.x && x <= qb.x + qb.w && y >= qb.y && y <= qb.y + qb.h) {
		return 1;
	}
	else if (x >= rb.x && x <= rb.x + rb.w && y >= rb.y && y <= rb.y + rb.h) {
		return 2;
	}

	return 0;
}

void ScoreScreen::handleEvents() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			is_running = false;
			break;
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN) {
			std::cout << "Click_3" << std::endl;

			int mouseX, mouseY;
			SDL_GetMouseState(&mouseX, &mouseY);

			if (ismouseoverbutton(mouseX, mouseY) == 1) {
				std::cout << "click on quit button" << std::endl;
				is_running = false;
				break;

			}
			else if (ismouseoverbutton(mouseX, mouseY) == 2) {
				swi_scr = true;
				break;
			}
		}
	}
}

void ScoreScreen::update() {

}

void ScoreScreen::render(SDL_Renderer* renderer) {
	Text result(renderer, "res/BRITANIC.TTF", 150, announce, { 236, 143, 94,255 });

	SDL_RenderCopy(renderer, backgroundImage, NULL, NULL);

	result.display(-1,100,renderer);
	SDL_RenderCopy(renderer, replay_button, NULL, &rb);
	SDL_RenderCopy(renderer, quit_button, NULL, &qb);
}