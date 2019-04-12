/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 05:22:34 by mhedeon           #+#    #+#             */
/*   Updated: 2019/03/31 05:22:34 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int window_malloc(t_window **win)
{
	if ((*win = (t_window*)malloc(sizeof(t_window))) == NULL)
		return (error_log("Could not allocate memory for window"));
	(*win)->win = NULL;
	(*win)->ren = NULL;
	(*win)->tex = NULL;
	(*win)->buff = NULL;

	return (1);
}

static int		window_init(t_window *win, char *title, SDL_Rect *rect, SDL_WindowFlags flags)
{
	win->w = rect->w > 0 ? rect->w : 100;
	win->h = rect->h > 0 ? rect->h : 100;
	rect->x = rect->x > 0 ? rect->x : SDL_WINDOWPOS_CENTERED;
	rect->y = rect->y > 0 ? rect->y : SDL_WINDOWPOS_CENTERED;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return (error_log("Unable to initialize SDL:"));
	if ((win->win = SDL_CreateWindow(title, rect->x,
		rect->y, win->w, win->h, flags)) == NULL)
		return (error_log("Could not create window:"));
	if ((win->ren = SDL_CreateRenderer(win->win, -1, SDL_RENDERER_ACCELERATED |
		SDL_RENDERER_PRESENTVSYNC)) == NULL)
		return (error_log("Could not create renderer:"));
	if ((win->tex = SDL_CreateTexture(win->ren, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, win->w, win->h)) == NULL)
		return (error_log("Could not create texture:"));
	if ((win->buff = (Uint32*)malloc(sizeof(Uint32) *
		(win->h * win->w))) == NULL)
		return (error_log("Could not allocate memory for buff"));
	clear_buffer(win);
	win->color = (SDL_Color) { 0, 0, 0, 0 };
	return (1);
}

t_window* window_create(char* title, SDL_Rect* rect, SDL_Color *bg_color)
{
	t_window* win;
	SDL_WindowFlags flags;

	flags = SDL_WINDOW_SHOWN;
	if (!window_malloc(&win))
		return (NULL);
	win->bg_color = (bg_color == NULL) ? (SDL_Color) { 0, 0, 0, 0 } : *bg_color;
	if (!window_init(win, title, rect, flags))
	{
		window_close(&win);
		return (NULL);
	}
	return (win);
}

t_window		*window_create_resizable(char *title, SDL_Rect *rect, SDL_Color* bg_color)
{
	t_window	*win;
	SDL_WindowFlags flags;

	flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
	if (!window_malloc(&win))
		return (NULL);
	win->bg_color = (bg_color == NULL) ? (SDL_Color) { 0, 0, 0, 0 } : *bg_color;
	if (!window_init(win, title, rect, flags))
	{
		window_close(&win);
		return (NULL);
	}
	return (win);
}

t_window* window_create_background(/* TODO */)
{
	// TODO
	// create window with background texture
	return (NULL);
}

int		window_resize(t_window *win)
{
	int w;
	int h;

	SDL_GetWindowSize(win->win, &w, &h);
	win->w = w;
	win->h = h;
	SDL_DestroyTexture(win->tex);
	free(win->buff);
	win->buff = NULL;
	if ((win->tex = SDL_CreateTexture(win->ren, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, win->w, win->h)) == NULL)
		return (error_log("Could not create texture:"));
	if ((win->buff = (Uint32*)malloc(sizeof(Uint32) *
		(win->h * win->w))) == NULL)
		return (error_log("Could not allocate memory for buff"));
	clear_buffer(win);
	return (1);
}

void			window_close(t_window **win)
{
	if (*win == NULL)
		return ;
	if ((*win)->tex != NULL)
		SDL_DestroyTexture((*win)->tex);
	if ((*win)->ren != NULL)
		SDL_DestroyRenderer((*win)->ren);
	if ((*win)->win != NULL)
		SDL_DestroyWindow((*win)->win);
	if ((*win)->buff != NULL)
		free((*win)->buff);
	(*win)->w = 0;
	(*win)->h = 0;
	(*win)->color = (SDL_Color) { 0, 0, 0, 0 };
	free(*win);
	*win = NULL;
}
