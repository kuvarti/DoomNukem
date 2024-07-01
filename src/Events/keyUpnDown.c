#include "events.h"
#include "global.h"

#define KEY_PRESSED gameEnv->event.keyPressed

void keyEventKeyUp(SDL_Keycode sym){
	switch (sym)
	{
	case SDLK_w:
	case SDLK_UP:
		ft_printf("W KEY RELEASED\n");
		KEY_PRESSED.forward = 0;
		break;
	case SDLK_a:
	case SDLK_LEFT:
		ft_printf("A KEY RELEASED\n");
		KEY_PRESSED.left = 0;
		break;
	case SDLK_s:
	case SDLK_DOWN:
		ft_printf("S KEY RELEASED\n");
		KEY_PRESSED.back = 0;
		break;
	case SDLK_d:
	case SDLK_RIGHT:
		ft_printf("D KEY RELEASED\n");
		KEY_PRESSED.right = 0;
		break;
	default:
		break;
	}
	// ft_printf("event.key Up : %d\n", sym);
}

void keyEventKeyDown(SDL_Keycode sym){
	switch (sym)
	{
	case SDLK_ESCAPE:
		gameEnv->RunningState = 0;
		break;
	case SDLK_w:
	case SDLK_UP:
		ft_printf("W KEY PRESSED\n");
		KEY_PRESSED.forward = 1;
		break;
	case SDLK_a:
	case SDLK_LEFT:
		ft_printf("A KEY PRESSED\n");
		KEY_PRESSED.left = 1;
		break;
	case SDLK_s:
	case SDLK_DOWN:
		ft_printf("S KEY PRESSED\n");
		KEY_PRESSED.back = 1;
		break;
	case SDLK_d:
	case SDLK_RIGHT:
		ft_printf("D KEY PRESSED\n");
		KEY_PRESSED.right = 1;
		break;
	default:
		break;
	}
	// ft_printf("event.key Down : %d\n", sym);
}
