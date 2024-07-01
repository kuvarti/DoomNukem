#include "global.h"
#include "map.h"
#include <sys/mman.h>

#include "config.h"
#include "libft.h"
#include "events.h"
#include "render.h"

#include "SDL_thread.h"

t_gameEnv	*gameEnv;

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	SDL_Thread *event_thread = NULL;
	// SDL_Thread *render_thread = NULL;

	InitConfigs();
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_putstr_fd("Failed to initialize the SDL2 library\n", STDERR_FILENO);
		return -1;
	}

	gameEnv->sdl.window = SDL_CreateWindow("DoomNukem", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	if (!gameEnv->sdl.window)
	{
		ft_putstr_fd("Failed to create window\n", STDERR_FILENO);
		return -1;
	}
	gameEnv->sdl.renderer = SDL_CreateRenderer(gameEnv->sdl.window, -1, SDL_RENDERER_ACCELERATED);
	if (!gameEnv->sdl.renderer)
	{
		ft_putstr_fd("Failed to create renderer\n", STDERR_FILENO);
		return -1;
	}

	gameEnv->RunningState = 1;
	event_thread = SDL_CreateThread(event_thread_func, "EventThread", NULL);
	// render_thread = SDL_CreateThread(render_thread_func, "RenderThread", NULL);

	getMap("resources/maps/raycastTest.map");
	// SDL_WaitThread(render_thread, NULL);

	renderMain();
	SDL_WaitThread(event_thread, NULL);

	TTF_CloseFont(gameEnv->mainMenu.font.font);
	SDL_DestroyRenderer(gameEnv->sdl.renderer);
	SDL_DestroyWindow(gameEnv->sdl.window);
	gameEnv->sdl.window = NULL;
	SDL_Quit();
	return 0;
}