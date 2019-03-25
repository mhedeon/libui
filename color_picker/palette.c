#include "libmgl.h"

t_palette* init_palette(SDL_Rect *size)
{
	t_palette* pal;
	t_slider* hue;
	t_slider* sv;

	pal = NULL;
	hue = NULL;
	sv = NULL;
	if ((pal = (t_palette*)malloc(sizeof(t_palette))) == NULL)
	{
		error_log("Could not allocate memory for palette");
		return (NULL);
	}
	pal->hsv = (t_hsv) { 0, 0, 0 };
	pal->size = *size;
	if ((hue = init_sl(&(SDL_Rect) { 0, 0, 2, 2 })) == NULL)
	{
		error_log("Could not allocate memory for slider");
		return (pal);
	}
	hue->set_size(hue, &(SDL_Rect){0, 0, pal->size.h / 18, 5});
	hue->set_sl(hue, &(SDL_Rect){ pal->size.x + pal->size.h + pal->size.h / 18 - 3, pal->hsv.h* pal->size.h / 360 + pal->size.y - hue->size.h / 2 - 4, 0, 0});
	pal->hue = hue;
	//if ((sv = init_sl(0, 0, 2, 2)) == NULL)
	//	return (error_log("Could not allocate memory for slider"));
	return (pal);
}