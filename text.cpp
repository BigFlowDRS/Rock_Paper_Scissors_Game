#include "text.h"
#include "iostream"

Text::Text(SDL_Renderer* renderer,const std::string& font_path, int font_size, const std::string& text_to_print, const SDL_Color& color) {
	TTF_Font* font = TTF_OpenFont(font_path.c_str(), font_size);
	if (!font) std::cout << "failed to load font" << std::endl;
	SDL_Surface* text_surface = TTF_RenderText_Solid(font, text_to_print.c_str(), color);
	if (!text_surface) std::cout << "failed to load font surface " << std::endl;
	text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
	if (!text_texture) std::cout << "failed to load font texture" << std::endl;
	tr.w = text_surface->w;
	tr.h = text_surface->h;
	SDL_FreeSurface(text_surface);
	TTF_CloseFont(font);
}

void Text::display(int x,int y, SDL_Renderer* renderer){
	if (x == -1) {
		tr.x = 640 - (tr.w) / 2;
	}
	else {
		tr.x = x;
	}
	tr.y = y;

	SDL_RenderCopy(renderer, text_texture, nullptr, &tr);
}

//SDL_Texture* Text::loadFont(const std::string& font_path, int font_size, const std::string &text_to_print, const SDL_Color& color) {
//	
//}

Text::~Text() {
	SDL_DestroyTexture(text_texture);

}
