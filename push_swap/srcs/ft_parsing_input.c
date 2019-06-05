/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:11:15 by crath             #+#    #+#             */
/*   Updated: 2019/06/05 18:21:04 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/push_swap.h"

void		ft_reverse_array(int *arr, int start, int end) 
{ 
	int		temp; 
	
	while (start < end) 
	{ 
		temp = arr[start];    
		arr[start] = arr[end]; 
		arr[end] = temp; 
		start++; 
		end--; 
	}    
}

int		*ft_par(int argc, char **argv, int	*stack)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		stack[i] = ft_atoi(argv[i]);
		i++;
	}
	stack[i] = '\0';
	return (stack);
}

char	**ft_parsing(int argc, char **argv)
{
	int		i;
	int		*stack;
	char	**temp = NULL;

	if (argc == 2)
	{
		temp = ft_strsplit(argv[1], ' ');	
	}
	else
	{
		ft_par(argc, argv, stack);
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

int		ft_counter_of_strings(char **for_counting)
{
	int		i;

	i = 0;
	while (for_counting[i] != '\0')
		i++;
	return (i);
}


int		*reverse(char **arg, int *b)
{
	int		i;

	i = 0;
	while (arg[i] != '\0')
	{
		b[i] = ft_atoi(arg[i]);
		i++;
	}
	return (b);
}

int		main(int argc, char **argv)
{	
	int		i;
	char	**temp;
	int		b_stack[80];
	int		last_string_in_2D_array;

	if (argc > 1)
	{
		temp = ft_parsing(argc, argv);
		ft_to_check_parsing(temp);

		printf("\ncounter_of_strings: %d\n", ft_counter_of_strings(temp));

		printf("\n-----------------------------\n");
		
		last_string_in_2D_array = ft_counter_of_strings(temp) - 1;

		// if (!(b_stack = (int *)ft_memalloc(sizeof(int) * (int)count)))
		// 	return 0;

		printf("\n%lu\n", sizeof(b_stack));
		
		
		i = 0;
		printf("\ni: %d\nlast_string_in_2D_array: %d\n", i, last_string_in_2D_array);
		printf("\n-----------------------------\n");
		while (last_string_in_2D_array >= 0)
		{
			b_stack[i] = ft_atoi(temp[last_string_in_2D_array--]);
			i++;
			printf("\ni: %d\nlast_string_in_2D_array: %d\n", i, last_string_in_2D_array);
		}

		i = 0;
		while (b_stack[i++] != '\0')
			printf("\nЭлемент стека: %d\n", b_stack[i]);

		//b_stack = reverse(temp, b_stack);
	}


	return (0);
}





