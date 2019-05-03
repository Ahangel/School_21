/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:49:21 by marvin            #+#    #+#             */
/*   Updated: 2018/11/29 17:20:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if ((int)content_size == -1)
		return (NULL);
	list = (t_list*)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->next = NULL;
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content = (void*)malloc(content_size);
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
		if (!list->content)
		{
			free(list);
			return (NULL);
		}
	}
	return (list);
}
