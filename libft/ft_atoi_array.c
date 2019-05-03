/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 00:28:10 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 15:53:38 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_atoi_array(const char *s)
{
	int *ret;
	int i;

	ret = (int *)ft_memalloc((ft_numcount(s) * sizeof(int)) + 1);
	i = 0;
	while (*s)
	{
		if (*s == '-' || ft_isdigit(*s))
			ret[++i] = ft_atoi(s);
		s = ((ft_strclen(s, ' ')) ? s + ft_strclen(s, ' ') : s + 1);
	}
	ret[0] = i;
	return (ret);
}
