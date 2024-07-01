#include "global.h"

//TODO Start Gameplay Raycast
void	btn_Play() {
	ft_printf("btn_Play \n");
}

//TODO Start Build Engine
void	btn_LevelEditor() {
	ft_printf("btn_LevelEditor \n");
}

//TODO Quit The Game
void	btn_Quit() {
	gameEnv->RunningState = 0;
}

int isMouseOverButton(int mouseX, int mouseY, t_Button button) {
	return mouseX >= button.rect.x && mouseX <= button.rect.x + button.rect.w &&
			mouseY >= button.rect.y && mouseY <= button.rect.y + button.rect.h;
}

void	mainMenu_mouseButtonHandler(t_2dVector pos) {
	for (int i = 0; i < 3; i++) {
		if (isMouseOverButton(pos.x, pos.y, gameEnv->mainMenu.menuButtons[i])) {
			gameEnv->mainMenu.menuButtons[i].onClick();
		}
	}
}

void renderButton(SDL_Renderer *renderer, t_Button button, TTF_Font *font) {
	SDL_Color color = {255, 255, 255, 255};
	SDL_Color bgColor = {50, 0, 100, 255};

	// Render button background
	SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
	SDL_RenderFillRect(renderer, &button.rect);

	// Render button label
	SDL_Surface *surface = TTF_RenderText_Solid(font, button.label, color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
	int texW = 0;
	int texH = 0;
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	SDL_Rect dstRect = {button.rect.x + (button.rect.w - texW) / 2, button.rect.y + (button.rect.h - texH) / 2, texW, texH};
	SDL_RenderCopy(renderer, texture, NULL, &dstRect);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}