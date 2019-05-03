/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:07:23 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 16:14:58 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_env	organize_bresenham(t_env env)
{
	env.z = abs(env.x1 - env.x2) < abs(env.y1 - env.y2) ? 1 : 0;
	if (env.z)
	{
		ft_swap(&env.x1, &env.y1);
		ft_swap(&env.x2, &env.y2);
	}
	if (env.x1 > env.x2)
	{
		ft_swap(&env.y1, &env.y2);
		ft_swap(&env.x1, &env.x2);
	}
	env.delt_x = env.x2 - env.x1;
	env.delt_y = env.y2 - env.y1;
	return (env);
}

void	run_bresenham(t_env env)
{
	int m_new;
	int slope;
	int x;
	int y;

	m_new = abs(env.delt_y) * 2;
	slope = 0;
	x = env.x1 - 1;
	y = env.y1;
	while (++x <= env.x2)
	{
		if (env.z)
			mlx_pixel_put(env.mlx, env.win, y + OFF_X, x + OFF_Y, RED);
		else if (env.top)
			mlx_pixel_put(env.mlx, env.win, x + OFF_X, y + OFF_Y, BLU);
		else
			mlx_pixel_put(env.mlx, env.win, x + OFF_X, y + OFF_Y, YEL);
		if (((slope += m_new)) > env.delt_x)
		{
			y += (env.delt_y < 0 ? -1 : 1);
			slope -= env.delt_x * 2;
		}
	}
}

void	set_bresenham(t_env *env, int i, int j)
{
	env->top = env->grid[i][j];
	env->x1 = (j * SIZE) + (i * SIZE);
	env->y1 = ((i * SIZE) / 2) - (((j * SIZE) + (SIZE * env->top)) / 2);
	if (j < env->width - 1)
	{
		env->x2 = ((j + 1) * SIZE) + (i * SIZE);
		env->y2 = ((i * SIZE) / 2) - ((((j + 1) * SIZE) + \
					(SIZE * env->grid[i][j + 1])) / 2);
		run_bresenham(organize_bresenham(*env));
	}
	if (i < env->height - 1)
	{
		env->x2 = (j * SIZE) + ((i + 1) * SIZE);
		env->y2 = (((i + 1) * SIZE) / 2) - (((j * SIZE) + \
					(SIZE * env->grid[i + 1][j])) / 2);
		run_bresenham(organize_bresenham(*env));
	}
}
