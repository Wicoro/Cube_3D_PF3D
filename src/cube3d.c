/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:14:16 by norban            #+#    #+#             */
/*   Updated: 2025/06/30 14:58:41 by norban           ###   ########.fr       */
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
		ft_putstr_fd("Malloc error encountered\n",  2);
}

int	get_assets(t_data *data, int fd)
{
	char	*line;
	char	**split;
	
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) != 0)
		{
			split = ft_split(line, ' ');
			if (ft_strncmp(split[0], "NO", 3) == 0)
				data->assets.no_path = ft_strdup(split[1]);
			else if (ft_strncmp(split[0], "SO", 3) == 0)
				data->assets.so_path = ft_strdup(split[1]);
			else if (ft_strncmp(split[0], "EA", 3) == 0)
				data->assets.ea_path = ft_strdup(split[1]);
			else if (ft_strncmp(split[0], "WE", 3) == 0)
				data->assets.we_path = ft_strdup(split[1]);
			else if (ft_strncmp(split[0], "F", 2) == 0
			)
		}
	}
}

int	create_data(t_data *data, char *path)
{
	int		fd;
	
	if (path[ft_strlen(path) - 3] == '.' && path[ft_strlen(path) - 2] == 'c'
		&& path[ft_strlen(path) - 2] == 'u' && path[ft_strlen(path) - 1] == 'b')
		return (print_error(ARG_ERROR), 1);
	data = malloc(sizeof(t_data));
	if (!data)
		return(print_error(MALLOC_ERROR), 1);
	data->map = NULL;
	fd = open(path, R_OK);
	if (fd == -1)
		return(print_error(ARG_ERROR), 1);
	if (get_assets(data, fd) == 1 || get_map(data, fd) == 1);
		return(print_error(ARG_ERROR), 1);
	return (0);
}

int	main(int ac, char *av)
{
	t_data	*data;
	
	data = NULL;
	if (ac == 1 || ac > 2)
		return (print_eror(ARG_COUNT_ERROR), 1);
	if (create_data(data, av[1]) == 1 || parsing(data) == 1)
		return (1);
	while (data)
	{
		
	}
	free(data);
	return (0);
}
