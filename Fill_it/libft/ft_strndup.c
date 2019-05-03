/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:41:02 by marvin            #+#    #+#             */
/*   Updated: 2018/11/27 17:27:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dest;
	char	*result;
	int		i;

	i = 0;
	dest = (char*)malloc(n + 1);
	if (dest == NULL)
		return (NULL);
	result = dest;
	while (*s1 && i < (int)n)
	{
		*dest = *s1;
		dest++;
		s1++;
		i++;
	}
	*dest = '\0';
	return (result);
}
