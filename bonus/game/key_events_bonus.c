/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:34:00 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/22 18:24:36 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_player(t_data *data, int up_or_down)
{
	double	new_x;
	double	new_y;

	if (up_or_down == 1)
	{
		new_x = data->player.x + (data->player.dir_x * SPEED);
		new_y = data->player.y + (data->player.dir_y * SPEED);
	}
	else
	{
		new_x = data->player.x - (data->player.dir_x * SPEED);
		new_y = data->player.y - (data->player.dir_y * SPEED);
	}
	if (!is_wall(&data->map, (int)new_x, (int)data->player.y))
		data->player.x = new_x;
	if (!is_wall(&data->map, (int)data->player.x, (int)new_y))
		data->player.y = new_y;
}

void	strafe_player(t_data *data, int right_or_left)
{
	double	new_x;
	double	new_y;
	double	perp_x;
	double	perp_y;

	perp_x = -data->player.dir_y;
	perp_y = data->player.dir_x;
	if (right_or_left == 1)
	{
		new_x = data->player.x + (perp_x * SPEED);
		new_y = data->player.y + (perp_y * SPEED);
	}
	else
	{
		new_x = data->player.x - (perp_x * SPEED);
		new_y = data->player.y - (perp_y * SPEED);
	}
	if (!is_wall(&data->map, (int)new_x, (int)data->player.y))
		data->player.x = new_x;
	if (!is_wall(&data->map, (int)data->player.x, (int)new_y))
		data->player.y = new_y;
}

void	rotate_player(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_dir_y;

	old_dir_x = player->dir_x;
	old_dir_y = player->dir_y;
	player->dir_x = old_dir_x * cos(angle) - old_dir_y * sin(angle);
	player->dir_y = old_dir_x * sin(angle) + old_dir_y * cos(angle);
}
