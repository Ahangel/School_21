/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:13:19 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 15:54:27 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	long_n;

	long_n = n;
	if (long_n < 0)
	{
		ft_putchar('-');
		long_n = -long_n;
	}
	if (long_n >= 10)
	{
		ft_putnbr(long_n / 10);
		ft_putnbr(long_n % 10);
	}
	else
		ft_putchar(long_n + '0');
}
