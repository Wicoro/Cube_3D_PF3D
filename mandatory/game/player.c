/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:45:03 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/22 13:16:05 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	is_player(char c, t_player *player)
{
	if (c == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		return (0);
	}
	if (c == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		return (0);
	}
	if (c == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		return (0);
	}
	if (c == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		return (0);
	}
	return (1);
}

void	where_player(t_map *map, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (map->map_tab[y])
	{
		x = 0;
		while (map->map_tab[y][x])
		{
			if (!is_player(map->map_tab[y][x], player))
			{
				player->x = x + 0.5;
				player->y = y + 0.5;
			}
			x++;
		}
		y++;
	}
}
