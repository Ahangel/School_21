/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:05:12 by marvin            #+#    #+#             */
/*   Updated: 2018/11/28 16:28:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	char	*point;

	if (!s || !f)
		return (NULL);
	result = (char*)malloc(ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	point = result;
	while (*s)
	{
		*point = f(*s);
		point++;
		s++;
	}
	*point = '\0';
	return (result);
}
