/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:21:57 by marvin            #+#    #+#             */
/*   Updated: 2018/11/30 14:29:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if ((char*)dst > (char*)src)
	{
		len--;
		while ((int)(len) >= 0)
		{
			*((char*)dst + len) = *((char*)src + len);
			len--;
		}
	}
	else
	{
		while (i < (int)len)
		{
			*((char*)dst + i) = *((char*)src + i);
			i++;
		}
	}
	return (dst);
}
