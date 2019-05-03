/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:21:55 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 15:53:40 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		ft_binary_search(char *items, int array_size, char key)
{
	int		low;
	int		high;
	int		mid;

	low = 0;
	high = array_size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key < items[mid])
			high = mid - 1;
		else if (key > items[mid])
			low = mid + 1;
		else
			return (mid);
	}
	return (-1);
}
