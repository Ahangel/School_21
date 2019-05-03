/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:34:12 by marvin            #+#    #+#             */
/*   Updated: 2018/11/30 12:57:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	j = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	while (*(dst + i))
	{
		i++;
	}
	while (*(src + j) && i + j < size - 1)
	{
		*(dst + i + j) = *(src + j);
		j++;
	}
	*(dst + i + j) = '\0';
	if (size < ft_strlen(dst))
		return (srclen + size);
	else
		return (srclen + dstlen);
}
