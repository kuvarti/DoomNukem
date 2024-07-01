#include "config.h"
#include "event.h"
#include "global.h"
#include "commonStructures.h"
#include <stdio.h>

void	initGameEnv(void *p) {
	t_gameEnv *g = (t_gameEnv *)p;
	g->map.sector = NULL;
	g->sdl.window = NULL;
	g->sdl.window_surface = NULL;
	g->mainMenu.menuButtons = NULL;
	g->event.mouseButtonHandler = NULL;
	g->RunningState = 0;
}

void	initMainMenu() {
	initMainMenuButtons();
	initMainMenufont();
} 

int InitConfigs() {
	gameEnv = (t_gameEnv *)getAndInitStruct(1, sizeof(t_gameEnv), &initGameEnv);
	initMainMenu();
	return 1;
}