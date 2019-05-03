/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 00:28:10 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 15:54:12 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numcount(const char *s)
{
	int count;
	int i;

	count = 0;
	i = -1;
	while (s[++i])
		if (ft_isdigit(s[i]) && !ft_isdigit(s[i + 1]))
			count++;
	return (count);
}
