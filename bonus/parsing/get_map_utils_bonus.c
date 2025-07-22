/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:14:37 by norban            #+#    #+#             */
/*   Updated: 2025/07/22 13:30:15 by stdevis          ###   ########.fr       */
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

int	get_squared_map(t_map *map)
{
	char	**new_map;
	int		i;

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
