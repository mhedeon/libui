/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 05:30:01 by mhedeon           #+#    #+#             */
/*   Updated: 2019/03/31 05:31:20 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "libui.h"

typedef struct		s_window
{
	int				w;
	int				h;
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Texture		*tex;
	Uint32			*buff;
	SDL_Color		color;
}					t_window;

/*
**	---------------------------- window_create.c | start
*/

t_window			*window_create(char *title, SDL_Rect *rect, int resizale);
int		window_resize(t_window *win);
void				window_close(t_window **win);

/*
**	---------------------------- window_create.c | end
*/

/*
**	---------------------------- window_update.c | start
*/

void				upd_win(t_window *win);

/*
**	---------------------------- window_update.c | end
*/

/*
**	---------------------------- window_draw.c | start
*/
void				clear_area(t_window *win, SDL_Rect *area);
void				color_area(t_window *win, SDL_Rect *area, SDL_Color *color);
void				clear_buffer(t_window *win);
void				color_buffer(t_window *win, SDL_Color *color);
/*
**	---------------------------- window_draw.c | end
*/

/*
**	---------------------------- error.c | start
*/

int					error_log(const char *message);

/*
**	---------------------------- error.c | end
*/

/*
**	---------------------------- pixel.c | start
*/

void				set_pixel(t_window *win, SDL_Color *color, int x, int y);
int					window_within(t_window *win, int x, int y);

/*
**	---------------------------- pixel.c | end
*/

/*
**	---------------------------- window_get.c | start
*/

int window_get_pos(t_window *win, int *x, int *y);
int window_get_size(t_window *win, int *w, int *h);
const char *window_get_title(t_window *win);

/*
**	---------------------------- window_get.c | end
*/

void window_set_pos(t_window *win, int x, int y);
void window_set_size(t_window *win, int w, int h);
void window_set_title(t_window *win, const char *title);

/*
**	---------------------------- window_set.c | start
*/



/*
**	---------------------------- window_set.c | end
*/

#endif
