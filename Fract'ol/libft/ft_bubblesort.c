/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:09:43 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 15:53:41 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bubblesort(char *str, int count)
{
	int		a;
	int		b;
	char	t;

	a = 1;
	while (a++ < count)
	{
		b = count - 1;
		while (b-- >= a)
			if (str[b - 1] > str[b])
			{
				t = str[b - 1];
				str[b - 1] = str[b];
				str[b] = t;
			}
	}
}
