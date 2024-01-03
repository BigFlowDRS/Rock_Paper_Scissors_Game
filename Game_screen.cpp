#include "SDL.h"
#include "SDL_image.h"
#include "iostream"
#include "Game_screen.h"
#include "text.h"

Gameplay_een::Gameplay_een(SDL_Renderer* renderer)
	: player_cho(0),com_cho(0)
{
	is_running = true;

	SDL_Surface* imageSurface = IMG_Load("res/bg.png");
	if (imageSurface) std::cout << "image done" << std::endl;
	backgroundImage = SDL_CreateTextureFromSurface(renderer, imageSurface);
	
	b1.w = 200;
	b1.h = 200;
	b1.x = 400-b1.w/2;
	b1.y = 500;
	
	b2.w = 200;
	b2.h = 200;
	b2.x = 640-b2.w/2;
	b2.y = 500;

	b3.w = 200;
	b3.h = 200;
	b3.x = 880-b3.w/2;
	b3.y = 500;

	SDL_Surface* button1sur = IMG_Load("res/rock_icon.png");
	but1tex = SDL_CreateTextureFromSurface(renderer, button1sur);

	SDL_Surface* button2sur = IMG_Load("res/paper_icon.png");
	but2tex = SDL_CreateTextureFromSurface(renderer, button2sur);

	SDL_Surface* button3sur = IMG_Load("res/scissors_icon.png");
	but3tex = SDL_CreateTextureFromSurface(renderer, button3sur);
	play_move = but1tex;
	com_move = but2tex;

	mp.x = -200;
	mp.y = 200;
	mp.w = 200;
	mp.h = 200;

	mc.x = 1280;
	mc.y = 200;
	mc.w = 200;
	mc.h = 200;
	


	SDL_FreeSurface(imageSurface);
	SDL_FreeSurface(button1sur);
	SDL_FreeSurface(button2sur);
	SDL_FreeSurface(button3sur);
}

Gameplay_een::~Gameplay_een() {
	TTF_Quit();
    SDL_DestroyTexture(backgroundImage);
	
	SDL_DestroyTexture(but1tex);
	SDL_DestroyTexture(but2tex);
	SDL_DestroyTexture(but3tex);
	SDL_DestroyTexture(play_move);
	SDL_DestroyTexture(com_move);
}

int Gameplay_een::info() {
	if (player_score > com_score) {
		return 1;
	}
	else if (player_score == com_score) {
		return 2;
	}
	else {
		return 3;
	}
}

int Gameplay_een::ismouseoverbutton(int x, int y) {
	if (x >= b1.x && x <= b1.x + b1.w && y >= b1.y && y <= b1.y + b1.h) {
		return 1;
	}else if (x >= b2.x && x <= b2.x + b2.w && y >= b2.y && y <= b2.y + b2.h) {
		return 2;
	}else if (x >= b3.x && x <= b3.x + b3.w && y >= b3.y && y <= b3.y + b3.h) {
		return 3;
	}
	return 0;
}

bool Gameplay_een::svch_screen() {
	return swi_scr;
}

bool Gameplay_een::close_win() {
	return is_running;
}

void Gameplay_een::handleEvents(){
	if (round == 0) {
		swi_scr = true;
	}
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			is_running = false;
			break;
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN && player_cho == 0) {
			std::cout << "Click_2" << std::endl;

			int mouseX, mouseY;
			SDL_GetMouseState(&mouseX, &mouseY);

			player_cho = ismouseoverbutton(mouseX, mouseY);
			if (player_cho != 0 && !process_moving) {
				mp.x = 0 - mp.w;
				mc.x = 1280;
				process_moving = true;
				round_result = "  ";
				round--;
			}
			break;
		}
	}
}

void Gameplay_een::update(){
	if (player_cho != 0 && process_moving) {
		std::cout << "in_update_1" << std::endl;

		logic game_log;
		com_cho = game_log.com_choice();
		if (player_cho == 1) play_move = but1tex;
		else if (player_cho == 2) play_move = but2tex;
		else play_move = but3tex;

		if (com_cho == 1) com_move = but1tex;
		else if (com_cho == 2) com_move = but2tex;
		else com_move = but3tex;

		process_moving = false;

	}
	else if (player_cho != 0) {
		mp.x += 16;
		mc.x -= 16;
	}
	else if (player_cho == 0 && !process_moving) {
		mp.x -= 16;
		mc.x += 16;
	}
	
	if (mp.x >= 300 && mc.x <= 1280 + mc.w - 300) {
		std::cout << "in_update_2" << std::endl;

		logic game_log;
		int game_res = game_log.round(com_cho, player_cho, com_score, player_score);
		if (game_res == 0) round_result = "DRAW";
		else if (game_res == 1) round_result = "Player Win";
		else round_result = "Computer Win";
		player_cho = 0;
		mp.x++;
		
	}
	if (mp.x + mp.w < 0 && mc.x > 1280 && !process_moving) {
		mp.x = 0-mp.w;
		mc.x = 1280;
		std::cout << "in_update_3" << std::endl;

		process_moving = true;
		round_result = "  ";
		round--;
	}	 
	if (mp.x == 297) {
		SDL_Delay(1000);
	}
}

void Gameplay_een::render(SDL_Renderer* renderer){

	SDL_RenderCopy(renderer, backgroundImage, NULL, NULL);
	
	Text text_plyr(renderer, "res/impact.ttf", 180, std::to_string(player_score), { 236, 143, 94,255 });
	text_plyr.display(330, 200, renderer);
	Text text_com(renderer, "res/impact.ttf", 180, std::to_string(com_score), { 236, 143, 94,255 });
	text_com.display(870, 200, renderer);
	Text round_res_text(renderer, "res/impact.ttf", 100, round_result, { 236, 143, 94,200 });
	round_res_text.display(-1, 70, renderer);
	
	SDL_RenderCopy(renderer, but1tex, NULL, &b1);
	SDL_RenderCopy(renderer, but2tex, NULL, &b2);
	SDL_RenderCopy(renderer, but3tex, NULL, &b3);
	SDL_RenderCopy(renderer, play_move, NULL, &mp);
	SDL_RenderCopy(renderer, com_move, NULL, &mc);
}