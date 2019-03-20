#ifndef WINDOW_H
# define WINDOW_H

# ifndef _APPLE_
#  include "SDL.h"
#  include "SDL_image.h"
#  include "SDL_ttf.h"
#  include "SDL_mixer.h"
# elif _WIN32
#  include <SDL.h>
#  include <SDL_image.h>
#  include <SDL_ttf.h>
#  include <SDL_mixer.h>
# elif _linux_
#  include "SDL.h"
#  include "SDL_image.h"
#  include "SDL_ttf.h"
#  include "SDL_mixer.h"
# endif
# include <stdio.h>
# include <stdlib.h>

// # define KEY e.type == SDL_KEYDOWN && e.key.keysym.sym
// # define L_CLICK SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)
// # define R_CLICK SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT)

typedef struct		s_window
{
	int				w;
	int				h;
	SDL_Window*		win;
	SDL_Renderer*	ren;
	SDL_Texture*	tex;
	Uint32*			buff;
	SDL_Color		color;
}					t_window;

/*
**	win.c | start
*/

/*
**	\brief Creates a new ready-to-drawing window.
**	\param title The title of the window? in UTF-8 encoding.
**	\param w Width of the window.
**	\param h Height of the window.
**	\return Structure with window, renderer, texture,
**	and buffer, or NULL if creation failed.
**	\note Default position of the window if SDL_WINDOWPOS_CENTERED.
*/
t_window* create_win(char* title, int w, int h);

/*
**	\brief Destroy the specified structure and sets the pointer to NULL.
**	\param win Double pointer to t_window structure.
**	\note Sets the poiner to NULL
*/
void close_win(t_window** win);

/*
**	\brief Draws the context on the window.
**	\param win Pointer to t_window structure.
**	\note buffer -> texture -> render.
*/
void	upd_win(t_window* win);

/*
**	\brief Draws a part the context on the window.
**	\param win Pointer to t_window structure.
**	\param r A pointer to the rectangular of pixels to update.
**	\note Updates a part of the texture from the buffer.
**	Copies the entire texture into a renderer with a previous renderer cleanup.
*/
void			upd_area_tex(t_window* win, SDL_Rect* r);

/*
**	\brief Draws a part the context on the window.
**	\param win Pointer to t_window structure.
**	\param r A pointer to the rectangular of pixels to update.
**	\note Updates entire texture from the buffer.
**	Copies a part of the texture to the same part of the renderer
**	without a previous renderer cleanup.
*/
void			upd_area_ren(t_window* win, SDL_Rect* r);

/*
**	win.c | end
*/

/*
**	draw.c | start
*/
int				error_log(char* message);
void	set_pixel(t_window* win, SDL_Color* color, int x, int y);
void  clear_area(t_window* win, SDL_Rect* area);
void color_area(t_window* win, SDL_Rect* area, SDL_Color* color);
void	clear_buffer(t_window* win);
void	color_buffer(t_window* win, SDL_Color* color);
/*
**	draw.c | end
*/

#endif
