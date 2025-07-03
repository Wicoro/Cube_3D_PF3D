/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:55:42 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/03 18:45:50 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_width_height(t_map *map, char *map_name)
{
	char	*line;
	int		width_tmp;
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (print_error(2));
	line = get_next_line(fd);
	map->width = ft_strlen(line);
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			width_tmp = ft_strlen(line);
		if (width_tmp > map->width)
			map->width = width_tmp;
		map->height++;
	}
	close(fd);
}

char	**alloc_map(t_map *map)
{
	char **map_tab;

	map_tab = malloc(sizeof(char *) * map->height + 1);
	if (!map_tab)
		return (print_error(3), NULL);
	return (map_tab);
}

void	fill_map(t_map *map, char *map_name)
{
	int fd;
	char *line;
	int i;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (print_error(2));
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map->map_tab[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map->map_tab[i] = NULL;
}

void	print_map(char **map)
{
	int i;
	
	i = 0;
	printf(BOLD "MAP :\n" RESET);
	while(map[i])
	{
		printf("     %s", map[i]);
		i++;
	}
	printf("\n");
}

void	create_map(t_data *data, char **av)
{
	get_width_height(data->map, av[1]);
	data->map->map_tab = alloc_map(data->map);
	fill_map(data->map, av[1]);
/* 	print_map(data->map->map_tab); */
}