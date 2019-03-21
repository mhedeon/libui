#include "window.h"

void	set_pixel(t_window *win, SDL_Color *color, int x, int y)
{
	win->buff[y * win->w + x] =
		color->r << 24 |
		color->g << 16 |
		color->b << 8 |
		color->a;
}
