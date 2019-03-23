#include "libmgl.h"

/*
**	For tests.
*/
int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	t_window* w = create_win("test", 300, 300);

	color_buffer(w, &(SDL_Color){136, 255, 38});
	
	asd(w);

	upd_win(w);
	

	SDL_Event e;
	while (SDL_PollEvent(&e) || 1)
		if (e.type == SDL_QUIT || (KEY == SDLK_ESCAPE))
			break;


	close_win(&w);

	if (w != NULL)
		printf("Error\n");
	SDL_Quit();

	foo();
	return (0);
}