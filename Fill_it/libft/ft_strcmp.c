/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:12:12 by marvin            #+#    #+#             */
/*   Updated: 2018/11/28 13:44:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ucs1;
	unsigned char	*ucs2;

	ucs1 = (unsigned char*)s1;
	ucs2 = (unsigned char*)s2;
	while (*ucs1 || *ucs2)
	{
		if (*ucs1 != *ucs2)
			return (*ucs1 - *ucs2);
		ucs1++;
		ucs2++;
	}
	return (*ucs1 - *ucs2);
}
