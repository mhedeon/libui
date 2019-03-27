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
	picker_set_pos(pal, 100, 50);
// printf("x: %d | y: %d | w: %d | h: %d\n", pal->sl_pal->border.x, pal->sl_pal->border.y, pal->sl_pal->border.w, pal->sl_pal->border.h);
	upd_win(w);
	
	SDL_Event e;
	int click_pal = 0, click_hue = 0;
	while (SDL_PollEvent(&e) || 1)
	{
		if (e.type == SDL_QUIT || (KEY == SDLK_ESCAPE))
			break;
		int x, y;
		if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			if (picker_within_hue(pal, x, y) && !click_pal)
			{
				picker_set_h_by_pos(pal, y);
				click_hue = 1;
				// printf("in hue\n");
			}
			else if (picker_within_pal(pal, x, y) && !click_hue)
			{
				picker_set_sv_by_pos(pal, x, y);
				click_pal = 1;
				// printf("in pal\n");
			}
			if (click_hue == 1)
				picker_set_h_by_pos(pal, y);
			else if (click_pal == 1)
				picker_set_sv_by_pos(pal, x, y);
			// printf("h: %f | s: %f | v: %f\n", pal->hsv.h, pal->hsv.s, pal->hsv.v);
		}
		else
		{
			// static int i = 0;
			click_hue = 0;
			click_pal = 0;
			// printf("UP %d\n", i++);
		}
		

		color_buffer(w, &(SDL_Color){136, 255, 38, 0});
		w->color = hsv2rgb(pal->hsv.h, pal->hsv.s, pal->hsv.v);
		color_area(w, &(SDL_Rect) { 300, 300, 75, 75 }, &w->color);

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