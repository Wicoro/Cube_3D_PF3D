/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:14:16 by norban            #+#    #+#             */
/*   Updated: 2025/06/30 18:00:10 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3d.h"

void	print_error(int id)
{
	ft_putstr_fd("Error\nCube_3D : ", 2);
	if (id == ARG_COUNT_ERROR)
		ft_putstr_fd("Invalid arg count : only use the .cub file\n", 2);
	else if (id == ARG_ERROR)
		ft_putstr_fd("Invalid .cub file, double check map and/or path\n", 2);
	else if (id == MALLOC_ERROR)
		ft_putstr_fd("Malloc error encountered\n", 2);
}

int	create_data(t_data *data, char *path)
{
	int		fd;

	if (path[ft_strlen(path) - 4] != '.' || path[ft_strlen(path) - 3] != 'c'
		|| path[ft_strlen(path) - 2] != 'u' || path[ft_strlen(path) - 1] != 'b')
		return (print_error(ARG_ERROR), 1);
	data->assets.fl_color[0] = -1;
	data->assets.ce_color[0] = -1;
	fd = open(path, R_OK);
	if (fd == -1)
		return (print_error(ARG_ERROR), 1);
	if (get_assets(&data->assets, fd) == 1 || get_map(data, fd) == 1)
		return (1);
	if (!data->assets.no_path || !data->assets.so_path
		|| !data->assets.ea_path || !data->assets.we_path
		|| data->assets.fl_color[0] == -1 || data->assets.ce_color[0] == -1)
		return (print_error(ARG_ERROR), 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (ac == 1 || ac > 2)
		return (print_error(ARG_COUNT_ERROR), 1);
	if (create_data(&data, av[1]) == 1/* || parsing(&data) == 1*/)
		return (1);
	int i = -1;
	while (data.map[++i])
	{
		printf("%s", data.map[i]);
	}
	printf("\n");
	free(data.assets.no_path);
	free(data.assets.so_path);
	free(data.assets.ea_path);
	free(data.assets.we_path);
	ft_free_split(&data.map);
	return (0);
}
