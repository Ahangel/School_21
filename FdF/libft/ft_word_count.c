/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:21:20 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 15:56:25 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_word_count(char *str)
{
	int c;
	int i;

	if (str == NULL || str[0] == '\0')
		return (0);
	c = 0;
	if (!ft_isspace(str[0]))
		c = 1;
	i = 1;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i - 1]) && !ft_isspace(str[i]))
			c++;
		i++;
	}
	return (c);
}
