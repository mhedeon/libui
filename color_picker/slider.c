#include "libmgl.h"

static void draw_corner(t_window* win, SDL_Rect *p, SDL_Color *color, int dir)
{
	if (dir > 0)
	{
		set_pixel(win, color, p->x, p->y + 2);
		set_pixel(win, color, p->x + 1, p->y + 1);
		set_pixel(win, color, p->x + 2, p->y);
		set_pixel(win, color, p->x + 1, p->y + 2);
		set_pixel(win, color, p->x + 2, p->y + 1);
	}
	else if (dir < 0)
	{
		set_pixel(win, color, p->x, p->y);
		set_pixel(win, color, p->x + 1, p->y + 1);
		set_pixel(win, color, p->x + 2, p->y + 2);
		set_pixel(win, color, p->x, p->y + 1);
		set_pixel(win, color, p->x + 1, p->y + 2);
	}
}

static void draw_sl(t_window* win, t_slider* sl)
{
	color_area(win, &(SDL_Rect){sl->size.x + 2, sl->size.y + 2, sl->size.w + 2,
		sl->size.h + 2}, &sl->color);
	color_area(win, &(SDL_Rect){sl->size.x + 2, sl->size.y, sl->size.w + 2, 1},
		& (SDL_Color){255, 255, 255, 0});
	color_area(win, &(SDL_Rect){sl->size.x + 2, sl->size.y + 6 + sl->size.h -1,
		sl->size.w + 2, 1}, & (SDL_Color){255, 255, 255, 0});
	color_area(win, &(SDL_Rect){sl->size.x, sl->size.y + 2, 1, sl->size.h + 2},
		& (SDL_Color){255, 255, 255, 0});
	color_area(win, &(SDL_Rect){sl->size.x + 6 + sl->size.w - 1,
		sl->size.y + 2, 1, sl->size.h + 2}, & (SDL_Color){255, 255, 255, 0});
	color_area(win, &(SDL_Rect){sl->size.x + 3, sl->size.y + 1, sl->size.w, 1},
		& (SDL_Color){0, 0, 0, 0});
	color_area(win, &(SDL_Rect){sl->size.x + 3, sl->size.y + 6 +
		sl->size.h - 2, sl->size.w, 1}, & (SDL_Color){0, 0, 0, 0});
	color_area(win, &(SDL_Rect){sl->size.x + 1, sl->size.y + 3, 1, sl->size.h},
		& (SDL_Color){0, 0, 0, 0});
	color_area(win, &(SDL_Rect){sl->size.x + 6 + sl->size.w - 2,
		sl->size.y + 3, 1, sl->size.h}, & (SDL_Color){0, 0, 0, 0});
	draw_corner(win, &(SDL_Rect){sl->size.x, sl->size.y, 0, 0}, 
		&(SDL_Color){255, 255, 255, 0}, 1);
	draw_corner(win, &(SDL_Rect){sl->size.x + 3 + sl->size.w, sl->size.y,
		0, 0}, & (SDL_Color){255, 255, 255, 0}, -1);
	draw_corner(win, &(SDL_Rect){sl->size.x + 1, sl->size.y + 1, 0, 0},
		& (SDL_Color){0, 0, 0, 0}, 1);
	draw_corner(win, &(SDL_Rect){sl->size.x + 2 + sl->size.w, sl->size.y + 1,
		0, 0}, & (SDL_Color){0, 0, 0, 0}, -1);
	draw_corner(win, &(SDL_Rect){sl->size.x, sl->size.y + 2 + sl->size.h,
		0, 0}, & (SDL_Color){255, 255, 255, 0}, -1);
	draw_corner(win, &(SDL_Rect){sl->size.x + 3 + sl->size.w, sl->size.y + 2 +
		sl->size.h, 0, 0}, & (SDL_Color){255, 255, 255, 0}, 1);
	draw_corner(win, &(SDL_Rect){sl->size.x + 1, sl->size.y + 1 +
		sl->size.h, 0, 0}, & (SDL_Color){0, 0, 0, 0}, -1);
	draw_corner(win, &(SDL_Rect){sl->size.x + 2 + sl->size.w, sl->size.y + 1 +
		sl->size.h, 0, 0}, & (SDL_Color){0, 0, 0, 0}, 1);
}

static void set_slider(t_slider* sl, SDL_Rect* pos)
{
	if (pos == NULL)
		return;
	sl->size.x = pos->x;
	sl->size.y = pos->y;
}

static void set_color(t_slider* sl, SDL_Color* color)
{
	if (color == NULL)
		return;
	sl->color = *color;
}

static void set_size(t_slider* sl, SDL_Rect* size)
{
	if (size == NULL)
		return;
	sl->size.w = size->w;
	sl->size.h = size->h;
}

t_slider* init_sl(SDL_Rect* size)
{
	t_slider* sl;

	if ((sl = (t_slider*)malloc(sizeof(t_slider))) == NULL)
		return (NULL);
	if (size == NULL)
		sl->size = (SDL_Rect) { 0, 0, 2, 2 };
	else
		sl->size = *size;
	sl->size.w = sl->size.w < 2 ? 2 : sl->size.w;
	sl->size.h = sl->size.h < 2 ? 2 : sl->size.h;
	sl->color = (SDL_Color) { 255, 255, 255, 0 };
	sl->set_sl = &set_slider;
	sl->set_color = &set_color;
	sl->draw = &draw_sl;
	sl->set_size = &set_size;
	return (sl);
}