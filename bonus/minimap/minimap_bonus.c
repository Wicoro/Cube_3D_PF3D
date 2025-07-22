/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:55:52 by norban            #+#    #+#             */
/*   Updated: 2025/07/22 18:01:59 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	display_map_tile(t_data *data, t_map_coord *coord, t_player *player)
{
	int	start_x;
	int	start_y;
	int	i;
	int	j;

	start_x = (coord->x * TILE_SIZE) - ((player->x * TILE_SIZE)
			- data->minimap.minimap_w * 0.5);
	start_y = (coord->y * TILE_SIZE) - ((player->y * TILE_SIZE)
			- data->minimap.minimap_h * 0.5);
	j = 1;
	while (j <= TILE_SIZE)
	{
		i = 1;
		while (i <= TILE_SIZE)
		{
			add_minimap_pixel(data, start_x + i, start_y + j,
				get_color_tile(&data->map, coord->x, coord->y));
			i++;
		}
		j++;
	}
}

void	display_tiles(t_data *data, t_player *player, t_minimap *minimap)
{
	int			i;
	int			j;
	int			range_y;
	int			range_x;
	t_map_coord	coord;

	range_y = (int)(minimap->minimap_h / TILE_SIZE * 0.5);
	range_x = (int)(minimap->minimap_w / TILE_SIZE * 0.5);
	j = 0;
	while (data->map.map_tab[j])
	{
		i = 0;
		while (data->map.map_tab[j][i])
		{
			if (fabs(i - player->x) <= (range_x + 2) && fabs(j
					- player->y) <= (range_y + 2))
			{
				coord.x = i;
				coord.y = j;
				display_map_tile(data, &coord, player);
			}
			i++;
		}
		j++;
	}
}

void	display_player(t_minimap *minimap, t_data *data)
{
	int	size;
	int	j;
	int	i;

	size = TILE_SIZE * 0.25;
	j = -size;
	while (j <= size)
	{
		i = -size;
		while (i <= size)
		{
			if (i * i + j * j <= size * size)
				add_minimap_pixel(data, minimap->minimap_w * 0.5 + i,
					minimap->minimap_h * 0.5 + j, GREEN_C);
			i++;
		}
		j++;
	}
}

void	display_ray(t_data *data, t_fov *fov, t_map *map)
{
	int		i;
	float	rx;
	float	ry;
	float	px;
	float	py;

	i = 0;
	px = data->player.x * TILE_SIZE;
	py = data->player.y * TILE_SIZE;
	while (1)
	{
		rx = px + (fov->ray_dir_x * i);
		ry = py + (fov->ray_dir_y * i);
		if (is_wall(map, (int)(rx / TILE_SIZE), (int)(ry / TILE_SIZE)))
			break ;
		add_minimap_pixel(data, (int)((rx - px)) + data->minimap.minimap_w
			* 0.5, (int)((ry - py)) + data->minimap.minimap_h * 0.5, GREEN_C);
		i++;
	}
}

void	minimap(t_data *data)
{
	display_tiles(data, &data->player, &data->minimap);
	display_player(&data->minimap, data);
	display_border(data, &data->minimap);
}
