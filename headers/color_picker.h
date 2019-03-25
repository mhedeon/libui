#ifndef COLOR_PICKER_H
# define COLOR_PICKER_H

# include "libmgl.h"

typedef struct	s_picker
{
	SDL_Rect	pos;
	SDL_Rect	hue;
	t_hsv		hsv;
}				t_picker;

t_picker *picker_create(int x, int y, int height);
void picker_delete(t_picker **picker);

void picker_draw(t_window *win, t_picker *picker);

#endif
