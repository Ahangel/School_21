/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:01:56 by marvin            #+#    #+#             */
/*   Updated: 2018/11/28 16:37:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (*(haystack + i) && i < len)
	{
		while (*(haystack + i + j) == *(needle + j)
				&& i + j < len && j < ft_strlen(needle))
		{
			j++;
		}
		if (j >= ft_strlen(needle))
			return ((char*)(haystack + i));
		j = 0;
		i++;
	}
	return (NULL);
}
