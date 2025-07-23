/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:15:14 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/23 16:47:23 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

void	gnl_ft_free(char **str)
{
	if (!str || !*str)
		return ;
	free(*str);
	*str = NULL;
}

char	*create_rest(char *line)
{
	int		i;
	char	*new_rest;

	i = gnl_ft_strchr(line, '\n');
	if (i == -1)
		return (NULL);
	new_rest = gnl_ft_substr(line, i + 1, gnl_ft_strlen(line) - i - 1);
	if (!new_rest)
		return (gnl_ft_free(&new_rest), NULL);
	line[i + 1] = '\0';
	return (new_rest);
}

char	*get_the_line(char *rest, char *buff)
{
	char	*tmp;

	if (!rest)
	{
		rest = gnl_ft_strdup("");
		if (!rest)
			return (NULL);
	}
	tmp = rest;
	rest = gnl_ft_strjoin(tmp, buff);
	if (!rest)
		return (gnl_ft_free(&rest), NULL);
	gnl_ft_free(&tmp);
	return (rest);
}

char	*read_the_line(int fd, char **rest)
{
	int		byte;
	char	buff[BUFFER_SIZE + 1];

	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
			return (gnl_ft_free(rest), NULL);
		if (byte == 0)
			break ;
		buff[byte] = '\0';
		*rest = get_the_line(*rest, buff);
		if (!*rest)
			return (NULL);
		if (gnl_ft_strchr(*rest, '\n') != -1)
			break ;
	}
	if (byte == 0 && (!*rest || *rest[0] == '\0'))
		return (gnl_ft_free(rest), NULL);
	return (*rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (BUFFER_SIZE >= MAX_BUFFER_SIZE)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (gnl_ft_free(&rest), NULL);
	line = read_the_line(fd, &rest);
	if (!line)
		return (NULL);
	rest = create_rest(line);
	if (!rest)
		gnl_ft_free(&rest);
	return (line);
}
