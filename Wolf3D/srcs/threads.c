/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:58:55 by marvin            #+#    #+#             */
/*   Updated: 2019/03/20 16:19:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_thread_args	*create_args(t_wolf *wolf, int start, int end)
{
	t_thread_args *args;

	NULL_CHECK((args = ft_memalloc(sizeof(t_thread_args))));
	args->wolf = wolf;
	args->start = start;
	args->end = end;
	return (args);
}

static void				*draw_rays_thread(void *param)
{
	int				i;
	t_thread_args	*args;

	args = (t_thread_args*)param;
	i = args->start;
	while (i < args->end)
	{
		ray(args->wolf, i);
		i++;
	}
	return (NULL);
}

static void				draw_gun(t_wolf *wolf)
{
	t_pixel	iw;
	t_pixel	it;
	Uint32	tr;

	tr = *(Uint32*)wolf->gun->pixels + (0 * 128 + 0)
			* wolf->surface->format->BytesPerPixel;
	it.y = -1;
	iw.y = H - 512;
	while (++it.y < 512)
	{
		it.x = -1;
		iw.x = W / 2 - 256;
		while (++it.x < 512)
		{
			if (tr != *(Uint32*)(wolf->gun->pixels + (it.y * 512 + it.x)
			* wolf->surface->format->BytesPerPixel))
				*(Uint32*)(wolf->surface->pixels + (iw.y * W + iw.x)
				* wolf->surface->format->BytesPerPixel) = *(Uint32*)
				(wolf->gun->pixels + (it.y * 512 + it.x)
				* wolf->surface->format->BytesPerPixel);
			iw.x++;
		}
		iw.y++;
	}
}

void					*draw_threads(t_wolf *wolf)
{
	t_thread_args	*args;
	int				start;
	int				end;
	pthread_t		id_arr[THREADS];
	int				i;

	i = -1;
	start = 0;
	end = W / THREADS;
	while (++i < THREADS)
	{
		args = create_args(wolf, start, end);
		pthread_create(&(id_arr[i]), NULL, &draw_rays_thread, args);
		start = end;
		end = end + W / THREADS;
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(id_arr[i], NULL);
	draw_gun(wolf);
	SDL_UpdateWindowSurface(wolf->window);
	return (NULL);
}

/*
** void					*draw_SDL_threads(t_wolf *wolf)
**{
**	t_thread_args	*args;
**	int				start;
**	int				end;
**	SDL_Thread		*id_arr[THREADS];
**	int				i;
**
**	i = -1;
**	start = 0;
**	end = W / THREADS;
**	while (++i < THREADS)
**	{
**		args = create_args(wolf, start, end);
**		id_arr[i] = SDL_CreateThread(draw_rays_thread, NULL, args);
**		start = end + 1;
**		end = end + W / THREADS;
**	}
**	i = -1;
**	while (++i < THREADS)
**		SDL_WaitThread(id_arr[i], NULL);
**	draw_gun(wolf);
**	SDL_UpdateWindowSurface(wolf->window);
**	return (NULL);
**}
*/
