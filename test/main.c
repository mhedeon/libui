#include "libmgl.h"

/*
**	For tests.
*/
int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	t_window* w = create_win("test", 300, 300);

	color_buffer(w, &(SDL_Color){136, 255, 38});
	
	t_checkbox* on = checkbox_create(CHECK_ON, CHECK_AVAILABLE, 50, 50);
	
	printf("x: %u | y: %u\n", checkbox_get_pos_x(on), checkbox_get_pos_y(on));
	printf("status: %u | av: %u\n", checkbox_get_status(on), checkbox_get_availalbe(on));

	checkbox_set_status(on, CHECK_OFF);
	checkbox_set_available(on, CHECK_UNAVAILABLE);
	checkbox_set_pos(on, 150, 200);

	printf("x: %u | y: %u\n", checkbox_get_pos_x(on), checkbox_get_pos_y(on));
	printf("status: %u | av: %u\n", checkbox_get_status(on), checkbox_get_availalbe(on));
	
	draw_checkbox(w, on);
	upd_win(w);
	

	SDL_Event e;
	while (SDL_PollEvent(&e) || 1)
		if (e.type == SDL_QUIT || (KEY == SDLK_ESCAPE))
			break;

	checkbox_delete(&on);
	close_win(&w);

	if (w != NULL)
		printf("Error\n");
	SDL_Quit();

	foo();
	return (0);
}