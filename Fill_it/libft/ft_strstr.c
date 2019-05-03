/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:16:57 by marvin            #+#    #+#             */
/*   Updated: 2018/11/28 14:16:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		len;

	len = ft_strlen(needle);
	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack)
	{
		if (ft_strncmp(haystack, needle, len) == 0)
		{
			return ((char*)haystack);
		}
		haystack++;
	}
	return (NULL);
}
