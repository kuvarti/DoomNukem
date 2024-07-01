#include "events.h"
#include "global.h"
#include <stdlib.h>

#define KEY_PRESSED gameEnv->event.keyPressed

void KeyPressInit() {
	KEY_PRESSED.forward = 0;
	KEY_PRESSED.left = 0;
	KEY_PRESSED.right = 0;
	KEY_PRESSED.back = 0;
}

int event_thread_func(void* data) {
	(void) data;
	t_2dVector	mousePos;
	SDL_Event	event;

	KeyPressInit();
	while (gameEnv->RunningState) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				gameEnv->RunningState = 0;
			} else if (event.type == SDL_KEYDOWN) {
				keyEventKeyDown(event.key.keysym.sym);
			} else if (event.type == SDL_KEYUP) {
				keyEventKeyUp(event.key.keysym.sym);
			} else if (event.type == SDL_MOUSEBUTTONDOWN) {
				if (event.button.button == SDL_BUTTON_LEFT) {
					SDL_GetMouseState(&mousePos.x, &mousePos.y);
					gameEnv->event.mouseButtonHandler(mousePos);
				}
			}
		}
		SDL_Delay(10);
		if (!gameEnv->RunningState){
			ft_printf("Event thread shutting down\n");
			break;
		}
	}
	return 0;
}