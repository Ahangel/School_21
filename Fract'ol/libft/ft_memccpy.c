/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:44:23 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 15:54:03 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*source;
	unsigned int		i;
	unsigned char		j;

	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	i = 0;
	j = (unsigned char)c;
	while (i < n)
	{
		if ((*dest++ = *source++) == j)
			return (dest);
		i++;
	}
	return (NULL);
}
