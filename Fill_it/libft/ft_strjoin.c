/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:55:51 by marvin            #+#    #+#             */
/*   Updated: 2018/11/28 16:31:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*point;

	if (!s1 || !s2)
		return (NULL);
	result = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	point = result;
	if (result == NULL)
		return (NULL);
	while (*s1)
	{
		*point = *s1;
		point++;
		s1++;
	}
	while (*s2)
	{
		*point = *s2;
		point++;
		s2++;
	}
	*point = '\0';
	return (result);
}
