/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:17:36 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/03/17 18:56:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static SDL_Surface	*create_surface(int width, int heigth)
{
	SDL_Surface	*surface;
	Uint32		rmask;
	Uint32		gmask;
	Uint32		bmask;
	Uint32		amask;

	rmask = 0x000000ff;
	gmask = 0x0000ff00;
	bmask = 0x00ff0000;
	amask = 0xff000000;
	surface = SDL_CreateRGBSurface(0, width, heigth, 32,
									rmask, gmask, bmask, amask);
	return (surface);
}

static void			set_pixel(SDL_Surface *gun, SDL_Surface *new_gun,
						t_pixel gi, t_pixel *ngi)
{
	*(Uint32*)(new_gun->pixels + (ngi->y * 128 * 4 + ngi->x)
	* new_gun->format->BytesPerPixel) = *(Uint32*)(gun->pixels
	+ (gi.y * 128 + gi.x) * new_gun->format->BytesPerPixel);
	ngi->x++;
}

static SDL_Surface	*resize_gun(SDL_Surface *gun)
{
	SDL_Surface	*new_gun;
	t_pixel		gi;
	t_pixel		ngi;
	t_pixel		iter_zoom;

	new_gun = create_surface(512, 512);
	gi.y = -1;
	ngi.y = 0;
	while (++gi.y < 128)
	{
		iter_zoom.y = -1;
		while (++iter_zoom.y < 4)
		{
			gi.x = -1;
			ngi.x = 0;
			while (++gi.x < 128)
			{
				iter_zoom.x = -1;
				while (++iter_zoom.x < 4)
					set_pixel(gun, new_gun, gi, &ngi);
			}
			ngi.y++;
		}
	}
	return (new_gun);
}

static int			load_texture(t_wolf **wolf, int i, char *name)
{
	(*wolf)->textures[i] = SDL_ConvertSurfaceFormat(IMG_Load(name),
							SDL_PIXELFORMAT_ARGB8888, 0);
	if (!((*wolf)->textures[i]) || (*wolf)->textures[i]->w != TS
		|| (*wolf)->textures[i]->h != TS)
		return (0);
	return (1);
}

int					read_textures(t_wolf **wolf)
{
	SDL_Surface *gun;

	IMG_Init(IMG_INIT_PNG);
	if (!load_texture(wolf, 0, "assets/textures/colorstone.png") ||
	!load_texture(wolf, 1, "assets/textures/bluestone.png") ||
	!load_texture(wolf, 2, "assets/textures/mossy.png") ||
	!load_texture(wolf, 3, "assets/textures/redbrick.png") ||
	!load_texture(wolf, 4, "assets/textures/greystone.png") ||
	!load_texture(wolf, 5, "assets/textures/wood.png"))
		return (0);
	gun = IMG_Load("assets/textures/gun.png");
	gun = SDL_ConvertSurfaceFormat(gun, SDL_PIXELFORMAT_ARGB8888, 0);
	if (!((*wolf)->textures[0]) || !((*wolf)->textures[1]) ||
		!((*wolf)->textures[2]) || !((*wolf)->textures[3]) ||
		!((*wolf)->textures[4]) || !((*wolf)->textures[5]) || !gun)
		return (0);
	(*wolf)->gun = resize_gun(gun);
	return (1);
}
