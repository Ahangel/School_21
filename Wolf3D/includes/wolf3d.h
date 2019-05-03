/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:16:23 by marvin            #+#    #+#             */
/*   Updated: 2019/03/20 18:34:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WOLF3D_H

# define FT_WOLF3D_H

# include <math.h>
# include <pthread.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "SDL.h"
# include "SDL_image.h"
# include "SDL_mixer.h"

# define MOVE_SPEED 0.12
# define RS 0.1
# define W 1600
# define H 1200
# define THREADS 10
# define NULL_CHECK(val) if (val == NULL) exit(12);
# define TS 64

typedef struct	s_movement
{
	int			forward;
	int			backwards;
	int			rotate_left;
	int			rotate_right;
}				t_movement;

typedef struct	s_pixel
{
	int			x;
	int			y;
	int			color;
}				t_pixel;

typedef struct	s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct	s_wolf
{
	SDL_Window	*window;
	SDL_Surface	*surface;
	SDL_Surface	*textures[6];
	SDL_Surface	*gun;
	SDL_Event	event;
	Mix_Music	*music;
	int			**map;
	int			running;
	int			changed;
	t_movement	movement;
	t_vector	dir;
	t_vector	pos;
	t_vector	plane;
}				t_wolf;

typedef struct	s_ray
{
	t_vector	camera;
	t_vector	dir;
	t_pixel		map;
	t_vector	side_dist;
	t_vector	delta_dist;
	t_pixel		step;
	t_pixel		start_end;
	double		wall_x;
	int			tex_num;
	int			hit;
	int			side;
	double		wall_dist;
	int			lh;
}				t_ray;

typedef struct	s_thread_args
{
	t_wolf		*wolf;
	int			start;
	int			end;
}				t_thread_args;

t_wolf			*create_wolf(char *name);
int				key_hook(t_wolf **wolf);
int				close_window(void *param);
int				read_map(t_wolf **wolf, char *name);
void			set_pixel_to_image(char *data_addr, int size_line,
t_pixel pixel);
void			get_data_addr(t_wolf *wolf);
void			draw_image(t_wolf *wolf);
void			rotate_right(t_wolf **wolf);
void			rotate_left(t_wolf **wolf);
void			move_forward(t_wolf **wolf);
void			move_back(t_wolf **wolf);
int				validate_map(t_wolf *wolf, t_pixel *size);
void			ray(t_wolf *wolf, int i);
int				read_textures(t_wolf **wolf);
void			floor_casting(t_ray ray, t_wolf *wolf, int x);
int				read_music(t_wolf **wolf);
void			*draw_threads(t_wolf *wolf);

#endif
