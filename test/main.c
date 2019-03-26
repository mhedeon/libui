#include "libmgl.h"

# define KEY e.type == SDL_KEYDOWN && e.key.keysym.sym
# define L_CLICK SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)
# define R_CLICK SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT)

/*
**	For tests.
*/
int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	t_window* w = create_win("test", 500, 500);

	color_buffer(w, &(SDL_Color){136, 255, 38, 0});
	
	t_picker *pal = picker_create(200);
	picker_set_pos(pal, 0, 0);
printf("x: %d | y: %d | w: %d | h: %d\n", pal->sl_pal->border.x, pal->sl_pal->border.y, pal->sl_pal->border.w, pal->sl_pal->border.h);
	upd_win(w);
	
	SDL_Event e;
	// int click = 0;
	while (SDL_PollEvent(&e) || 1)
	{
		if (e.type == SDL_QUIT || (KEY == SDLK_ESCAPE))
			break;
		int x, y;
		if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			if (picker_within_hue(pal, x, y))
				picker_set_h_by_pos(pal, y);
			else if (picker_within_pal(pal, x, y))
				picker_set_sv_by_pos(pal, x, y);
			printf("h: %f | s: %f | v: %f\n", pal->hsv.h, pal->hsv.s, pal->hsv.v);
		}
		

		color_buffer(w, &(SDL_Color){136, 255, 38, 0});
	
		picker_draw(w, pal);
		upd_win(w);
	}

	close_win(&w);

	if (w != NULL)
		printf("Error\n");
	SDL_Quit();

	// system("leaks libmgl");
	return (0);
}