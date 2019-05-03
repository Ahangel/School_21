/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacgyve <fmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:13:00 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/02/28 15:12:53 by fmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	check_horizontal_borders(t_wolf *wolf, t_pixel *size)
{
	t_pixel iter;

	iter.y = 0;
	iter.x = 0;
	while (iter.x < size->x)
	{
		if (wolf->map[iter.y][iter.x] != 1)
			return (0);
		iter.x++;
	}
	iter.y = size->y - 1;
	iter.x = 0;
	while (iter.x < size->x)
	{
		if (wolf->map[iter.y][iter.x] != 1)
			return (0);
		iter.x++;
	}
	return (1);
}

static void	set_initial_pos(t_wolf *wolf, t_pixel pos)
{
	if (!wolf->pos.x && !wolf->pos.y)
	{
		wolf->pos.x = pos.x + 0.5;
		wolf->pos.y = pos.y + 0.5;
	}
	wolf->map[pos.y][pos.x] = 0;
}

int			validate_map(t_wolf *wolf, t_pixel *size)
{
	t_pixel i;

	if (!check_horizontal_borders(wolf, size))
		return (0);
	i.y = 0;
	while (++i.y < size->y - 1)
	{
		i.x = 0;
		if (wolf->map[i.y][0] != 1 || wolf->map[i.y][size->x - 1] != 1)
			return (0);
		while (++i.x <= size->x - 1)
		{
			if (wolf->map[i.y][i.x] != -1 && wolf->map[i.y][i.x] != 1 &&
				wolf->map[i.y][i.x] != 0)
				return (0);
			if (wolf->map[i.y][i.x] == -1 && !wolf->pos.x && !wolf->pos.y)
				set_initial_pos(wolf, i);
			else if (wolf->map[i.y][i.x] == -1 && wolf->pos.x && wolf->pos.y)
				return (0);
		}
	}
	if (!wolf->pos.x && !wolf->pos.y)
		return (0);
	return (1);
}
