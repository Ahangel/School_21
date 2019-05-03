/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:10:01 by marvin            #+#    #+#             */
/*   Updated: 2019/03/17 15:27:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		define_side(t_ray ray, t_vector *floor_wall)
{
	if (ray.side == 0 && ray.dir.x > 0)
	{
		floor_wall->x = ray.map.x;
		floor_wall->y = ray.map.y + ray.wall_x;
	}
	else if (ray.side == 0 && ray.dir.x <= 0)
	{
		floor_wall->x = ray.map.x + 1.0;
		floor_wall->y = ray.map.y + ray.wall_x;
	}
	else if (ray.side == 1 && ray.dir.y > 0)
	{
		floor_wall->x = ray.map.x + ray.wall_x;
		floor_wall->y = ray.map.y;
	}
	else
	{
		floor_wall->x = ray.map.x + ray.wall_x;
		floor_wall->y = ray.map.y + 1.0;
	}
}

static void		draw_pixel(t_ray ray, t_wolf *wolf,
							t_pixel pixel, t_vector floor_wall)
{
	double		current_dist;
	double		weigth;
	t_vector	current_floor;
	t_pixel		floor_tex;

	current_dist = H / (2.0 * pixel.y - H);
	weigth = current_dist / ray.wall_dist;
	current_floor.x = weigth * floor_wall.x + (1.0 - weigth) * wolf->pos.x;
	current_floor.y = weigth * floor_wall.y + (1.0 - weigth) * wolf->pos.y;
	floor_tex.x = (int)(current_floor.x * TS) % TS;
	floor_tex.y = (int)(current_floor.y * TS) % TS;
	*(Uint32*)(wolf->surface->pixels + (pixel.y * W + pixel.x)
	* wolf->surface->format->BytesPerPixel) =
	*(Uint32*)(wolf->textures[4]->pixels + (TS * floor_tex.y + floor_tex.x)
	* wolf->textures[4]->format->BytesPerPixel);
	*(Uint32*)(wolf->surface->pixels + ((H - pixel.y) * W + pixel.x)
	* wolf->surface->format->BytesPerPixel) =
	*(Uint32*)(wolf->textures[5]->pixels + (TS * floor_tex.y + floor_tex.x)
	* wolf->textures[5]->format->BytesPerPixel);
}

void			floor_casting(t_ray ray, t_wolf *wolf, int x)
{
	t_vector	floor_wall;
	double		dist_wall;
	double		dist_player;
	t_pixel		pixel;

	define_side(ray, &floor_wall);
	if (ray.start_end.y < 0)
		ray.start_end.y = H;
	pixel.y = ray.start_end.y + 1;
	pixel.x = x;
	dist_wall = ray.wall_dist;
	dist_player = 0.0;
	while (pixel.y < H)
	{
		draw_pixel(ray, wolf, pixel, floor_wall);
		pixel.y++;
	}
}
