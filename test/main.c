#include "libmgl.h"

/*
**	For tests.
*/
int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	t_window* w = create_win("test", 500, 300);

	color_buffer(w, &(SDL_Color){196, 236, 20, 0});
	color_area(w, &(SDL_Rect){0, 0, 100, 150}, & (SDL_Color){128, 128, 128, 0});
	clear_area(w, &(SDL_Rect){15, 15, 23, 45});
	// clear_buffer(w);
	upd_win(w);
	error_log("all fine");
	SDL_Delay(2000);

	close_win(&w);

	if (w != NULL)
		printf("Error\n");
	SDL_Quit();

	foo();
	return (0);
}