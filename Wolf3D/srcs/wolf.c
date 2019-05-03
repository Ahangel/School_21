/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:24:40 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/03/17 18:57:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_wolf	*create_wolf(char *name)
{
	t_wolf	*wolf;

	SDL_Init(SDL_INIT_EVERYTHING);
	wolf = (t_wolf *)ft_memalloc(sizeof(t_wolf));
	wolf->running = 1;
	wolf->pos.x = 0.0;
	wolf->pos.y = 0.0;
	wolf->dir.x = -1.0;
	wolf->dir.y = 0.0;
	wolf->plane.x = 0;
	wolf->plane.y = 0.66;
	wolf->movement.rotate_right = 0;
	wolf->movement.rotate_left = 0;
	wolf->movement.forward = 0;
	wolf->movement.backwards = 0;
	if (!read_map(&wolf, name) || !read_textures(&wolf) || !read_music(&wolf))
		return (NULL);
	Mix_PlayMusic(wolf->music, -1);
	wolf->window = SDL_CreateWindow("wolf3d", SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, W, H, SDL_WINDOW_ALLOW_HIGHDPI);
	wolf->surface = SDL_GetWindowSurface(wolf->window);
	return (wolf);
}
