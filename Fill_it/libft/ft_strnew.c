/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:00:32 by marvin            #+#    #+#             */
/*   Updated: 2018/12/01 18:47:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*result;
	char	*point;
	int		i;

	i = 0;
	if (size == 2147483647)
		return (NULL);
	result = (char*)malloc((int)size + 1);
	if (result == NULL)
		return (NULL);
	point = result;
	while (i < (int)size + 1)
	{
		*point = '\0';
		point++;
		i++;
	}
	return (result);
}
