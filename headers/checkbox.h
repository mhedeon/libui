#ifndef CHECKBOX_H
# define CHECKBOX_H

# include "libmgl.h"

# define CHECKBOX_SIZE 15
# define CHECK_ON 1
# define CHECK_OFF 0


typedef struct	s_checkbox
{
	Uint8		status;
	SDL_Rect	pos;
}				t_checkbox;

void asd(t_window* win);

#endif
