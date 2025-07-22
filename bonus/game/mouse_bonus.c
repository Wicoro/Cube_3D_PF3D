/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:26:00 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/22 14:31:55 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	mouse_hook(int x, int y, void *param)
{
	t_data	*data;
	double	delta_x;
	double	rot_speed;

	(void)y;
	if (!param || x < 0)
		return (0);
	data = (t_data *)param;
	delta_x = x - WIDTH / 2;
	if (fabs(delta_x) > 20)
	{
		rot_speed = 0.0005;
		if (delta_x > 200)
			delta_x = 200;
		rotate_player(&data->player, delta_x * rot_speed);
		render(data, 1);
		mlx_mouse_move(data->mlx_p, data->win_p, WIDTH / 2, HEIGHT / 2);
	}
	return (0);
}
