/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:01:50 by marvin            #+#    #+#             */
/*   Updated: 2018/11/29 16:35:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power(int num, int power)
{
	int		i;
	int		res;

	i = 0;
	res = 1;
	while (i < power)
	{
		res *= num;
		i++;
	}
	return (res);
}

static int	ft_count(int n)
{
	int		count;

	count = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	ft_get_char(int n, int len)
{
	return ((n / ft_power(10, len - 1)) % 10 + '0');
}

static char	*ft_get_str(int n, int len, char *head, int is_neg)
{
	char	*result;

	result = head;
	if (is_neg)
	{
		*head = '-';
		head++;
	}
	while (len > 0)
	{
		*head = ft_get_char(n, len);
		len--;
		head++;
	}
	*head = '\0';
	return (result);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*result;
	int		is_neg;
	char	*int_min;

	is_neg = 0;
	len = ft_count(n);
	if (n == -2147483648)
	{
		int_min = ft_strsub("-2147483648", 0, 12);
		if (int_min == NULL)
			return (NULL);
		return (int_min);
	}
	if (n < 0)
	{
		is_neg = 1;
		n *= -1;
		result = (char*)malloc(len + 2);
	}
	else
		result = (char*)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	return (ft_get_str(n, len, result, is_neg));
}
