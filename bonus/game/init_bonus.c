/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:38:53 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/23 15:44:35 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	if (init_texture(data, data->assets.so_path, 1) == 1)
		return (1);
	if (init_texture(data, data->assets.ea_path, 2) == 1)
		return (1);
	if (init_texture(data, data->assets.we_path, 3) == 1)
		return (1);
	if (init_texture(data, data->assets.do_path, 4) == 1)
		return (1);
	return (0);
}

static int	minimap_init(t_data *data)
{
	data->img[2].img_p = mlx_new_image(data->mlx_p, data->minimap.minimap_w,
			data->minimap.minimap_h);
	if (!data->img[2].img_p)
		return (1);
	return (0);
}

int	wind_init(t_data *data)
{
	data->mlx_p = mlx_init();
	if (!data->mlx_p)
		return (print_error(3), 1);
	if (init_textures(data) == 1)
		return (print_error(INVALID_MAP), 1);
	data->win_p = mlx_new_window(data->mlx_p, WIDTH, HEIGHT, "Cub3D");
	if (!data->win_p)
		return (print_error(3), 1);
	data->img[0].img_p = mlx_new_image(data->mlx_p, WIDTH, HEIGHT);
	if (!data->img[0].img_p)
		return (print_error(3), 1);
	data->img[1].img_p = mlx_new_image(data->mlx_p, WIDTH, HEIGHT);
	if (!data->img[1].img_p)
		return (print_error(3), 1);
	if (minimap_init(data))
		return (print_error(3), 1);
	return (0);
}

void	end_gnl(int fd)
{
	char	*line;
	
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

int	init_data(t_data *data, char *path)
{
	int	fd;

	if (ft_strlen(path) <= 4 || (path[ft_strlen(path) - 5] == '/')
		|| path[ft_strlen(path) - 4] != '.' || path[ft_strlen(path) - 3] != 'c'
		|| path[ft_strlen(path) - 2] != 'u' || path[ft_strlen(path) - 1] != 'b')
		return (print_error(ARG_ERROR), 1);
	data->assets.fl_color[0] = -1;
	data->assets.ce_color[0] = -1;
	fd = open(path, R_OK);
	if (fd == -1)
		return (print_error(ARG_ERROR), 1);
	if (get_assets(&data->assets, fd) == 1)
		return (1);
	if (!data->assets.no_path || !data->assets.so_path || !data->assets.ea_path
		|| !data->assets.we_path || data->assets.fl_color[0] == -1
		|| data->assets.ce_color[0] == -1 || !data->assets.do_path)
		return (print_error(ARG_ERROR), free(data->assets.no_path),
				free(data->assets.so_path), free(data->assets.ea_path),
				free(data->assets.we_path), free(data->assets.do_path),
				end_gnl(fd), 1);
	data->minimap.minimap_h = ((HEIGHT / 100) * 30);
	data->minimap.minimap_w = data->minimap.minimap_h;
	if (get_map(&data->map, fd) == 1)
		return (1);
	return (0);
}
