/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:28:16 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 15:54:32 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qs(char *items, int left, int right)
{
	int		i;
	int		j;
	char	x;
	char	y;

	i = left;
	j = right;
	x = items[(left + right) / 2];
	while (i <= j)
	{
		while ((items[i++] < x) && (i < right))
			;
		while ((x < items[j--]) && (j > left))
			;
		if (i++ <= j--)
		{
			y = items[i];
			items[i] = items[j];
			items[j] = y;
		}
	}
	if (left < j)
		ft_qs(items, left, j);
	if (i < right)
		ft_qs(items, i, right);
}
