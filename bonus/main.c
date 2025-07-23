/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:14:16 by norban            #+#    #+#             */
/*   Updated: 2025/07/23 19:16:21 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	closer(t_data *data)
{
	if (data->img[0].img_p)
		mlx_destroy_image(data->mlx_p, data->img[0].img_p);
	if (data->img[1].img_p)
		mlx_destroy_image(data->mlx_p, data->img[1].img_p);
	if (data->img[2].img_p)
		mlx_destroy_image(data->mlx_p, data->img[2].img_p);
	destroy_textures(data);
	if (data->win_p)
		mlx_destroy_window(data->mlx_p, data->win_p);
	mlx_destroy_display(data->mlx_p);
	free(data->assets.no_path);
	free(data->assets.so_path);
	free(data->assets.ea_path);
	free(data->assets.we_path);
	free(data->assets.do_path);
	ft_free_tab(&data->map.map_tab);
	free(data->mlx_p);
	exit(0);
}

void	destroy_textures(t_data *data)
{
	if (data->textures[0].img)
		mlx_destroy_image(data->mlx_p, data->textures[0].img);
	if (data->textures[1].img)
		mlx_destroy_image(data->mlx_p, data->textures[1].img);
	if (data->textures[2].img)
		mlx_destroy_image(data->mlx_p, data->textures[2].img);
	if (data->textures[3].img)
		mlx_destroy_image(data->mlx_p, data->textures[3].img);
	if (data->textures[4].img)
		mlx_destroy_image(data->mlx_p, data->textures[4].img);
}

void	print_error(int id)
{
	ft_putstr_fd("Error\nCube_3D : ", 2);
	if (id == ARG_COUNT_ERROR)
		ft_putstr_fd("Invalid arg count : only use the .cub file\n", 2);
	else if (id == ARG_ERROR)
		ft_putstr_fd("Invalid .cub file, double check map and/or path\n", 2);
	else if (id == MALLOC_ERROR)
		ft_putstr_fd("Malloc error encountered\n", 2);
	else if (id == INVALID_MAP)
		ft_putstr_fd("Invalid Map\n", 2);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (ac == 1 || ac > 2)
		return (print_error(ARG_COUNT_ERROR), 1);
	if (init_data(&data, av[1]) == 1)
		return (1);
	game_loop(&data);
	return (0);
}
