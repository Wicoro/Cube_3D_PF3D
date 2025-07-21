/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_fov.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:57:46 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/21 18:31:54 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	draw_wall(float x, t_fov *fov, t_data *data)
{
	int	draw_start;
	int	draw_end; 
	int	i;

	draw_start = -fov->wall_height * 0.5 + HEIGHT * 0.5;
	draw_end = fov->wall_height * 0.5 + HEIGHT * 0.5;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	i = 0;
	while (i < HEIGHT)
	{
		if (i < draw_start)
			put_pixel(data->img, &data->map, x, i,
				get_rgb_color(data->assets.ce_color));
		if (i > draw_end && i < HEIGHT)
			put_pixel(data->img, &data->map, x, i,
				get_rgb_color(data->assets.fl_color));
		i++;
	}
	display_wall(x, fov, data);
}

void	draw_player_fov(t_data *data)
{
	t_fov	fov;
	int		i;
	double	step;
	double	start_angle;

	ft_memset(data->img[2].addr, 0, MINIMAP_H * MINIMAP_W * 4);
	display_tiles(&data->map, data->img, &data->player);
	display_player(data->img);
	display_border(data->img);
	step = FOV / WIDTH;
	start_angle = atan2(data->player.dir_y, data->player.dir_x) - (FOV * 0.5);
	i = 0;
	while (i < WIDTH)
	{
		fov.ray_angle = start_angle + (i * step);
		fov.ray_dir_x = cos(fov.ray_angle);
		fov.ray_dir_y = sin(fov.ray_angle);
		draw_ray(&data->player, &fov, &data->map);
		display_ray(&data->player, &fov, data->img, &data->map);
		draw_wall(i, &fov, data);
		i++;
	}
}
