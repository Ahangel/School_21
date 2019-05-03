/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:40:50 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/03/20 18:34:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	key_hook
**	Hooks for pressing keys on keyboard
*/

int		key_hook(t_wolf **wolf)
{
	if ((*wolf)->event.key.keysym.scancode == SDL_SCANCODE_D)
		rotate_right(wolf);
	else if ((*wolf)->event.key.keysym.scancode == SDL_SCANCODE_A)
		rotate_left(wolf);
	else if ((*wolf)->event.key.keysym.scancode == SDL_SCANCODE_W)
		move_forward(wolf);
	else if ((*wolf)->event.key.keysym.scancode == SDL_SCANCODE_S)
		move_back(wolf);
	if ((SDL_QUIT == (*wolf)->event.type) || (SDL_KEYDOWN == (*wolf)->event.type
				&& SDL_SCANCODE_ESCAPE == (*wolf)->event.key.keysym.scancode))
		(*wolf)->running = 0;
	return (0);
}
