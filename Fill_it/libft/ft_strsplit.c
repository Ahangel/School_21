/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:15:08 by marvin            #+#    #+#             */
/*   Updated: 2018/12/01 18:47:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_count_words(char const *s, char c)
{
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			size++;
		i++;
	}
	return (size);
}

static char const	*ft_skip_del(char const *s, char c, size_t *len)
{
	while (*s == c)
		s++;
	*len = 0;
	return (s);
}

static char			**ft_check(size_t *i, size_t size)
{
	char	**arr;

	if (!(arr = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	arr[size] = NULL;
	*i = 0;
	return (arr);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	size;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	size = ft_count_words(s, c);
	if (!(arr = ft_check(&i, size)))
		return (NULL);
	while (i < size)
	{
		s = ft_skip_del(s, c, &len);
		while (s[len] && s[len] != c)
			len++;
		if (!(arr[i] = ft_strsub(s, 0, len)))
		{
			while (i)
				free(arr[--i]);
			return (NULL);
		}
		s += len;
		i++;
	}
	return (arr);
}
