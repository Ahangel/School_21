/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:50:09 by marvin            #+#    #+#             */
/*   Updated: 2018/11/30 14:29:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*point;

	if (!dst && !src)
		return (NULL);
	i = 0;
	point = (char*)dst;
	while (i < (int)n)
	{
		*point = *((char*)src);
		src++;
		point++;
		i++;
	}
	return (dst);
}
