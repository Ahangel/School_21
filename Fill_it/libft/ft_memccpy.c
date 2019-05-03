/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:36:48 by marvin            #+#    #+#             */
/*   Updated: 2018/11/29 17:09:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int		i;

	i = 0;
	while (i < (int)n)
	{
		*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
		if (*((unsigned char*)(src + i)) == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
