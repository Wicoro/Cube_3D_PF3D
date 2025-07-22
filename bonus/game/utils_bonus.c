/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:28:54 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/22 18:08:02 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

void	ft_sleep(int ms)
{
	long	ref_time;
	long	new_time;

	ref_time = get_time_in_ms();
	new_time = get_time_in_ms();
	while (new_time - ms > ref_time)
		new_time = get_time_in_ms();
}

int	is_wall(t_map *map, int x, int y)
{
	char	c;

	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return (1);
	c = map->map_tab[y][x];
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '3')
		return (0);
	if (c == '2')
		return (2);
	return (1);
}
