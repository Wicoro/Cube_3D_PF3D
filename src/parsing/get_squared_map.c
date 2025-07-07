/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_squared_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:14:37 by norban            #+#    #+#             */
/*   Updated: 2025/07/07 18:14:49 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		new_map[i] = malloc(sizeof(char) * (map->width + 1));
		if (!new_map[i])
			return (print_error(MALLOC_ERROR), ft_free_tab(&new_map), 1);
		ft_memset(new_map[i], 32, map->width);
		new_map[i][map->width + 2] = '\0';
		ft_memcpy(new_map[i], map->map_tab[i], ft_strlen(map->map_tab[i]));
		if (ft_strchr(new_map[i], '\n'))
			ft_memset(ft_strchr(new_map[i], '\n'), 32, 1);
		if (!new_map[i])
			return (print_error(MALLOC_ERROR), ft_free_tab(&new_map), 1);
		i++;
	}
	ft_free_tab(&map->map_tab);
	map->map_tab = new_map;
	return (0);
}
