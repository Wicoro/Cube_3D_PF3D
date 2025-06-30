/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:55:19 by norban            #+#    #+#             */
/*   Updated: 2025/01/10 10:47:05 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	get_buf_last_i(char **rest, int size)
{
	int	i;

	i = 0;
	while (i < size && (*rest)[i] && (*rest)[i] != '\n')
		i++;
	if (i == size)
		return (-1);
	return (i);
}

void	move_rest(char **rest, int i)
{
	char	*tmp;

	tmp = gnl_strdup(*rest + i);
	if (!tmp || !tmp[0])
	{
		free(*rest);
		*rest = NULL;
		free(tmp);
	}
	else
	{
		free(*rest);
		*rest = tmp;
	}
}

int	process_rest_to_line(char **rest, char **line)
{
	*line = gnl_strdup("");
	if (!(*line))
		return (0);
	if (*rest)
	{
		if (get_buf_last_i(rest, BUFFER_SIZE) != -1)
		{
			gnl_strnjoin(line, rest, get_buf_last_i(rest, BUFFER_SIZE) + 1);
			move_rest(rest, get_buf_last_i(rest, BUFFER_SIZE));
		}
		else
		{
			gnl_strnjoin(line, rest, ft_strlen(*rest));
			move_rest(rest, ft_strlen(*line));
		}
		return (1);
	}
	return (2);
}

void	*read_next_line(char **buf, char **line, int r, int fd)
{
	*buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(*buf))
		return (free(*line), NULL);
	ft_bzero(*buf, (long) BUFFER_SIZE + 1);
	while (r > 0)
	{
		r = read(fd, *buf, BUFFER_SIZE);
		if (r == -1)
			return (free(*buf), free(*line), NULL);
		if (r == 0 || get_buf_last_i(buf, BUFFER_SIZE) != -1)
			break ;
		gnl_strnjoin(line, buf, BUFFER_SIZE);
		gnl_free(buf);
		*buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!(*buf))
			return (free(*line), NULL);
		ft_bzero(*buf, (long) BUFFER_SIZE + 1);
	}
	if (!(*buf)[get_buf_last_i(buf, BUFFER_SIZE)])
		gnl_strnjoin(line, buf, get_buf_last_i(buf, BUFFER_SIZE));
	else
		gnl_strnjoin(line, buf, get_buf_last_i(buf, BUFFER_SIZE) + 1);
	if ((ft_strlen(*line) == 0) && r <= 0)
		return (free(*buf), free(*line), NULL);
	return (*line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*rest;
	int			pro;
	int			r;

	r = 1;
	pro = process_rest_to_line(&rest, &line);
	if (pro == 0)
		return (gnl_free(&rest), NULL);
	if (pro == 1 && rest)
		return (move_rest(&rest, get_buf_last_i(&rest, BUFFER_SIZE) + 1), line);
	else
	{
		if (read_next_line(&buf, &line, r, fd) == NULL)
			return (NULL);
		if (buf[1] && get_buf_last_i(&buf, BUFFER_SIZE) != -1)
			rest = gnl_strdup(1 + buf + get_buf_last_i(&buf, BUFFER_SIZE));
	}
	if (rest && ft_strlen(rest) == 0)
		gnl_free(&rest);
	gnl_free(&buf);
	if (r <= 0 && ft_strlen(line) == 0)
		return (NULL);
	return (line);
}

/*int	main(int ac, char **av)
{
	int	f = open(av[1], 0);
	char *s;

	ac = 0;
	while (1)
	{
		s = get_next_line(f);
		if (!s)
		{
			close(f);
			exit(1);
		}
		printf("%s", s);
		free(s);
		s = NULL;
	}
	close(f);
	return (0);
}*/
