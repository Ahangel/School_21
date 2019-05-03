/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:32:01 by marvin            #+#    #+#             */
/*   Updated: 2018/11/28 16:37:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t			i;
	unsigned char	*ucs1;
	unsigned char	*ucs2;

	i = 0;
	ucs1 = (unsigned char*)s1;
	ucs2 = (unsigned char*)s2;
	while (*(ucs1 + i) && *(ucs2 + i) && i < n)
	{
		if (*(ucs1 + i) != *(ucs2 + i))
			return (*(ucs1 + i) - *(ucs2 + i));
		i++;
	}
	if (i >= n)
		return (0);
	else
		return (*(ucs1 + i) - *(ucs2 + i));
}
