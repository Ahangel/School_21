/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:29:36 by marvin            #+#    #+#             */
/*   Updated: 2018/11/28 16:35:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	result;
	long	res;
	int		is_neg;

	result = 0;
	is_neg = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_neg = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = result;
		result = result * 10 + (*str - '0');
		if (res > result)
			return (is_neg == -1 ? 0 : -1);
		str++;
	}
	return ((int)result * is_neg);
}
