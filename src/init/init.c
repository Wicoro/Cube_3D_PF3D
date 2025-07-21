/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:38:53 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/21 17:43:29 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	init_texture(t_data *data, char *path, int i)
{
	data->textures[i].img = mlx_xpm_file_to_image(data->mlx_p, path,
			&data->textures[i].width, &data->textures[i].height);
	if (!data->textures[i].img)
		return (1);
	data->textures[i].addr = mlx_get_data_addr(data->textures[i].img,
			&data->textures[i].bits_per_pixel, &data->textures[i].line_length,
			&data->textures[i].endian);
	return (0);
}

int	init_textures(t_data *data)
{
	if (init_texture(data, data->assets.no_path, 0) == 1)
		return (1);
	init_texture(data, data->assets.so_path, 1);
	init_texture(data, data->assets.ea_path, 2);
	init_texture(data, data->assets.we_path, 3);
	init_texture(data, data->assets.do_path, 4);
	return (0);
}

int	wind_init(t_data *data)
{
	data->mlx_p = mlx_init();
	if (!data->mlx_p)
		return (print_error(3), 1);
	data->win_p = mlx_new_window(data->mlx_p, WIDTH, HEIGHT, "Cub3D");
	if (!data->win_p)
		return (print_error(3), mlx_destroy_display(data->mlx_p), 1);
	if (init_textures(data) == 1)
		return (print_error(3), mlx_destroy_window(data->mlx_p, data->win_p),
			mlx_destroy_display(data->mlx_p), 1);
	data->img[0].img_p = mlx_new_image(data->mlx_p, WIDTH, HEIGHT);
	if (!data->img[0].img_p)
		return (print_error(3), mlx_destroy_window(data->mlx_p, data->win_p),
			mlx_destroy_display(data->mlx_p), 1);
	data->img[1].img_p = mlx_new_image(data->mlx_p, WIDTH, HEIGHT);
	if (!data->img[1].img_p)
		return (print_error(3), mlx_destroy_window(data->mlx_p, data->win_p),
			mlx_destroy_display(data->mlx_p), mlx_destroy_image(data->mlx_p,
				data->img[0].img_p), 1);
	data->img[2].img_p = mlx_new_image(data->mlx_p, MINIMAP_W, MINIMAP_H);
	if (!data->img[2].img_p)
		return (print_error(3), mlx_destroy_window(data->mlx_p, data->win_p),
			mlx_destroy_display(data->mlx_p), mlx_destroy_image(data->mlx_p,
				data->img[0].img_p), mlx_destroy_image(data->mlx_p,
				data->img[1].img_p), 1);
	return (0);
}

void	init_doors(t_data *data)
{
	int	x;
	int	y;

	data->door_count = 0;
	for (y = 0; y < data->map.height; y++)
	{
		for (x = 0; x < data->map.width; x++)
		{
			if (data->map.map_tab[y][x] == '2' && data->door_count < MAX_DOORS)
			{
				data->doors[data->door_count].x = x;
				data->doors[data->door_count].y = y;
				data->doors[data->door_count].state = 0;
				data->door_count++;
			}
		}
	}
}

int	init_data(t_data *data, char *path)
{
	int	fd;

	if (path[ft_strlen(path) - 4] != '.' || path[ft_strlen(path) - 3] != 'c'
		|| path[ft_strlen(path) - 2] != 'u' || path[ft_strlen(path) - 1] != 'b')
		return (print_error(ARG_ERROR), 1);
	data->assets.fl_color[0] = -1;
	data->assets.ce_color[0] = -1;
	fd = open(path, R_OK);
	if (fd == -1)
		return (print_error(ARG_ERROR), 1);
	if (get_assets(&data->assets, fd) == 1 || get_map(&data->map, fd) == 1)
		return (1);
	if (!data->assets.no_path || !data->assets.so_path || !data->assets.ea_path
		|| !data->assets.we_path || data->assets.fl_color[0] == -1
		|| data->assets.ce_color[0] == -1)
		return (print_error(ARG_ERROR), 1);
	return (0);
}
