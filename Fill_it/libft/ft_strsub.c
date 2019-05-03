/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:46:13 by marvin            #+#    #+#             */
/*   Updated: 2018/11/30 14:28:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*result;
	char				*point;

	i = 0;
	if (!s || len == 2147483647)
		return (NULL);
	result = (char*)malloc((int)len + 1);
	if (result == NULL)
		return (NULL);
	point = result;
	while (i < start && start != 0)
	{
		s++;
		i++;
	}
	i = 0;
	while (i < (unsigned int)len)
	{
		*(point + i) = *(s + i);
		i++;
	}
	*(point + i) = '\0';
	return (result);
}
