#include "libmgl.h"

void picker_set_pos(t_picker *picker, int x, int y)
{
	int h;

	if (picker == NULL)
		return ;
	h = picker->pos.h;
	picker->pos = (SDL_Rect) { x, y, h, h };
	picker->hue = (SDL_Rect) { x + h + h / 18, y, h / 18, h };
}

void picker_set_size(t_picker *picker, int height)
{
	int x;
	int y;

	if (picker == NULL)
		return ;
	x = picker->pos.x;
	y = picker->pos.y;
	picker->pos = (SDL_Rect) { x, y, height, height };
	picker->hue = (SDL_Rect) {x + height + height / 18, y, height / 18, height};
}

void picker_set_hsv(t_picker *picker, double h, double s, double v)
{
	if (picker == NULL ||
		(h < 0.0 || h > 360.0) ||
		(s < 0.0 || s > 1.0) ||
		(v < 0.0 || v > 1.0))
		return ;
	picker->hsv = (t_hsv) { h, s, v };
}