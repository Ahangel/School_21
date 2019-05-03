/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:42:22 by marvin            #+#    #+#             */
/*   Updated: 2018/11/28 12:20:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		if (*(src + i))
		{
			*(dst + i) = *(src + i);
			i++;
		}
		else
		{
			while (i < len)
			{
				*(dst + i) = '\0';
				i++;
			}
		}
	}
	return (dst);
}
