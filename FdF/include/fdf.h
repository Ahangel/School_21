/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:11:16 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 15:53:35 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define SIZE env->size
# define OFF_X env.horz
# define OFF_Y env.vert

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../minilibx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_ZOOM_IN 12
# define KEY_ZOOM_OUT 13

# define BLU 0x0099FF
# define GRE 0x83F52C
# define YEL 0xF3F315
# define RED 0xFF0099

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				x1;
	int				y1;
	int				height;
	int				width;
	int				vert;
	int				horz;
	int				top;
	int				size;
	int				x2;
	int				y2;
	int				z;
	int				delt_x;
	int				delt_y;
	int				**grid;
}					t_env;

int					fdf(char *s);
int					image_loop(t_env *env);
t_env				parsing(int fd);
t_env				organize_bresenham(t_env env);
void				error(int value, t_env *env);
void				controls(t_env *env);
void				banner(t_env *env);
void				set_bresenham(t_env *env, int i, int j);
void				run_bresenham(t_env env);

#endif
