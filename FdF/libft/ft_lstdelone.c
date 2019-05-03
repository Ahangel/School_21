/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:45:14 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 15:53:56 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*new;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	new = *alst;
	del(new->content, new->content_size);
	free(*alst);
	*alst = NULL;
}
