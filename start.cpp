#include "SDL.h"
#include "SDL_image.h"
#include "iostream"
#include "start.h"


StartScreen::StartScreen(SDL_Renderer* renderer) {
	is_running = true;
	SDL_Surface* imageSurface = IMG_Load("res/start.png");
	backgroundImage = SDL_CreateTextureFromSurface(renderer, imageSurface);

	SDL_Surface* button_sur = IMG_Load("res/start_button.png");
	button = SDL_CreateTextureFromSurface(renderer, button_sur);
	buton.w = 242*1.5;
	buton.h = 64*1.5;
	buton.x = 640 - (buton.w)/2;
	buton.y = 550;
	

	SDL_FreeSurface(imageSurface);
	SDL_FreeSurface(button_sur);
}

bool StartScreen::ismouseoverbutton(int x, int y) {
	if (x >= buton.x && x <= buton.x + buton.w && y >= buton.y && y <= buton.y + buton.h) {
		return true;
	}

	return false;
}
bool StartScreen::svch_screen() {
	return swi_scr;

}
void StartScreen::buttonclick() {
	swi_scr = true;
}

StartScreen::~StartScreen() {
	SDL_DestroyTexture(backgroundImage);
	SDL_DestroyTexture(button);
}

bool StartScreen::close_win() {
	return is_running;
}

void StartScreen::handleEvents(){
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			is_running = false;
			break;
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN) {
			std::cout << "Click" << std::endl;

			int mouseX, mouseY;
			SDL_GetMouseState(&mouseX, &mouseY);

			if (ismouseoverbutton(mouseX, mouseY)) {
				std::cout << "click on button" << std::endl;
				buttonclick();
			}
			break;
		}
	}
}

void StartScreen::update(){
        
}

int StartScreen::info() {
	return 0;
}

void StartScreen::render(SDL_Renderer* renderer){
	SDL_RenderCopy(renderer, backgroundImage, NULL, NULL);
	SDL_RenderCopy(renderer, button, NULL, &buton);
}
