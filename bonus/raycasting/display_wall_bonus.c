/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wall_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:27:08 by norban            #+#    #+#             */
/*   Updated: 2025/07/23 20:32:28 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	get_texture(t_fov *fov, t_data *data, t_textures **tex)
{
	if (fov->isdoor == 1)
		*tex = &data->textures[4];
	else if (fov->side == 0 && fov->ray_dir_x > 0)
		*tex = &data->textures[3];
	else if (fov->side == 0 && fov->ray_dir_x < 0)
		*tex = &data->textures[2];
	else if (fov->side == 1 && fov->ray_dir_y > 0)
		*tex = &data->textures[0];
	else if (fov->side == 1 && fov->ray_dir_y < 0)
		*tex = &data->textures[1];
}

static int	check_door(t_fov *fov, t_data *data, t_textures *tex)
{
	int	horizontal_offset;
	int	i;

	horizontal_offset = 0;
	if (fov->isdoor == 1)
	{
		i = -1;
		while (++i < data->door_count)
		{
			if (data->doors[i].x == data->map.map_x
				&& data->doors[i].y == data->map.map_y)
			{
				horizontal_offset = (tex->height * data->doors[i].state)
					/ DOOR_MAX_STATE;
				break ;
			}
		}
	}
	return (horizontal_offset);
}

static int	get_draw_index(int wall_height, int flag)
{
	int	index;

	if (flag == 0)
	{
		index = -wall_height * 0.5 + HEIGHT * 0.5;
		if (index < 0)
			index = 0;
	}
	if (flag == 1)
	{
		index = wall_height * 0.5 + HEIGHT * 0.5;
		if (index >= HEIGHT)
			index = HEIGHT - 1;
	}
	return (index);
}

static void	put_wall_pixels(int x, int wall_height, t_data *data,
		t_textures *tex)
{
	int				y;
	unsigned int	color;
	int				draw_end;
	int				tex_y;

	y = get_draw_index(wall_height, 0) - 1;
	draw_end = get_draw_index(wall_height, 1);
	while (++y <= draw_end)
	{
		tex_y = (((y * 256 - HEIGHT * 128 + wall_height * 128) * tex->height)
				/ wall_height) / 256;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		if (tex_y < 0)
			tex_y = 0;
		color = *(unsigned int *)(tex->addr + (tex_y * tex->line_length
					+ tex->tex_x * (tex->bits_per_pixel / 8)));
		put_pixel(data, x, y, color);
	}
}

void	display_wall(int x, t_fov *fov, t_data *data)
{
	t_textures	*tex;
	int			tex_x;
	int			wall_height;

	tex = NULL;
	get_texture(fov, data, &tex);
	if (!tex || !tex->addr)
		return ;
	wall_height = (int)(HEIGHT / fov->distance);
	tex_x = (int)(fov->wall_hit_x * tex->width) - check_door(fov, data, tex);
	if ((fov->side == 0 && fov->ray_dir_x > 0) || (fov->side == 1
			&& fov->ray_dir_y < 0))
		tex_x = tex->width - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	tex->tex_x = tex_x;
	put_wall_pixels(x, wall_height, data, tex);
}
