#include <stdio.h>
#include <SDL2/SDL.h>

#define WIDTH 800
#define HEIGHT 800

main()
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
		return 3;
	}

	if (SDL_CreateWindowAndRenderer(WIDTH,HEIGHT,SDL_WINDOW_RESIZABLE, &window, &renderer)) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
		return 3;
	}

	int prev_mouse_x, prev_mouse_y;
	prev_mouse_x = prev_mouse_y = 0;

	int mouse_x;
	int mouse_y;
	int quit = 0;

	
  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x00);

	while (1) {

		while(SDL_PollEvent(&event) != 0) {
			switch (event.type) {
				case SDL_QUIT: 
					quit = 1;
			}
		}

		SDL_GetMouseState(&mouse_x, &mouse_y);

		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			SDL_RenderDrawLine(renderer, prev_mouse_x, prev_mouse_y, mouse_x, mouse_y);
		}
		/*printf("%d %d\n", mouse_x, mouse_y);*/

		prev_mouse_x = mouse_x;
		prev_mouse_y = mouse_y;

		SDL_RenderPresent(renderer);

		SDL_Delay(16);

		if (quit) {
			break;
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
