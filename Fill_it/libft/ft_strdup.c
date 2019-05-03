/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:00:31 by marvin            #+#    #+#             */
/*   Updated: 2018/11/27 16:41:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	char	*result;
	size_t	len;

	len = ft_strlen(s1);
	dest = (char*)malloc((int)len + 1);
	if (dest == NULL)
		return (NULL);
	result = dest;
	while (*s1)
	{
		*dest = *s1;
		dest++;
		s1++;
	}
	*dest = '\0';
	return (result);
}
