#include "libmgl.h"

/*
**	For tests.
*/
int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	t_window* w = create_win("test", 500, 500);

	color_buffer(w, &(SDL_Color){136, 255, 38, 0});
	
	t_picker *pal = picker_create(50, 50, 250);
	picker_draw(w, pal);


	upd_win(w);
	
	SDL_Event e;
	while (SDL_PollEvent(&e) || 1)
	{
		if (e.type == SDL_QUIT || (KEY == SDLK_ESCAPE))
			break;
		// int x, y;
		

		color_buffer(w, &(SDL_Color){136, 255, 38, 0});
		picker_draw(w, pal);
		upd_win(w);
	}

	close_win(&w);

	if (w != NULL)
		printf("Error\n");
	SDL_Quit();

	foo();
	// system("leaks libmgl");
	return (0);
}