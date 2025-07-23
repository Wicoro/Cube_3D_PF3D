/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:14:37 by norban            #+#    #+#             */
/*   Updated: 2025/07/23 22:03:44 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	remove_map_nl(t_map *map)
{
	int	i;

	i = -1;
	while (map->map_tab[++i])
	{
		if (ft_strchr(map->map_tab[i], '\n'))
			ft_memset(ft_strchr(map->map_tab[i], '\n'), '\0', 1);
	}
}

void	get_map_dimension(t_map *map)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while (map->map_tab[h])
	{
		if (w < ft_strlen(map->map_tab[h]))
			w = ft_strlen(map->map_tab[h]);
		h++;
	}
	map->height = h;
	map->width = w;
}

int	line_full_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\n'))
		i++;
	if (!line[i])
		return (0);
	return (1);
}

int	is_it_end(int fd, char *line)
{
	free(line);
	line = get_next_line(fd);
	while (line && ((ft_strlen(line) == 1
				&& line[0] == '\n') || !line_full_space(line)))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line && !(ft_strlen(line) == 1 && line[0] == '\n'))
		return (free(line), print_error(INVALID_MAP), 1);
	free(line);
	return (0);
}

int	get_squared_map(t_map *map)
{
	char	**new_map;
	int		i;

	if (!map)
		return (1);
	new_map = malloc(sizeof(char *) * (map->height + 1));
	if (!new_map)
		return (print_error(MALLOC_ERROR), 1);
	ft_bzero(new_map, sizeof(char *) * (map->height + 1));
	i = 0;
	while (i < map->height)
	{
		new_map[i] = malloc(sizeof(char) * (map->width + 1));
		if (!new_map[i])
			return (print_error(MALLOC_ERROR), ft_free_tab(&new_map), 1);
		ft_memset(new_map[i], 32, map->width);
		new_map[i][map->width] = '\0';
		ft_memcpy(new_map[i], map->map_tab[i], ft_strlen(map->map_tab[i]));
		if (!new_map[i])
			return (print_error(MALLOC_ERROR), ft_free_tab(&new_map), 1);
		i++;
	}
	ft_free_tab(&map->map_tab);
	map->map_tab = new_map;
	return (0);
}
