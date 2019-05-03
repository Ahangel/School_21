/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:56:44 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 15:53:55 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*new;
	t_list	*nextlist;

	new = *alst;
	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	while (new)
	{
		nextlist = new->next;
		del(new->content, new->content_size);
		free(new);
		new = nextlist;
	}
	*alst = NULL;
}
