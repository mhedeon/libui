/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmgl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 05:27:49 by mhedeon           #+#    #+#             */
/*   Updated: 2019/04/05 19:19:31 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H

/*
**	Dynamic checking of Operating System
*/
# ifdef _APPLE_
#  include "SDL.h"
#  include "SDL_image.h"
#  include "SDL_ttf.h"
#  include "SDL_mixer.h"
#  include <unistd.h>
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
#  include <unistd.h>
# endif

/*
**	Standart libraries
*/
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

/*
**	Parts of libmgl
*/
# include "window.h"
# include "ttf.h"
# include "checkbox.h"
# include "color.h"
# include "slider.h"
# include "color_picker.h"
# include "screenshot.h"

# define INVALID_POINTER 0xFF

# define KEY(e, k) (e.type == SDL_KEYDOWN && e.key.keysym.sym == k)
# define QUIT (e.type == SDL_QUIT)

#endif
