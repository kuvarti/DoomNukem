#include "global.h"
#include "config.h"

# define MainMenuButton gameEnv->mainMenu.menuButtons

void	initMenuButton(void *p){
	t_Button *b = (t_Button *)p;
	(*b).label = 0;
	(*b).onClick = NULL;
	(*b).rect = (SDL_Rect){0, 0, 0, 0};
}

void	initMainMenuButtons() {
	MainMenuButton = (t_Button *)getAndInitStruct(3, sizeof(t_Button), *initMenuButton);
	MainMenuButton[0].label = "Play";
	MainMenuButton[0].rect = (SDL_Rect){
		(WINDOW_WIDTH - BUTTON_WIDTH) / 2, 
		(WINDOW_HEIGHT - (BUTTON_HEIGHT * 3 + BUTTON_PADDING * 2)) / 2, 
		BUTTON_WIDTH, BUTTON_HEIGHT
	};
	MainMenuButton[0].onClick = &btn_Play;

	MainMenuButton[1].label = "Level Editor";
	MainMenuButton[1].rect = (SDL_Rect){
		(WINDOW_WIDTH - BUTTON_WIDTH) / 2,
		(WINDOW_HEIGHT - (BUTTON_HEIGHT * 3 + BUTTON_PADDING * 2)) / 2 + BUTTON_HEIGHT + BUTTON_PADDING,
		BUTTON_WIDTH, BUTTON_HEIGHT
	};
	MainMenuButton[1].onClick = &btn_LevelEditor;

	MainMenuButton[2].label = "Quit";
	MainMenuButton[2].rect = (SDL_Rect){
		(WINDOW_WIDTH - BUTTON_WIDTH) / 2,
		(WINDOW_HEIGHT - (BUTTON_HEIGHT * 3 + BUTTON_PADDING * 2)) / 2 + (BUTTON_HEIGHT + BUTTON_PADDING) * 2, 
		BUTTON_WIDTH, BUTTON_HEIGHT
	};
	MainMenuButton[2].onClick = &btn_Quit;
}

void	initMainMenufont() {
	if (TTF_Init() == -1) {
		ft_printf("TTF_Init err: %s\n", TTF_GetError());
	}
	gameEnv->mainMenu.font.size = 30;
	gameEnv->mainMenu.font.font = TTF_OpenFont("resources/ttf/arial.ttf", gameEnv->mainMenu.font.size);
	if (!gameEnv->mainMenu.font.font) {
		ft_printf("Failed to load font! TTF_Error: %s\n", TTF_GetError());
	}
}