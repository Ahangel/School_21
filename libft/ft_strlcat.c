/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:43:07 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 15:55:58 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*destination;
	const char	*source;
	size_t		size_n;
	size_t		dest_len;

	destination = dst;
	source = src;
	size_n = size;
	while (size_n-- != 0 && *destination != '\0')
		destination++;
	dest_len = destination - dst;
	size_n = size - dest_len;
	if (size_n == 0)
		return (dest_len + ft_strlen(source));
	while (*source)
	{
		if (size_n != 1)
		{
			*destination++ = *source;
			size_n--;
		}
		source++;
	}
	*destination = '\0';
	return (dest_len + (source - src));
}
