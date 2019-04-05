#include "libui.h"

int window_get_pos(t_window *win, int *x, int *y)
{
	if (win == NULL)
		return (error_log("NULL pointer"));
	SDL_GetWindowPosition(win->win, x, y);
	return (1);
}

int window_get_size(t_window *win, int *w, int *h)
{
	if (win == NULL)
		return (error_log("NULL pointer"));
	SDL_GetWindowSize(win->win, w, h);
	return (1);
}

const char *window_get_title(t_window *win)
{
	if (win == NULL)
	{
		error_log("NULL pointer");
		return (NULL);
	}
	return (SDL_GetWindowTitle(win->win));
}