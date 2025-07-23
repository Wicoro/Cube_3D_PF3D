/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:58:51 by norban            #+#    #+#             */
/*   Updated: 2025/07/23 21:52:25 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	exit_helper(char ***map, char ***new_map)
{
	ft_free_tab(map);
	ft_free_tab(new_map);
	print_error(MALLOC_ERROR);
	return (1);
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
		return (ft_free_tab(map), print_error(MALLOC_ERROR), 1);
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
	ft_free_tab(map);
	*map = new_map;
	return (0);
}

static int	end_map_process(t_map *map)
{
	remove_map_nl(map);
	get_map_dimension(map);
	if (get_squared_map(map) == 1)
		return (1);
	return (0);
}

int	get_map(t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && ft_strlen(line) == 1 && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (print_error(INVALID_MAP), 1);
	while (line)
	{
		if (ft_strlen(line) == 1 && line[0] == '\n')
		{
			if (is_it_end(fd, line) == 1)
				return (1);
			break ;
		}
		if (concat_map(&map->map_tab, line) == 1)
			return (free(line), 1);
		free(line);
		line = get_next_line(fd);
	}
	return (end_map_process(map));
}
