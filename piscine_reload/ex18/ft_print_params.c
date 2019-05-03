/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:12:45 by crath             #+#    #+#             */
/*   Updated: 2018/11/20 14:28:22 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int		first_counter;
	int		second_counter;

	first_counter = 1;
	second_counter = 0;
	while (argc > first_counter)
	{
		second_counter = 0;
		while (argv[first_counter][second_counter])
		{
			ft_putchar(argv[first_counter][second_counter]);
			second_counter++;
		}
		ft_putchar('\n');
		first_counter++;
	}
	return (0);
}
