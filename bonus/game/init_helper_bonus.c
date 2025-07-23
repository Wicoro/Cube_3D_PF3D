/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:57:28 by norban            #+#    #+#             */
/*   Updated: 2025/07/23 22:00:42 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	end_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

static int	error_return(t_data *data, int fd)
{
	print_error(ARG_ERROR);
	free(data->assets.no_path);
	free(data->assets.so_path);
	free(data->assets.ea_path);
	free(data->assets.we_path);
	free(data->assets.do_path);
	end_gnl(fd);
	return (1);
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
	get_assets(&data->assets, fd);
	if (!data->assets.no_path || !data->assets.so_path || !data->assets.ea_path
		|| !data->assets.we_path || data->assets.fl_color[0] == -1
		|| data->assets.ce_color[0] == -1 || !data->assets.do_path)
		return (error_return(data, fd));
	data->minimap.minimap_h = ((HEIGHT / 100) * 30);
	data->minimap.minimap_w = data->minimap.minimap_h;
	if (get_map(&data->map, fd) == 1 || parse_map_border(&data->map) == 1)
		return (error_return(data, fd));
	return (0);
}
