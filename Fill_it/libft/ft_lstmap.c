/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:06:55 by marvin            #+#    #+#             */
/*   Updated: 2018/12/01 18:50:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_cleanup(t_list *result)
{
	t_list	*current_node;

	while (result)
	{
		current_node = result->next;
		free(result->content);
		free(result);
		result = current_node;
	}
}

static void		ft_put_back(t_list *list, t_list *new_node)
{
	while (list->next)
		list = list->next;
	list->next = new_node;
}

static t_list	*ft_creator(t_list *(*f)(t_list *elem),
		t_list *lst, t_list **result)
{
	t_list	*new_node;

	new_node = lst;
	new_node = (**f)(new_node);
	if (!(new_node = ft_lstnew(new_node->content, new_node->content_size)))
	{
		ft_cleanup(*result);
		return (NULL);
	}
	return (new_node);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*new_node;
	int		flag;

	flag = 0;
	if (!lst || !(*f))
		return (NULL);
	while (lst)
	{
		if (!(new_node = ft_creator(f, lst, &result)))
			return (NULL);
		if (flag)
			ft_put_back(result, new_node);
		else
		{
			result = new_node;
			flag++;
		}
		lst = lst->next;
	}
	return (result);
}
