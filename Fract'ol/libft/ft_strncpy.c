/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:09:33 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 15:56:08 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *start;

	start = dst;
	while (len && (*dst++ = *src++))
		len--;
	if (len)
		while (--len)
			*dst++ = '\0';
	return (start);
}
