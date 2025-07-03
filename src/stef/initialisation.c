/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:49:59 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/03 17:00:55 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	initialisation(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (print_error(3));
	data->img = malloc (sizeof(t_imag));
	if (!data->img)
		return (print_error(3));
	data->player = malloc (sizeof(t_player));
	if (!data->player)
		return (print_error(3));
	ft_memset(data->player, 0, sizeof(t_player));
	ft_memset(data->img, 0, sizeof(t_imag));
	ft_memset(data->map, 0, sizeof(t_map));
}