/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:43:20 by marvin            #+#    #+#             */
/*   Updated: 2018/12/20 15:35:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*write_all_tetris(int fd, t_tetri *list,
		t_uchar matrix[4][4], int result)
{
	while (1)
	{
		result = read_tetris(fd, matrix);
		if (result == 1)
			list = write_new_tetri(list, matrix);
		else if (result == 0)
			return (NULL);
		else
		{
			list = write_new_tetri(list, matrix);
			break ;
		}
	}
	return (list);
}

int		main(int argc, char *argv[])
{
	int		fd;
	t_tetri	*list;
	t_uchar	matrix[4][4];
	int		result;
	int		size;

	list = NULL;
	result = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (!(list = write_all_tetris(fd, list, matrix, result))
			|| list_count(list) > 26)
	{
		clean_tetri(list);
		ft_putstr("error\n");
		return (0);
	}
	size = ft_max(ft_sqrt(list_count(list) * 4), find_max_count(list));
	prepare_to_solve(list, size);
	clean_tetri(list);
	return (1);
}
