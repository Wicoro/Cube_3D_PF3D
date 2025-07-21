/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:55:52 by norban            #+#    #+#             */
/*   Updated: 2025/07/21 18:07:25 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	add_minimap_pixel(t_imag *img, int x, int y, int color)
{
	int		x_sized;
	int		y_sized;
	int		index;
	char	*addr;

	x_sized = x;
	y_sized = y;
	addr = img[2].addr;
	if (x_sized < 0 || x_sized >= MINIMAP_W
		|| y_sized < 0 || y_sized >= MINIMAP_H)
		return ;
	index = y_sized * img[2].line_lenght + (x_sized * (img[2].bits_per_pixel
				/ 8));
	*(unsigned int *)(addr + index) = color;
}

static void	display_map_tile(t_imag *img, t_map *map,
	t_map_coord *coord, t_player *player)
{
	int	start_x;
	int	start_y;
	int	i;
	int	j;

	start_x = (coord->x * TILE_SIZE)
		- ((player->x * TILE_SIZE) - MINIMAP_W * 0.5);
	start_y = (coord->y * TILE_SIZE)
		- ((player->y * TILE_SIZE) - MINIMAP_H * 0.5);
	j = 1;
	while (j <= TILE_SIZE)
	{
		i = 1;
		while (i <= TILE_SIZE)
		{
			add_minimap_pixel(img, start_x + i,
				start_y + j, get_color_tile(map, coord->x, coord->y));
			i++;
		}
		j++;
	}
}

void	display_tiles(t_map *map, t_imag *img, t_player *player)
{
	int			i;
	int			j;
	int			range_y;
	int			range_x;
	t_map_coord	coord;

	range_y = (int)(MINIMAP_H / TILE_SIZE / 2);
	range_x = (int)(MINIMAP_W / TILE_SIZE / 2);
	j = 0;
	while (map->map_tab[j])
	{
		i = 0;
		while (map->map_tab[j][i])
		{
			if (fabs(i - player->x) <= (range_x + 2)
				&& fabs(j - player->y) <= (range_y + 2))
			{
				coord.x = i;
				coord.y = j;
				display_map_tile(img, map, &coord, player);
			}
			i++;
		}
		j++;
	}
}

void	display_player(t_imag *img)
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
				add_minimap_pixel(img, MINIMAP_W * 0.5
					+ i, MINIMAP_H * 0.5 + j, GREEN_C);
			i++;
		}
		j++;
	}
}

void	display_ray(t_player *player, t_fov *fov, t_imag *img, t_map *map)
{
	int		i;
	float	rx;
	float	ry;
	float	px;
	float	py;

	i = 0;
	px = player->x * TILE_SIZE;
	py = player->y * TILE_SIZE;
	while (1)
	{
		rx = px + (fov->ray_dir_x * i);
		ry = py + (fov->ray_dir_y * i);
		if (is_wall(map, (int)(rx / TILE_SIZE), (int)(ry / TILE_SIZE)))
			break ;
		add_minimap_pixel(img, (int)((rx - px)) + MINIMAP_W * 0.5,
			(int)((ry - py)) + MINIMAP_H * 0.5, GREEN_C);
		i++;
	}
}
