/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 05:21:59 by mhedeon           #+#    #+#             */
/*   Updated: 2019/03/31 05:22:07 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	upd_win(t_window *win)
{
	SDL_UpdateTexture(win->tex, NULL, win->buff,
		win->w * sizeof(Uint32));
	SDL_RenderClear(win->ren);
	SDL_RenderCopy(win->ren, win->tex, NULL, NULL);
	SDL_RenderPresent(win->ren);
}
