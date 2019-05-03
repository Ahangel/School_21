/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:15:06 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 15:53:57 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *element))
{
	t_list	*next_lst;

	if (lst == NULL)
		return ;
	while (lst)
	{
		next_lst = lst->next;
		f(lst);
		lst = next_lst;
	}
}
