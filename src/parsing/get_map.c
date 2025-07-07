/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:58:51 by norban            #+#    #+#             */
/*   Updated: 2025/06/30 18:02:34 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3d.h"

static int	exit_helper(char ***map, char ***new_map)
{
	ft_free_split(map);
	ft_free_split(new_map);
	print_error(MALLOC_ERROR);
	return (1);
}

static void	free_char(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static int	concat_null_map(char ***map, char *line)
{
	*map = malloc(sizeof(char *) * 2);
	if (!(*map))
		return (print_error(MALLOC_ERROR), 1);
	(*map)[0] = ft_strdup(line);
	(*map)[1] = 0;
	return (0);
}

static int	concat_map(char ***map, char *line)
{
	char	**new_map;
	int		size;

	if (!(*map))
		return (concat_null_map(map, line));
	size = 0;
	while ((*map)[size])
		size++;
	new_map = malloc(sizeof(*map) * (size + 2));
	if (!new_map)
		return (ft_free_split(map), print_error(MALLOC_ERROR), 1);
	size = -1;
	while ((*map)[++size])
	{
		new_map[size] = ft_strdup((*map)[size]);
		if (!new_map[size])
			return (exit_helper(map, &new_map));
	}
	new_map[size] = ft_strdup(line);
	if (!new_map[size])
		return (exit_helper(map, &new_map));
	new_map[++size] = 0;
	ft_free_split(map);
	*map = new_map;
	return (0);
}

int	get_map(t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (!(ft_strlen(line) == 1 && line[0] == '\n')
			&& concat_map(&data->map, line) == 1)
			return (1);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
