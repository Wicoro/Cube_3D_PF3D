/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:14:16 by norban            #+#    #+#             */
/*   Updated: 2025/07/22 14:32:28 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

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
	if (init_data(&data, av[1]) == 1 || parse_map_border(&data.map) == 1)
		return (1);
/* 	int i = -1;
 	while (data.map.map_tab[++i])
	{
		printf("|%s|\n", data.map.map_tab[i]);
	}
	printf("%s", data.assets.no_path);
	printf("%s", data.assets.so_path);
	printf("%s", data.assets.ea_path);
	printf("%s", data.assets.we_path);
	printf("h : %d", data.map.height);
	printf(" | w : %d\n", data.map.width); */ 
	game_loop(&data);
	free(data.assets.no_path);
	free(data.assets.so_path);
	free(data.assets.ea_path);
	free(data.assets.we_path);
	ft_free_tab(&data.map.map_tab);
	return (0);
}
