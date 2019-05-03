/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 00:28:10 by crath             #+#    #+#             */
/*   Updated: 2019/03/03 16:13:16 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_t		*ft_forwarding(int const fd, t_t **fd_list)
{
	t_t		*tmp;
	t_t		*new;

	tmp = *fd_list;
	if (tmp)
	{
		while (tmp->next && tmp->fd != fd)
			tmp = tmp->next;
		if (tmp->fd == fd)
			return (tmp);
	}
	if (!(new = (t_t *)malloc(sizeof(t_t))))
		return (NULL);
	if (*fd_list)
		tmp->next = new;
	else
		*fd_list = new;
	new->fd = fd;
	new->state = 0;
	new->next = NULL;
	new->nbr_lines = 0;
	if (!(new->data = ft_lstnew(NULL, 0)))
		return (NULL);
	return (new);
}

static size_t	line_width(t_t *current, t_list *end, void *end_of_line)
{
	size_t	width;
	t_list	*to_del;

	to_del = current->data;
	current->data = ft_lstnew((void *)((char*)end_of_line + 1),
	end->content_size - (size_t)((char*)end_of_line - (char*)end->content) - 1);
	current->state =
	current->state - (int)((char*)end_of_line - (char*)end->content) - 1;
	width = (size_t)((char*)end_of_line - (char*)end->content);
	while (to_del != end)
	{
		width += to_del->content_size;
		to_del = to_del->next;
	}
	return (width);
}

static int		ft_line_extract(t_t *current, t_list *end, char **line,
	void *end_of_line)
{
	size_t	len;
	size_t	i;
	t_list	*tmp;
	t_list	*to_del;

	if ((i = 0) || current->state <= 0 || !end_of_line)
		return (0);
	to_del = current->data;
	len = line_width(current, end, end_of_line);
	if (!(current->data) || !(*line = ft_strnew(len + 1)))
	{
		ft_putendl_fd("Error: couldn't allocate memory\n", 2);
		return (-1);
	}
	while ((tmp = to_del))
	{
		ft_memccpy(*line + i, to_del->content, '\n', to_del->content_size);
		i += to_del->content_size;
		to_del = to_del->next;
		free(tmp->content);
		free(tmp);
	}
	(*line)[len] = ((*line)[len] == '\n') ? 0 : (*line)[len];
	current->nbr_lines += 1;
	return (1);
}

static int		ft_next_lines_read(t_t *current, char **line, void *buff)
{
	t_list	*running;
	int		extract;

	running = current->data;
	while ((extract = (int)read(current->fd, buff, BUFF_SIZE)) > 0)
	{
		current->state = extract;
		if (!(running->next = ft_lstnew(buff, (size_t)current->state)))
		{
			ft_putendl_fd("Error: couldn't allocate memory\n", 2);
			return (-1);
		}
		running = running->next;
		if ((extract = ft_line_extract(current, running, line,
			ft_memchr(running->content, '\n', running->content_size))))
			return (extract);
	}
	current->state = (extract) ? extract : current->state;
	if (current->state == -1)
	{
		ft_putendl_fd("Error: could not read file\n", 2);
		return (-1);
	}
	return (ft_line_extract(current, running, line,
		(void *)((char*)running->content + running->content_size - 1)));
}

int				get_next_line(int const fd, char **line)
{
	static t_t	*fd_list = NULL;
	t_t			*current;
	int			res;
	void		*buff;

	if (fd < 0 || !line || !(current = ft_forwarding(fd, &fd_list)))
	{
		ft_putendl_fd("Error: couldn't allocate memory, or line = NULL, "
		"or file isn't readable\n", 2);
		return (-1);
	}
	*line = NULL;
	if ((res = ft_line_extract(current, current->data, line,
	ft_memchr(current->data->content, '\n', current->data->content_size)) != 0))
		return (res);
	if (!(buff = ft_memalloc(BUFF_SIZE)))
	{
		ft_putendl_fd("Error: couldn't allocate memory\n", 2);
		return (-1);
	}
	res = ft_next_lines_read(current, line, buff);
	ft_memdel(&buff);
	return (res);
}
