/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:57:46 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/22 16:15:37 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_rgb_color(int *color)
{
	return (color[0] << 16 | color[1] << 8 | color[2]);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	int		x_sized;
	int		y_sized;
	int		index;
	char	*addr;

	x_sized = x;
	y_sized = y;
	addr = data->img[data->map.check_img].addr;
	if (x_sized < 0 || x_sized >= WIDTH || y_sized < 0 || y_sized >= HEIGHT)
		return ;
	index = y_sized * data->img[data->map.check_img].line_lenght + (x_sized
			* (data->img[data->map.check_img].bits_per_pixel / 8));
	*(unsigned int *)(addr + index) = color;
}

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
			put_pixel(data, x, i, get_rgb_color(data->assets.ce_color));
		if (i > draw_end && i < HEIGHT)
			put_pixel(data, x, i, get_rgb_color(data->assets.fl_color));
		i++;
	}
	display_wall(x, fov, data);
}

void	raycasting(t_data *data)
{
	t_fov	fov;
	int		i;
	double	step;
	double	start_angle;

	step = FOV / WIDTH;
	start_angle = atan2(data->player.dir_y, data->player.dir_x) - (FOV * 0.5);
	i = 0;
	while (i < WIDTH)
	{
		fov.ray_angle = start_angle + (i * step);
		fov.ray_dir_x = cos(fov.ray_angle);
		fov.ray_dir_y = sin(fov.ray_angle);
		draw_ray(&data->player, &fov, &data->map);
		draw_wall(i, &fov, data);
		i++;
	}
}
