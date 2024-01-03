#pragma once

#include "SDL_ttf.h"
#include "SDL.h"
#include "string"

class Text {
private:
	SDL_Texture* text_texture = nullptr;
	SDL_Rect tr;

public:
	~Text();
	Text(SDL_Renderer* renderer,const std::string& font_path, int font_size, const std::string& text_to_print, const SDL_Color& color);

	void display(int x, int y, SDL_Renderer* renderer);

	//static SDL_Texture* loadFont(const std::string& font_path, int font_size, const std::string& text_to_print, const SDL_Color& color);
};
