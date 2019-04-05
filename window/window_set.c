#include "libui.h"

void window_set_pos(t_window *win, int x, int y)
{
	if (win == NULL)
	{
		error_log("NULL pointer");
		return ;
	}
	if (x < 0 || y < 0)
	{
		error_log("Bad position");
		return ;
	}
	SDL_SetWindowPosition(win->win, x, y);
}

void window_set_size(t_window *win, int w, int h)
{
	if (win == NULL)
	{
		error_log("NULL pointer");
		return ;
	}
	if (w < 0 || w < 0)
	{
		error_log("Bad position");
		return ;
	}
	SDL_SetWindowSize(win->win, w, h);
}

void window_set_title(t_window *win, const char *title)
{
	if (win == NULL)
	{
		error_log("NULL pointer");
		return ;
	}
	if (title == NULL)
	{
		error_log("Bad title");
		return ;
	}
	SDL_SetWindowTitle(win->win, title);
}
