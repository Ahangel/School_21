/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:08:38 by marvin            #+#    #+#             */
/*   Updated: 2018/11/25 15:13:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*lstchr;

	lstchr = NULL;
	while (*s)
	{
		if (*s == c)
			lstchr = (char*)s;
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	else
		return (lstchr);
}
