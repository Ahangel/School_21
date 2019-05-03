/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:33:25 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 15:55:37 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_realloc(char **s1, size_t n)
{
	char	*s2;

	if (!(s2 = ft_strnew(ft_strlen(*s1))))
		return (0);
	ft_strcpy(s2, *s1);
	free(*s1);
	if (!(*s1 = ft_strnew(ft_strlen(s2) + n)))
		return (0);
	ft_strcpy(*s1, s2);
	free(s2);
	return (1);
}
