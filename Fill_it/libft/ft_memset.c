/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 09:59:08 by marvin            #+#    #+#             */
/*   Updated: 2018/11/26 10:27:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*str;

	str = (char*)b;
	i = 0;
	while (i < (int)len)
	{
		*str = (unsigned char)c;
		i++;
		str++;
	}
	return (b);
}
