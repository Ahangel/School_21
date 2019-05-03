/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:14:08 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 15:56:13 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len2;

	if (*needle == '\0')
		return ((char *)haystack);
	len2 = ft_strlen(needle);
	while (*haystack != '\0' && len-- >= len2)
	{
		if (ft_memcmp(haystack, needle, len2) == 0 && *haystack == *needle)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
