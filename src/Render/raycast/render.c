// #include "global.h"
// #include "render.h"
// #include "map.h"

// float angle = 30;

// int render_thread_func(void *)
// {
// 	if (!window)
// 	{
// 		ft_putstr_fd("Failed to create window\n", STDERR_FILENO);
// 		return -1;
// 	}
// 	SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

// 	if (!renderer)
// 	{
// 		ft_putstr_fd("Failed to create renderer\n", STDERR_FILENO);
// 		SDL_DestroyWindow(window);
// 		SDL_Quit();
// 		return -1;
// 	}

// 	while (running)
// 	{
// 		// Clear screen
// 		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
// 		SDL_RenderClear(renderer);

// 		render_scene(renderer, 2, 2, &angle);
// 		// Update screen
// 		SDL_RenderPresent(renderer);

// 		// Sleep for a short duration to limit the frame rate
// 		SDL_Delay(16);
// 	}
// 	SDL_DestroyRenderer(renderer);
// 	return 0;
// }

// void render_scene(SDL_Renderer *renderer, int player_x, int player_y, float *player_angle)
// {
// 	int screen_width = WINDOW_WIDTH;
// 	int screen_height = WINDOW_HEIGHT;
// 	int ray_count = screen_width; // Number of rays equals the screen width for 1 ray per pixel

// 	for (int ray = 0; ray < ray_count; ++ray)
// 	{
// 		// Calculate the angle of the ray
// 		float ray_angle = (*player_angle - FOV / 2.0) + (ray / (float)ray_count) * FOV;
// 		// Calculate the direction vector for the ray
// 		float ray_x = cos(ray_angle);
// 		float ray_y = sin(ray_angle);

// 		float distance_to_wall = 0.0f; // Initialize distance to wall
// 		int hit_wall = 0;			   // Flag to indicate if the wall is hit

// 		// Ray casting loop
// 		while (!hit_wall && distance_to_wall < MAX_DEPTH)
// 		{
// 			distance_to_wall += 0.1f; // Increment the distance to the wall
// 			// Calculate the test point based on the direction vector and distance
// 			int test_x = (int)(player_x + ray_x * distance_to_wall);
// 			int test_y = (int)(player_y + ray_y * distance_to_wall);

// 			// Check if the ray is out of bounds

// 			if (test_x < 0 || test_x >= MAP_WIDTH || test_y < 0 || test_y >= MAP_HEIGHT)
// 			{
// 				hit_wall = 1;		   // Mark as hit wall to break the loop
// 				distance_to_wall = -1; // Set distance to max depth to avoid drawing
// 			}
// 			else if (get_map_value(test_x, test_y) == 1) // Check if the map value indicates a wall
// 			{
// 				hit_wall = 1;
// 			}
// 		}

// 		// Calculate the height of the wall slice to draw
// 		int line_height = (int)(screen_height / distance_to_wall);
// 		// Calculate the start and end points for the wall slice
// 		int draw_start = -line_height / 2 + screen_height / 2;
// 		int draw_end = line_height / 2 + screen_height / 2;

// 		// Set the color for the wall slice
// 		SDL_SetRenderDrawColor(renderer, 50, 50, 50, 50); // Gray color
// 		// Draw the wall slice as a vertical line
// 		// SDL_RenderLine(renderer, ray, draw_start, ray, draw_end);
// 	}
// }