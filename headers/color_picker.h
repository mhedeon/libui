#ifndef HEADER_H
# define HEADER_H

# include "libmgl.h"

// # define KEY e.type == SDL_KEYDOWN && e.key.keysym.sym
// # define L_CLICK SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)
// # define R_CLICK SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT)



typedef struct	s_slider
{
	SDL_Rect	size;
	SDL_Color color;
	void (*set_sl)();
	void (*set_color)();
	void (*draw)();
	void (*set_size)();
}				t_slider;

typedef struct	s_palette
{
	t_hsv hsv;
	SDL_Rect size;
	t_slider* hue;
	t_slider* sv;
}				t_palette;

/*
**	color.c
*/
SDL_Color hsv2rgb(double h, double s, double v);
void draw_palette(t_window* window, t_palette *pal);
int in_hue(t_palette *pal);

/*
**	slider.c
*/
t_slider* init_sl(SDL_Rect* size);

/*
**	palette.c
*/
t_palette* init_palette(SDL_Rect* size);

#endif
