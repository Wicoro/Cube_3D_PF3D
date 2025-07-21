/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:25:15 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/21 18:27:07 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_rgb_color(int *color)
{
	return (color[0] << 16 | color[1] << 8 | color[2]);
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

void	put_pixel(t_imag *img, t_map *map, int x, int y, int color)
{
	int		x_sized;
	int		y_sized;
	int		index;
	char	*addr;

	x_sized = x;
	y_sized = y;
	addr = img[map->check_img].addr;
	if (x_sized < 0 || x_sized >= WIDTH || y_sized < 0 || y_sized >= HEIGHT)
		return ;
	index = y_sized * img[map->check_img].line_lenght + (x_sized
			* (img[map->check_img].bits_per_pixel / 8));
	*(unsigned int *)(addr + index) = color;
}
