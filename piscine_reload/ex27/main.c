/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:09:33 by crath             #+#    #+#             */
/*   Updated: 2018/11/20 17:11:59 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 4096

int		main(int argc, char **argv)
{
	int		nb;
	int		fd;
	char	buf[BUF_SIZE + 1];

	nb = 1;
	if (argc < 2)
		return (write(2, "File name missing.\n", 19) || 1);
	if (argc > 2)
		return (write(2, "Too many arguments.\n", 20));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "Open() error.\n", 14) || 1);
	while (nb)
	{
		nb = read(fd, buf, BUF_SIZE);
		buf[nb] = '\0';
		write(1, buf, nb);
	}
	fd = close(fd);
	if (fd == -1)
	{
		write(2, "Close() error.\n", 15);
		return (1);
	}
	return (0);
}
