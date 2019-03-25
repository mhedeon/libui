#include "libmgl.h"

t_picker *picker_create(int x, int y, int height)
{
	t_picker *new;

	if ((new = (t_picker*)malloc(sizeof(t_picker))) == NULL)
	{
		error_log("Could not allocate memory for color picker");
		return (NULL);
	}
	new->hsv = (t_hsv) { 0, 0, 0 };
	new->pos = (SDL_Rect) { x, y, height, height };
	new->hue = (SDL_Rect) { x + height + height / 18, y, height / 18, height };

	return (new);
}

void picker_delete(t_picker **picker)
{
	if (*picker == NULL)
		return ;
	free(*picker);
	*picker = NULL;
}
