/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:21:57 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/21 16:27:46 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

long	get_time_in_ms(void)
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

void	init_doors(t_data *data)
{
	int	x;
	int	y;

	data->door_count = 0;
	for (y = 0; y < data->map.height; y++)
	{
		for (x = 0; x < data->map.width; x++)
		{
			if (data->map.map_tab[y][x] == '2' && data->door_count < MAX_DOORS)
			{
				data->doors[data->door_count].x = x;
				data->doors[data->door_count].y = y;
				data->doors[data->door_count].state = 0;
				data->door_count++;
			}
		}
	}
}

int	init_texture(t_data *data, char *path, int i)
{
	data->textures[i].img = mlx_xpm_file_to_image(data->mlx_p, path,
			&data->textures[i].width, &data->textures[i].height);
	if (!data->textures[i].img)
		return (1);
	data->textures[i].addr = mlx_get_data_addr(data->textures[i].img,
			&data->textures[i].bits_per_pixel, &data->textures[i].line_length,
			&data->textures[i].endian);
	return (0);
}

int	init_textures(t_data *data)
{
	if (init_texture(data, data->assets.no_path, 0) == 1)
		return (1);
	init_texture(data, data->assets.so_path, 1);
	init_texture(data, data->assets.ea_path, 2);
	init_texture(data, data->assets.we_path, 3);
	init_texture(data, data->assets.do_path, 4);
	return (0);
}

int	wind_init(t_data *data)
{
	data->mlx_p = mlx_init();
	if (!data->mlx_p)
		return (print_error(3), 1);
	data->win_p = mlx_new_window(data->mlx_p, WIDTH, HEIGHT, "Cub3D");
	if (!data->win_p)
		return (print_error(3), mlx_destroy_display(data->mlx_p), 1);
	if (init_textures(data) == 1)
		return (print_error(3), mlx_destroy_window(data->mlx_p, data->win_p),
			mlx_destroy_display(data->mlx_p), 1);
	data->img[0].img_p = mlx_new_image(data->mlx_p, WIDTH, HEIGHT);
	if (!data->img[0].img_p)
		return (print_error(3), mlx_destroy_window(data->mlx_p, data->win_p),
			mlx_destroy_display(data->mlx_p), 1);
	data->img[1].img_p = mlx_new_image(data->mlx_p, WIDTH, HEIGHT);
	if (!data->img[1].img_p)
		return (print_error(3), mlx_destroy_window(data->mlx_p, data->win_p),
			mlx_destroy_display(data->mlx_p), mlx_destroy_image(data->mlx_p,
				data->img[0].img_p), 1);
	data->img[2].img_p = mlx_new_image(data->mlx_p, MINIMAP_W, MINIMAP_H);
	if (!data->img[2].img_p)
		return (print_error(3), mlx_destroy_window(data->mlx_p, data->win_p),
			mlx_destroy_display(data->mlx_p), mlx_destroy_image(data->mlx_p,
				data->img[0].img_p), mlx_destroy_image(data->mlx_p,
				data->img[1].img_p), 1);
	return (0);
}

int	get_color_tile(t_map *map, int x, int y)
{
	char	c;

	if (!map || !map->map_tab)
		return (0x000000);
	else if (y < 0 || y >= map->height)
		return (0x000000);
	else if (x < 0 || x >= map->width)
		return (0x000000);
	c = map->map_tab[y][x];
	if (c == ' ')
		return (0x000000);
	else if (c == '1')
		return (RED_C);
	else if (c == '2')
		return (0x0000FF);
	else if (c == '3')
		return (0x7F00FF);
	else if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (0xA0A0A0);
	else
		return (0x000000);
}

void	put_pixel(t_imag *img, t_map *map, int x, int y, int color)
{
	int		x_sized;
	int		y_sized;
	int		index;
	char	*addr;

	x_sized = x;
	y_sized = y;
	addr = img[map->check_img].addr;
	if (x_sized < 0 || x_sized >= WIDTH || y_sized < 0 || y_sized >= HEIGHT)
		return ;
	index = y_sized * img[map->check_img].line_lenght + (x_sized
			* (img[map->check_img].bits_per_pixel / 8));
	*(unsigned int *)(addr + index) = color;
}

int	closer(t_data *data)
{
	ft_printf("the ESC key or red cross has been pressed\n");
	mlx_destroy_image(data->mlx_p, data->img[0].img_p);
	mlx_destroy_image(data->mlx_p, data->img[1].img_p);
	mlx_destroy_image(data->mlx_p, data->img[2].img_p);
	mlx_destroy_window(data->mlx_p, data->win_p);
	mlx_destroy_display(data->mlx_p);
	exit(0);
}

int	is_player(char c, t_player *player)
{
	if (c == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		return (0);
	}
	if (c == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		return (0);
	}
	if (c == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		return (0);
	}
	if (c == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		return (0);
	}
	return (1);
}

void	where_player(t_map *map, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (map->map_tab[y])
	{
		x = 0;
		while (map->map_tab[y][x])
		{
			if (!is_player(map->map_tab[y][x], player))
			{
				player->x = x + 0.5;
				player->y = y + 0.5;
			}
			x++;
		}
		y++;
	}
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

void	get_delta_dist(t_fov *fov)
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

void	get_step_side_dist(t_fov *fov, t_map *map, t_player *p)
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

void	draw_ray(t_player *player, t_fov *fov, t_map *map)
{
	int		hit;
	int		side;
	double	player_angle;
	double	angle_diff;
		int tmp;

	map->map_x = player->x;
	map->map_y = player->y;
	get_delta_dist(fov);
	get_step_side_dist(fov, map, player);
	hit = 0;
	side = 0;
	fov->isdoor = 0;

	while (hit == 0)
	{
		if (fov->side_dist_x < fov->side_dist_y)
		{
			fov->side_dist_x += fov->delta_dist_x;
			map->map_x += map->step_x;
			side = 0;
		}
		else
		{
			fov->side_dist_y += fov->delta_dist_y;
			map->map_y += map->step_y;
			side = 1;
		}
		tmp = is_wall(map, map->map_x, map->map_y);
		if (tmp == 1 || tmp == 2)
			hit = 1;
		if (tmp == 2)
			fov->isdoor = 1;
	}
	fov->side = side;
	if (side == 0)
		fov->distance = (map->map_x - (player->x) + (1 - map->step_x) * 0.5)
			/ fov->ray_dir_x;
	else
		fov->distance = (map->map_y - (player->y) + (1 - map->step_y) * 0.5)
			/ fov->ray_dir_y;
	if (fov->distance == 0)
		fov->distance = 0.0001;
	// --- CORRECTED FISHEYE FIX ---
	// Calculate player viewing angle once (cache for speed)
	player_angle = atan2(player->dir_y, player->dir_x);
	// Cosine of angle difference between ray and player view
	angle_diff = fov->ray_angle - player_angle;
	// Normalize angle_diff to range [-PI, PI] to avoid errors
	while (angle_diff > M_PI)
		angle_diff -= 2 * M_PI;
	while (angle_diff < -M_PI)
		angle_diff += 2 * M_PI;
	// Apply cosine fisheye correction
	fov->distance *= cos(angle_diff);
	// Calculate wall height for this ray
	fov->wall_height = HEIGHT / fov->distance;
	// Calculate exact hit position on the wall for texture mapping
	if (side == 0)
		fov->wall_hit_x = player->y + (fov->side_dist_x - fov->delta_dist_x)
			* fov->ray_dir_y;
	else
		fov->wall_hit_x = player->x + (fov->side_dist_y - fov->delta_dist_y)
			* fov->ray_dir_x;
	fov->wall_hit_x -= floor(fov->wall_hit_x);
}

int	get_rgb_color(int *color)
{
	return (color[0] << 16 | color[1] << 8 | color[2]);
}

void	display_wall(int x, t_fov *fov, t_data *data)
{
	t_textures		*tex;
	unsigned int	color;
	int				tex_x;
	int				tex_y;
	int				index;
	int				y;
	int				horizontal_offset = 0;
	int 			d;

	int draw_start, draw_end, wall_height;
	if (fov->isdoor == 1)
	{
		tex = &data->textures[4];

		// === Add this: compute vertical offset for animation ===
		for (int i = 0; i < data->door_count; i++)
		{
			if (data->doors[i].x == data->map.map_x &&
				data->doors[i].y == data->map.map_y)
			{
				horizontal_offset = (tex->height * data->doors[i].state) / DOOR_MAX_STATE;
				break;
			}
		}
	}
	else if (fov->side == 0)
		tex = (fov->ray_dir_x > 0) ? &data->textures[3] : &data->textures[2];
	else
		tex = (fov->ray_dir_y > 0) ? &data->textures[1] : &data->textures[0];
	if (!tex || !tex->addr)
		return ;
	wall_height = (int)(HEIGHT / fov->distance);
	draw_start = -wall_height * 0.5 + HEIGHT * 0.5;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = wall_height * 0.5 + HEIGHT * 0.5;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	tex_x = (int)(fov->wall_hit_x * tex->width) - horizontal_offset;
	if ((fov->side == 0 && fov->ray_dir_x > 0) || (fov->side == 1 && fov->ray_dir_y < 0))
    	tex_x = tex->width - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	for (y = draw_start; y <= draw_end; y++)
	{
		d = y * 256 - HEIGHT * 128 + wall_height * 128;
		tex_y = ((d * tex->height) / wall_height) / 256;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		if (tex_y < 0)
			tex_y = 0;
		index = tex_y * tex->line_length + tex_x * (tex->bits_per_pixel / 8);
		color = *(unsigned int *)(tex->addr + index);
		put_pixel(data->img, &data->map, x, y, color);
	}
}

void	draw_wall(float x, t_fov *fov, t_data *data)
{
	int	draw_start;
	int	draw_end; 
	int	i;

	draw_start = -fov->wall_height * 0.5 + HEIGHT * 0.5;
	draw_end = fov->wall_height * 0.5 + HEIGHT * 0.5;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	i = 0;
	while (i < HEIGHT)
	{
		if (i < draw_start)
			put_pixel(data->img, &data->map, x, i,
				get_rgb_color(data->assets.ce_color));
		if (i > draw_end && i < HEIGHT)
			put_pixel(data->img, &data->map, x, i,
				get_rgb_color(data->assets.fl_color));
		i++;
	}
	display_wall(x, fov, data);
}

void	draw_player_fov(t_data *data)
{
	t_fov	fov;
	int		i;
	double	step;
	double	start_angle;

	ft_memset(data->img[2].addr, 0, MINIMAP_H * MINIMAP_W * 4);
	display_tiles(&data->map, data->img, &data->player);
	display_player(data->img);
	display_border(data->img);
	step = FOV / WIDTH;
	start_angle = atan2(data->player.dir_y, data->player.dir_x) - (FOV * 0.5);
	i = 0;
	while (i < WIDTH)
	{
		fov.ray_angle = start_angle + (i * step);
		fov.ray_dir_x = cos(fov.ray_angle);
		fov.ray_dir_y = sin(fov.ray_angle);
		draw_ray(&data->player, &fov, &data->map);
		display_ray(&data->player, &fov, data->img, &data->map);
		draw_wall(i, &fov, data);
		i++;
	}
}

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

void	clear_image(t_imag *img, t_map *map)
{
	int	img_size;

	img_size = HEIGHT * WIDTH * 4;
	map->check_img = !map->check_img;
	ft_memset(img[map->check_img].addr, 0, img_size);
}

/* void	open_door(t_data *data)
{
	int		i;
	double	x;
	double	y;

	i = 0;
	x = data->player.x;
	y = data->player.y;
	while (i <= (TILE_SIZE * 2))
	{
		x += data->player.dir_x;
		y += data->player.dir_y;
		if (data->map.map_x == data->player.x
			&& data->map.map_y == data->player.y)
		{
			i++;
			continue ;
		}
		if (data->map.map_tab[(int)y][(int)x] == '2')
		{
			data->map.map_tab[(int)y][(int)x] = '3';
			break ;
		}
		else if (data->map.map_tab[(int)y][(int)x] == '3')
		{
			data->map.map_tab[(int)y][(int)x] = '2';
			break ;
		}
		i++;
	}
} */

void	animate_door_open(t_data *data, int door_index)
{
	t_door	*door;

	door = &data->doors[door_index];
	if (door->state >= DOOR_MAX_STATE)
		return;
	while (door->state < DOOR_MAX_STATE)
	{
		door->state++;
		clear_image(data->img, &data->map);
		draw_player_fov(data);
		mlx_put_image_to_window(data->mlx_p, data->win_p,
			data->img[data->map.check_img].img_p, 0, 0);
		mlx_put_image_to_window(data->mlx_p, data->win_p, data->img[2].img_p,
			WIDTH - MINIMAP_W - MINIMAP_W / 10, HEIGHT - MINIMAP_H - MINIMAP_H / 10);
		mlx_do_sync(data->mlx_p);
		ft_sleep(30);
	}
	data->map.map_tab[data->doors[door_index].y][data->doors[door_index].x] = '3'; 
}

void	animate_door_close(t_data *data, int door_index)
{
	t_door	*door = &data->doors[door_index];

	if (door->state <= 0)
		return;

	data->map.map_tab[data->doors[door_index].y][data->doors[door_index].x] = '2'; 
	while (door->state > 0)
	{
		door->state--;
		clear_image(data->img, &data->map);
		draw_player_fov(data);
		mlx_put_image_to_window(data->mlx_p, data->win_p,
			data->img[data->map.check_img].img_p, 0, 0);
		mlx_put_image_to_window(data->mlx_p, data->win_p, data->img[2].img_p,
			WIDTH - MINIMAP_W - MINIMAP_W / 10, HEIGHT - MINIMAP_H - MINIMAP_H / 10);
		mlx_do_sync(data->mlx_p);
		ft_sleep(30);
	}
}

void	open_door(t_data *data)
{
	double	x = data->player.x;
	double	y = data->player.y;
	int		map_player_x = x;
	int		map_player_y = y;
	t_door *door;

	for (int i = 0; i < TILE_SIZE * 2; i++)
	{
		x += data->player.dir_x;
		y += data->player.dir_y;

		int tx = x;
		int ty = y;

		if (tx == map_player_x && ty == map_player_y)
			continue ;
		for (int j = 0; j < data->door_count; j++)
		{
			door = &data->doors[j];
			if (door->x == tx && door->y == ty)
			{

				if (door->state == 0)
					animate_door_open(data, j);
				else if (door->state == DOOR_MAX_STATE)
					animate_door_close(data, j);
				return;
			}
		}
	}
}
int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		closer(data);
	else if (keycode == XK_w)
		move_player(data, 1);
	else if (keycode == XK_s)
		move_player(data, 0);
	else if (keycode == XK_d)
		strafe_player(data, 1);
	else if (keycode == XK_a)
		strafe_player(data, 0);
	else if (keycode == XK_Left)
		rotate_player(&data->player, -0.10);
	else if (keycode == XK_Right)
		rotate_player(&data->player, 0.10);
	else if (keycode == XK_space)
		open_door(data);
	clear_image(data->img, &data->map);
	draw_player_fov(data);
	mlx_put_image_to_window(data->mlx_p, data->win_p,
		data->img[data->map.check_img].img_p, 0, 0);
	mlx_put_image_to_window(data->mlx_p, data->win_p, data->img[2].img_p, WIDTH
		- MINIMAP_W - MINIMAP_W / 10, HEIGHT - MINIMAP_H - MINIMAP_H / 10);
	return (0);
}

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
		clear_image(data->img, &data->map);
		draw_player_fov(data);
		mlx_put_image_to_window(data->mlx_p, data->win_p,
			data->img[data->map.check_img].img_p, 0, 0);
		mlx_put_image_to_window(data->mlx_p, data->win_p, data->img[2].img_p,
			WIDTH - MINIMAP_W - MINIMAP_W / 10, HEIGHT - MINIMAP_H - MINIMAP_H
				/ 10);
		mlx_mouse_move(data->mlx_p, data->win_p, WIDTH / 2, HEIGHT / 2);
	}
	return (0);
}

int	execution(t_data *data)
{
	int i;
	
	i = 0;
	if (wind_init(data))
		return (1);
	init_doors(data);
	data->img[0].addr = mlx_get_data_addr(data->img[0].img_p,
			&data->img[0].bits_per_pixel, &data->img[0].line_lenght,
			&data->img[0].endian);
	data->img[1].addr = mlx_get_data_addr(data->img[1].img_p,
			&data->img[1].bits_per_pixel, &data->img[1].line_lenght,
			&data->img[1].endian);
	data->img[2].addr = mlx_get_data_addr(data->img[2].img_p,
			&data->img[2].bits_per_pixel, &data->img[2].line_lenght,
			&data->img[2].endian);
	where_player(&data->map, &data->player);
	draw_player_fov(data);
	mlx_put_image_to_window(data->mlx_p, data->win_p,
		data->img[data->map.check_img].img_p, 0, 0);
	mlx_put_image_to_window(data->mlx_p, data->win_p, data->img[2].img_p, WIDTH
		- MINIMAP_W - MINIMAP_W / 10, HEIGHT - MINIMAP_H - MINIMAP_H / 10);
	mlx_hook(data->win_p, 17, 0, closer, data);
	mlx_hook(data->win_p, 2, 1L << 0, key_hook, data);
	mlx_mouse_move(data->mlx_p, data->win_p, WIDTH * 0.5, HEIGHT * 0.5);
	mlx_hook(data->win_p, 6, 1L << 6, mouse_hook, data);
	mlx_loop(data->mlx_p);
	return (0);
}
