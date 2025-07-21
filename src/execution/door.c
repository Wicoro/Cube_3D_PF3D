/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:54:51 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/21 17:55:46 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	animate_door_open(t_data *data, int door_index)
{
	t_door	*door;

	door = &data->doors[door_index];
	if (door->state >= DOOR_MAX_STATE)
		return ;
	while (door->state < DOOR_MAX_STATE)
	{
		door->state++;
		render(data, 1);
		mlx_do_sync(data->mlx_p);
		ft_sleep(30);
	}
	data->map.map_tab[data->doors[door_index].y][data->doors[door_index].x] = '3';
}

static void	animate_door_close(t_data *data, int door_index)
{
	t_door	*door;

	door = &data->doors[door_index];
	if (door->state <= 0)
		return ;
	data->map.map_tab[data->doors[door_index].y][data->doors[door_index].x] = '2';
	while (door->state > 0)
	{
		door->state--;
		render(data, 1);
		mlx_do_sync(data->mlx_p);
		ft_sleep(30);
	}
}

void	open_door(t_data *data)
{
	double	x;
	double	y;
	int		map_player_x;
	int		map_player_y;
	t_door	*door;
	int		tx;
	int		ty;

	x = data->player.x;
	y = data->player.y;
	map_player_x = x;
	map_player_y = y;
	for (int i = 0; i < TILE_SIZE * 2; i++)
	{
		x += data->player.dir_x;
		y += data->player.dir_y;
		tx = x;
		ty = y;
		if (tx == map_player_x && ty == map_player_y)
			continue ;
		for (int j = 0; j < data->door_count; j++)
		{
			door = &data->doors[j];
			if (door->x == tx && door->y == ty)
			{
				if (door->state == 0)
					animate_door_open(data, j);
				else if (door->state == DOOR_MAX_STATE)
					animate_door_close(data, j);
				return ;
			}
		}
	}
}
