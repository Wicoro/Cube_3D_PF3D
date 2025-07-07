/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:58:51 by norban            #+#    #+#             */
/*   Updated: 2025/07/07 17:32:36 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	get_squared_map(t_map *map)
{
	char	**new_map;
	int		i;
	
	new_map = malloc(sizeof(char *) * (map->height + 1));
	if (!new_map)
		return (print_error(MALLOC_ERROR), 1);
	ft_bzero(new_map, 0);
	i = 0;
	while (i < map->height)
	{
		new_map[i] = malloc(sizeof(char) * (map->width + 3));
		if (!new_map[i])
			return (print_error(MALLOC_ERROR), ft_free_tab(&new_map), 1);
		ft_memset(new_map[i], 32, map->width + 2);
		new_map[i][map->width + 2] = '\0';
		//printf("test1 : |%s| => %d\n", new_map[i], ft_strlen(new_map[i]));
		ft_memcpy(&new_map[i][1], map->map_tab[i], ft_strlen(map->map_tab[i]));
		if (ft_strchr(new_map[i], '\n'))
			ft_memset(ft_strchr(new_map[i], '\n'), 32, 1);
		printf("test3 : |%s| => %d\n", new_map[i], ft_strlen(new_map[i]));
		if (!new_map[i])
			return (print_error(MALLOC_ERROR), ft_free_tab(&new_map), 1);
		i++;
	}
	ft_free_tab(&map->map_tab);
	map->map_tab = new_map;
	return (0);
}

int	get_map(t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (concat_map(&map->map_tab, " ") == 1)
		return (1);
	while (line)
	{
		if (!(ft_strlen(line) == 1 && line[0] == '\n')
			&& concat_map(&map->map_tab, line) == 1)
			return (1);
		free(line);
		line = get_next_line(fd);
	}
	if (concat_map(&map->map_tab, " ") == 1)
		return (1);
	get_map_dimension(map);
	if (get_squared_map(map) == 1)
		return (1);
	return (0);
}
