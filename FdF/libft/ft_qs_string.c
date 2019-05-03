/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qs_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:35:20 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 15:54:31 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qs_string(char items[][10], int left, int right)
{
	int		i;
	int		j;
	char	*x;
	char	temp[10];

	i = left;
	j = right;
	x = items[(left + right) / 2];
	while (i <= j)
	{
		while ((ft_strcmp(items[i++], x) < 0) && (i < right))
			;
		while ((ft_strcmp(items[j--], x) > 0) && (j > left))
			;
		if (i++ <= j--)
		{
			ft_strcpy(temp, items[i]);
			ft_strcpy(items[i], items[j]);
			ft_strcpy(items[j], temp);
		}
	}
	if (left < j)
		ft_qs_string(items, left, j);
	if (i < right)
		ft_qs_string(items, i, right);
}
