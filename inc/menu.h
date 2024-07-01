#pragma once

#include "SDL.h"
#include "SDL_ttf.h"

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 50
#define BUTTON_PADDING 20

typedef struct s_Button {
	SDL_Rect rect;
	const char *label;
	void (*onClick)();
}	t_Button;

typedef struct s_Font {
	TTF_Font	*font;
	int			size;
}	t_Font;

typedef struct s_Menu {
	t_Button	*menuButtons;
	t_Font		font;
}	t_Menu;

void	btn_Play();
void	btn_Quit();
void	btn_LevelEditor();

int		showMainMenu();
void	renderButton(SDL_Renderer *, t_Button, TTF_Font *);
void	mainMenu_mouseButtonHandler(t_2dVector pos);