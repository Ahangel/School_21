/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:18:38 by marvin            #+#    #+#             */
/*   Updated: 2019/03/05 17:25:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	read_music(t_wolf **wolf)
{
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	(*wolf)->music = Mix_LoadMUS("assets/music.ogg");
	if (!((*wolf)->music))
		return (0);
	return (1);
}
