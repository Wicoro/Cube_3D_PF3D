/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:57:07 by norban            #+#    #+#             */
/*   Updated: 2025/07/22 15:17:12 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	get_delta_dist(t_fov *fov)
{
	if (fov->ray_dir_x == 0)
		fov->delta_dist_x = 1e30;
	else
		fov->delta_dist_x = fabs(1 / fov->ray_dir_x);
	if (fov->ray_dir_y == 0)
		fov->delta_dist_y = 1e30;
	else
		fov->delta_dist_y = fabs(1 / fov->ray_dir_y);
}

static void	get_step_side_dist(t_fov *fov, t_map *map, t_player *p)
{
	if (fov->ray_dir_x < 0)
	{
		map->step_x = -1;
		fov->side_dist_x = (p->x - map->map_x) * fov->delta_dist_x;
	}
	else
	{
		map->step_x = 1;
		fov->side_dist_x = (map->map_x + 1.0 - p->x) * fov->delta_dist_x;
	}
	if (fov->ray_dir_y < 0)
	{
		map->step_y = -1;
		fov->side_dist_y = (p->y - map->map_y) * fov->delta_dist_y;
	}
	else
	{
		map->step_y = 1;
		fov->side_dist_y = (map->map_y + 1.0 - p->y) * fov->delta_dist_y;
	}
}

static void	dda_processing(t_fov *fov, t_map *map, int *side)
{
	int	hit;
	int	tmp;

	hit = 0;
	while (hit == 0)
	{
		if (fov->side_dist_x < fov->side_dist_y)
		{
			fov->side_dist_x += fov->delta_dist_x;
			map->map_x += map->step_x;
			*side = 0;
		}
		else
		{
			fov->side_dist_y += fov->delta_dist_y;
			map->map_y += map->step_y;
			*side = 1;
		}
		tmp = is_wall(map, map->map_x, map->map_y);
		if (tmp == 1)
			hit = 1;
	}
}

static void	get_wall_distance(int side, t_map *map, t_player *p, t_fov *fov)
{
	double	player_angle;
	double	angle_diff;

	if (side == 0)
		fov->distance = (map->map_x - (p->x) + (1 - map->step_x) * 0.5)
			/ fov->ray_dir_x;
	else
		fov->distance = (map->map_y - (p->y) + (1 - map->step_y) * 0.5)
			/ fov->ray_dir_y;
	if (fov->distance == 0)
		fov->distance = 0.0001;
	player_angle = atan2(p->dir_y, p->dir_x);
	angle_diff = fov->ray_angle - player_angle;
	while (angle_diff > M_PI)
		angle_diff -= 2 * M_PI;
	while (angle_diff < -M_PI)
		angle_diff += 2 * M_PI;
	fov->distance *= cos(angle_diff);
}

void	draw_ray(t_player *player, t_fov *fov, t_map *map)
{
	int	side;

	map->map_x = player->x;
	map->map_y = player->y;
	get_delta_dist(fov);
	get_step_side_dist(fov, map, player);
	side = 0;
	dda_processing(fov, map, &side);
	fov->side = side;
	get_wall_distance(side, map, player, fov);
	fov->wall_height = HEIGHT / fov->distance;
	if (side == 0)
		fov->wall_hit_x = player->y + (fov->side_dist_x - fov->delta_dist_x)
			* fov->ray_dir_y;
	else
		fov->wall_hit_x = player->x + (fov->side_dist_y - fov->delta_dist_y)
			* fov->ray_dir_x;
	fov->wall_hit_x -= floor(fov->wall_hit_x);
}
