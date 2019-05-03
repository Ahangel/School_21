/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:06:16 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 15:53:58 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*list;

	if (!lst)
		return (NULL);
	list = f(lst);
	new = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(list->next = f(lst)))
		{
			free(list->next);
			return (NULL);
		}
		list = list->next;
	}
	return (new);
}
