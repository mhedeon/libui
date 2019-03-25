#include "libmgl.h"

/*
**	For tests.
*/
int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	t_window* w = create_win("test", 300, 300);

	color_buffer(w, &(SDL_Color){136, 255, 38, 0});
	
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
	int click = 0;
	while (SDL_PollEvent(&e) || 1)
	{
		if (e.type == SDL_QUIT || (KEY == SDLK_ESCAPE))
			break;
		int x, y;
		
		if (e.type == SDL_MOUSEBUTTONUP)
			click = 0;
		if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT) && !click)
		{
			printf("LEFT click | x: %d | y: %d\n", x, y);
			if (x > checkbox_get_pos_x(on) && y > checkbox_get_pos_y(on) &&
				x < checkbox_get_pos_x(on) + CHECKBOX_SIZE &&
				y < checkbox_get_pos_y(on) + CHECKBOX_SIZE)
				checkbox_set_invert_status(on);
		}
		if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_RIGHT) && !click)
		{
			printf("RIGHT click | x: %d | y: %d\n", x, y);
			if (x > checkbox_get_pos_x(on) && y > checkbox_get_pos_y(on) &&
				x < (checkbox_get_pos_x(on) + CHECKBOX_SIZE) &&
				y < (checkbox_get_pos_y(on) + CHECKBOX_SIZE))
				checkbox_set_invert_available(on);
		}
		if (e.type == SDL_MOUSEBUTTONDOWN)
			click = 1;
		draw_checkbox(w, on);
		upd_win(w);
	}

	checkbox_delete(&on);
	close_win(&w);

	if (w != NULL)
		printf("Error\n");
	SDL_Quit();

	foo();
	// system("leaks libmgl");
	return (0);
}