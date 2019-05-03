/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:19:26 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/03/20 18:37:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	clean_up(t_wolf *wolf)
{
	int i;

	i = -1;
	while (++i < 6)
		SDL_FreeSurface(wolf->textures[i]);
	SDL_FreeSurface(wolf->gun);
	Mix_FreeMusic(wolf->music);
	Mix_CloseAudio();
	SDL_DestroyWindow(wolf->window);
	Mix_Quit();
	SDL_Quit();
}

void		process_error(void)
{
	const char	*sdl_error;

	sdl_error = SDL_GetError();
	if (*sdl_error && *sdl_error != '\n')
		ft_putendl(sdl_error);
	else
		ft_putendl("invalid map");
	exit(0);
}

void		lsync(void)
{
	int						delay;
	static unsigned int		time;
	static char				vsync = 1;

	vsync == 1 ? SDL_GL_SetSwapInterval(1) : 0;
	if (vsync)
	{
		delay = 16 - (SDL_GetTicks() - time);
		if (delay < 0)
			SDL_Delay(0);
		else
			SDL_Delay(delay);
		time = SDL_GetTicks();
	}
}

int			main(int argc, char **argv)
{
	t_wolf		*wolf;

	if (argc == 2)
	{
		wolf = create_wolf(argv[1]);
		if (!wolf)
			process_error();
		SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
		SDL_EventState(SDL_MOUSEBUTTONDOWN, SDL_IGNORE);
		SDL_EventState(SDL_MOUSEBUTTONUP, SDL_IGNORE);
		while (wolf->running)
		{
			if (SDL_WaitEvent(&(wolf->event)) >= 0)
			{
				key_hook(&wolf);
				draw_threads(wolf);
			}
		}
		clean_up(wolf);
	}
	else
		ft_putendl("usage: ./wolf3d [map_name]");
	return (0);
}
