/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_door_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:18:40 by norban            #+#    #+#             */
/*   Updated: 2025/07/21 18:32:07 by norban           ###   ########.fr       */
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
		clear_image(data->img, &data->map);
		draw_player_fov(data);
		mlx_put_image_to_window(data->mlx_p, data->win_p,
			data->img[data->map.check_img].img_p, 0, 0);
		mlx_put_image_to_window(data->mlx_p, data->win_p, data->img[2].img_p,
			WIDTH - MINIMAP_W - MINIMAP_W / 10,
			HEIGHT - MINIMAP_H - MINIMAP_H / 10);
		mlx_do_sync(data->mlx_p);
		ft_sleep(30);
	}
	data->map.map_tab[data->doors[door_index].y]
	[data->doors[door_index].x] = '3';
}

static void	animate_door_close(t_data *data, int door_index)
{
	t_door	*door;

	door = &data->doors[door_index];
	if (door->state <= 0)
		return ;
	data->map.map_tab[data->doors[door_index].y]
	[data->doors[door_index].x] = '2';
	while (door->state > 0)
	{
		door->state--;
		clear_image(data->img, &data->map);
		draw_player_fov(data);
		mlx_put_image_to_window(data->mlx_p, data->win_p,
			data->img[data->map.check_img].img_p, 0, 0);
		mlx_put_image_to_window(data->mlx_p, data->win_p, data->img[2].img_p,
			WIDTH - MINIMAP_W - MINIMAP_W / 10,
			HEIGHT - MINIMAP_H - MINIMAP_H / 10);
		mlx_do_sync(data->mlx_p);
		ft_sleep(30);
	}
}

static int	get_door_dist(int x, int y, t_player *player)
{
	double	dx;
	double	dy;
	double	dist;

	dx = x - player->x;
	dy = y - player->y;
	dist = sqrt(dx * dx + dy * dy);
	return (dist);
}

void	check_map_tiles(double x, double y, t_data *data)
{
	int		i;
	int		j;
	t_door	*door;

	i = -1;
	while (++i < TILE_SIZE * 2)
	{
		x += data->player.dir_x;
		y += data->player.dir_y;
		if (get_door_dist(x, y, &data->player) > 2)
			break ;
		j = -1;
		while (++j < data->door_count)
		{
			door = &data->doors[j];
			if (door->x == (int)x && door->y == (int)y)
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

void	interact_door(t_data *data)
{
	double		x;
	double		y;

	x = data->player.x;
	y = data->player.y;
	check_map_tiles(x, y, data);
}
