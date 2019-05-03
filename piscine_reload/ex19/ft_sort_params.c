/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:29:25 by crath             #+#    #+#             */
/*   Updated: 2018/11/20 17:55:17 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print(char *c)
{
	int i;

	i = 0;
	while (c[i] != '\0')
	{
		ft_putchar(c[i]);
		i++;
	}
	ft_putchar('\n');
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_swap(int *a, int *b)
{
	int c;

	if (a && b)
	{
		c = *a;
		*a = *b;
		*b = c;
	}
}

int		main(int argc, char **argv)
{
	int i;
	int j;
	int k;
	int arg[argc];

	i = 1;
	while (i < argc)
	{
		arg[i] = i;
		i++;
	}
	j = 1;
	while (j < argc)
	{
		k = j;
		while (k < argc)
		{
			if (ft_strcmp(argv[arg[j]], argv[arg[k]]) > 0)
				ft_swap(&arg[j], &arg[k]);
			k++;
		}
		ft_print(argv[arg[j++]]);
	}
	return (0);
}
