#include "libmgl.h"

void	set_pixel(t_window *win, SDL_Color *color, int x, int y)
{
	if (x < 0 || x >= win->w || y < 0 || x >= win->h)
		return;
	win->buff[y * win->w + x] =
		color->r << 24 |
		color->g << 16 |
		color->b << 8 |
		color->a;
}
