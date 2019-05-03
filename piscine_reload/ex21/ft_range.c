/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:05:39 by crath             #+#    #+#             */
/*   Updated: 2018/11/20 16:24:50 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		i;
	int		*tmp;

	i = 0;
	if (min >= max)
		return (NULL);
	tmp = (int *)malloc(sizeof(*tmp) * (max - min));
	while (min < max)
	{
		tmp[i] = min;
		i++;
		min++;
	}
	return (tmp);
}
