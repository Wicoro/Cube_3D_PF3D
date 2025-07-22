/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:28:54 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/22 18:27:07 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_wall(t_map *map, int x, int y)
{
	char	c;

	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return (1);
	c = map->map_tab[y][x];
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (0);
	return (1);
}
