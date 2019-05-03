/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:51:36 by marvin            #+#    #+#             */
/*   Updated: 2018/11/30 14:04:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*end;
	char	*result;
	char	*copy;

	if (s == NULL)
		return (NULL);
	copy = (char*)s;
	while (*s == ' ' || *s == '\n' || *s == '\t' || *s == '\0')
	{
		if (*s == '\0')
		{
			if (!(result = ft_strsub(copy, 0, 0)))
				return (NULL);
			return (result);
		}
		s++;
	}
	end = (char*)s + ft_strlen(s) - 1;
	while (*end == ' ' || *end == '\n' || *end == '\t')
	{
		end--;
	}
	if (!(result = ft_strsub(s, 0, end - s + 1)))
		return (NULL);
	return (result);
}
