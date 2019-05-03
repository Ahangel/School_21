/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:35:21 by marvin            #+#    #+#             */
/*   Updated: 2018/11/30 14:12:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*result;

	if (size == 0)
		return (NULL);
	result = (void*)malloc((int)size);
	if (result == NULL)
		return (NULL);
	ft_memset(result, 0, (int)size);
	return (result);
}
