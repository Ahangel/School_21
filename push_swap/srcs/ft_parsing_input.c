/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:11:15 by crath             #+#    #+#             */
/*   Updated: 2019/06/04 18:53:59 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/push_swap.h"

char	**ft_parsing(int argc, char **argv)
{
	int		i;
	char	**temp = NULL;
	
	if (argc == 2)
	{
		temp = ft_strsplit(argv[1], ' ');	
	}
	else
	{
		i = 1;
		while (i < argc)
		{		
			i++;
		}
	}
	return (temp);

}

void	ft_to_check_parsing(char **after_parsing)
{
	int		i;

	i = 0;
	while (after_parsing[i] != '\0')
	{
		printf("%s\n", after_parsing[i]);
		i++;
	}
}

size_t	ft_counter_of_strings(char **for_counting)
{
	size_t	i;

	i = 0;
	while (for_counting[i] != '\0')
		i++;
	return (i);
}

int		main(int argc, char **argv)
{	
	int		i;
	char	**temp;
	char	*b_stack;
	size_t	count;

	

	// printf("%ld\n", count);

	if (argc > 1)
	{
		temp = ft_parsing(argc, argv);
		ft_to_check_parsing(temp);

		printf("%ld\n\n", ft_counter_of_strings(temp));
		
		b_stack = (char *)ft_memalloc(sizeof(*temp) * ft_counter_of_strings(temp) + 1);
		temp = NULL;
		count = ft_strlen(b_stack);
		
		i = 0;
		while (temp[i] != '\0')
		{
			b_stack[count - 1] = ft_atoi(temp[i]);
			i++;
		}

		i = 0;
		while (b_stack[i++] != '\0')
			printf("%d\n", b_stack[i]);
	}
	return (0);
}















// 1) сколько аргументов?
// 2) какого они типа?
