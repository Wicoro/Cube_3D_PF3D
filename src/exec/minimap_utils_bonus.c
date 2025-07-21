/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:06:26 by norban            #+#    #+#             */
/*   Updated: 2025/07/21 18:08:27 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	display_border(t_imag *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_H)
	{
		j = 0;
		while (j < MINIMAP_W)
		{
			if (i < MINIMAP_BORDER_SIZE || i > MINIMAP_H - MINIMAP_BORDER_SIZE)
				add_minimap_pixel(img, j, i, GREEN_C);
			else if (j < MINIMAP_BORDER_SIZE
				|| j > MINIMAP_W - MINIMAP_BORDER_SIZE)
				add_minimap_pixel(img, j, i, GREEN_C);
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
