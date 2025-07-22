/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_border_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:26:18 by norban            #+#    #+#             */
/*   Updated: 2025/07/22 18:26:39 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	check_surround(char **map, int x, int y)
{
	if (y == 0 || x == 0 || !map[y - 1] || !map[y + 1] || !map[y][x + 1]
		|| !map[y][x - 1])
		return (1);
	if (map[y - 1][x] == ' ' || map[y + 1][x] == ' ' || map[y][x + 1] == ' '
		|| map[y][x - 1] == ' ')
		return (1);
	return (0);
}

int	parse_map_border(t_map *map)
{
	int	i;
	int	j;
	int	player;

	i = -1;
	player = 0;
	while (map->map_tab[++i])
	{
		j = -1;
		while (map->map_tab[i][++j])
		{
			if (ft_strchr("NSEW02", map->map_tab[i][j])
				&& check_surround(map->map_tab, j, i) == 1)
				return (print_error(INVALID_MAP), 1);
			if (ft_strchr("NSEW", map->map_tab[i][j]))
				player++;
			else if (!ft_strchr("012 ", map->map_tab[i][j]))
				return (print_error(INVALID_MAP), 1);
		}
	}
	if (player != 1)
		return (print_error(INVALID_MAP), 1);
	return (0);
}
