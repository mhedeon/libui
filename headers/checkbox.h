#ifndef CHECKBOX_H
# define CHECKBOX_H

# include "libmgl.h"

# define CHECKBOX_SIZE 15
# define CHECK_ON 1
# define CHECK_OFF 0
# define CHECK_UNAVAILABLE 81

typedef struct	s_checkbox
{
	Uint8		status;
	Uint8		unavailable;
	SDL_Rect	pos;
}				t_checkbox;

void draw_checkbox(t_window* win, t_checkbox* check);

#endif
