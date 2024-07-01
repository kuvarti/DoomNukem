#include "global.h"

int	showMainMenu(){
	gameEnv->event.mouseButtonHandler = &mainMenu_mouseButtonHandler;
	while (gameEnv->RunningState == 1)
	{
		SDL_SetRenderDrawColor(gameEnv->sdl.renderer, 0, 0, 0, 255);
		SDL_RenderClear(gameEnv->sdl.renderer);
		for (int i = 0; i < 3; i++) {
			renderButton(gameEnv->sdl.renderer, gameEnv->mainMenu.menuButtons[i], gameEnv->mainMenu.font.font);
		}
		SDL_RenderPresent(gameEnv->sdl.renderer);
		SDL_Delay(300);
	}
	return 1;
}