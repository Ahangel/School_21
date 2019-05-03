/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:57:21 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 16:07:00 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1024

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"

typedef struct			s_struct
{
	int					fd;
	int					state;
	size_t				nbr_lines;
	t_list				*data;
	struct s_struct		*next;
}						t_t;

int						get_next_line(int const fd, char **line);

#endif
