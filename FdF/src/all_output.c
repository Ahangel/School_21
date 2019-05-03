/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:09:37 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 15:57:49 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	controls(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 25, 835, BLU, "<     Controls     >");
	mlx_string_put(env->mlx, env->win, 25, 850, BLU, "                    ");
	mlx_string_put(env->mlx, env->win, 25, 865, BLU, "Move:  Arrows       ");
	mlx_string_put(env->mlx, env->win, 25, 895, BLU, "Zoom:  IN  = 'Q'    ");
	mlx_string_put(env->mlx, env->win, 25, 915, \
			BLU, "       OUT = 'W'   ");
	mlx_string_put(env->mlx, env->win, 25, 945, \
			BLU, "Quit:  ESC           ");
}

void	banner(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 1650, 20, \
			BLU, "/%%%%%%%%% /%%%%%%%%  /%%%%%%%%%");
	mlx_string_put(env->mlx, env->win, 1650, 35, \
			BLU, "| %%_____/ | %%__  %% | %%_____/");
	mlx_string_put(env->mlx, env->win, 1650, 50, \
			BLU, "| %%       | %%  \\ %% | %%");
	mlx_string_put(env->mlx, env->win, 1650, 65, \
			BLU, "| %%%%%    | %%  | %% | %%%%%");
	mlx_string_put(env->mlx, env->win, 1650, 80, \
			BLU, "| %%__/    | %%  | %% | %%__/");
	mlx_string_put(env->mlx, env->win, 1650, 95, \
			BLU, "| %%       | %%  | %% | %%");
	mlx_string_put(env->mlx, env->win, 1650, 110, \
			BLU, "| %%       | %%%%%  / | %%");
	mlx_string_put(env->mlx, env->win, 1650, 125, \
			BLU, "|__/       |_______/  |__/");
}

void	error(int value, t_env *env)
{
	if (value == -1)
		ft_putstr_fd("Error: usage: ./fdf target_file\n", 2);
	else if (value == -2)
		ft_putstr_fd("Error: bad user's input\n", 2);
	else if (value == -3)
		ft_putstr_fd("Error: bad file's size\n", 2);
	if (env->grid)
		ft_memdel((void *)env->grid);
	exit(-1);
}

int		image_loop(t_env *env)
{
	int i;
	int j;

	i = -1;
	mlx_clear_window(env->mlx, env->win);
	controls(env);
	banner(env);
	while (++i < env->height)
	{
		j = 0;
		while (++j < env->width)
			set_bresenham(env, i, j);
	}
	return (0);
}
