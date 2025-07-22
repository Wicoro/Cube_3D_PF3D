/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:06:26 by norban            #+#    #+#             */
/*   Updated: 2025/07/22 18:07:15 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	add_minimap_pixel(t_data *data, int x, int y, int color)
{
	int		x_sized;
	int		y_sized;
	int		index;
	char	*addr;

	x_sized = x;
	y_sized = y;
	addr = data->img[2].addr;
	if (x_sized < 0 || x_sized >= data->minimap.minimap_w || y_sized < 0
		|| y_sized >= data->minimap.minimap_h)
		return ;
	index = y_sized * data->img[2].line_lenght + (x_sized
			* (data->img[2].bits_per_pixel / 8));
	*(unsigned int *)(addr + index) = color;
}

void	display_border(t_data *data, t_minimap *minimap)
{
	int	i;
	int	j;

	i = 0;
	while (i < minimap->minimap_h)
	{
		j = 0;
		while (j < minimap->minimap_w)
		{
			if (i < MINIMAP_BORDER_SIZE || i > minimap->minimap_h
				- MINIMAP_BORDER_SIZE)
				add_minimap_pixel(data, j, i, GREEN_C);
			else if (j < MINIMAP_BORDER_SIZE || j > minimap->minimap_w
				- MINIMAP_BORDER_SIZE)
				add_minimap_pixel(data, j, i, GREEN_C);
			j++;
		}
		i++;
	}
}

int	get_color_tile(t_map *map, int x, int y)
{
	char	c;

	if (!map || !map->map_tab)
		return (0x000000);
	else if (y < 0 || y >= map->height)
		return (0x000000);
	else if (x < 0 || x >= map->width)
		return (0x000000);
	c = map->map_tab[y][x];
	if (c == ' ')
		return (0x000000);
	else if (c == '1')
		return (RED_C);
	else if (c == '2')
		return (0x0000FF);
	else if (c == '3')
		return (0x7F00FF);
	else if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (0xA0A0A0);
	else
		return (0x000000);
}
