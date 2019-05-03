/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:06:35 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/03/05 18:24:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	move_forward
**	move_back
**	Functions for moving in maze
*/

void	move_forward(t_wolf **wolf)
{
	if ((*wolf)->map[(int)(*wolf)->pos.y]
				[(int)((*wolf)->pos.x + (*wolf)->dir.x * MOVE_SPEED)] == 0)
		(*wolf)->pos.x += (*wolf)->dir.x * MOVE_SPEED;
	if ((*wolf)->map[(int)((*wolf)->pos.y + (*wolf)->dir.y * MOVE_SPEED)]
				[(int)((*wolf)->pos.x)] == 0)
		(*wolf)->pos.y += (*wolf)->dir.y * MOVE_SPEED;
}

void	move_back(t_wolf **wolf)
{
	if ((*wolf)->map[(int)(*wolf)->pos.y]
				[(int)((*wolf)->pos.x - (*wolf)->dir.x * MOVE_SPEED)] == 0)
		(*wolf)->pos.x -= (*wolf)->dir.x * MOVE_SPEED;
	if ((*wolf)->map[(int)((*wolf)->pos.y - (*wolf)->dir.y * MOVE_SPEED)]
				[(int)((*wolf)->pos.x)] == 0)
		(*wolf)->pos.y -= (*wolf)->dir.y * MOVE_SPEED;
}
