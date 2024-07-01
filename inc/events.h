#pragma once

#include "libft.h"
#include "SDL.h"
#include "SDL_events.h"
#include "commonStructures.h"

typedef struct s_KeyPress
{
	char forward;
	char left;
	char right;
	char back;
}	t_KeyPress;

typedef struct s_Events {
	t_KeyPress  keyPressed;
	void (* mouseButtonHandler)(t_2dVector);
}	t_Events;

int event_thread_func(void *);
void keyEventKeyUp(SDL_Keycode);
void keyEventKeyDown(SDL_Keycode);