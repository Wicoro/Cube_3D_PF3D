/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:21:57 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/07 17:39:50 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	wind_init(t_data *data)
{
	data->mlx_p = mlx_init();
	if (!data->mlx_p)
		return (print_error(3), 1);
	data->win_p = mlx_new_window(data->mlx_p, WIDTH, HEIGHT, "Cub3D");
	if (!data->win_p)
		return (print_error(3), mlx_destroy_display(data->mlx_p), 1);
	data->img[0].img_p = mlx_new_image(data->mlx_p, WIDTH, HEIGHT);
	if (!data->img[0].img_p)
		return (print_error(3), mlx_destroy_window(data->mlx_p, data->win_p),
			mlx_destroy_display(data->mlx_p), 1);
	data->img[1].img_p = mlx_new_image(data->mlx_p, WIDTH, HEIGHT);
	if (!data->img[1].img_p)
		return (print_error(3), mlx_destroy_window(data->mlx_p, data->win_p),
			mlx_destroy_display(data->mlx_p), mlx_destroy_image(data->mlx_p,
				data->img[0].img_p), 1);
	return (0);
}

int	get_color(t_map *map, int x, int y)
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
	addr = img[map->check_img].addr;
	if (x_sized < 0 || x_sized >= WIDTH || y_sized < 0 || y_sized >= HEIGHT)
		return ;
	index = y_sized * img[0].line_lenght + (x_sized * (img[0].bits_per_pixel
				/ 8));
	*(unsigned int *)(addr + index) = color;
}

void	draw_tile(t_imag *img, t_map *map, int x, int y)
{
	int	start_x;
	int	start_y;
	int	i;
	int	j;

	start_x = x * TILE_SIZE;
	start_y = y * TILE_SIZE;
	j = 1;
	while (j <= TILE_SIZE)
	{
		i = 1;
		while (i <= TILE_SIZE)
		{
			put_pixel(img, map, start_x + i, start_y + j, get_color(map, x,
					y));
			i++;
		}
		j++;
	}
}

void	make_map(t_map *map, t_imag *img)
{
	int	i;
	int	j;

	j = 0;
	while (map->map_tab[j])
	{
		i = 0;
		while (map->map_tab[j][i])
		{
			draw_tile(img, map, i, j);
			i++;
		}
		j++;
	}
}

int	closer(t_data *data)
{
	ft_printf("the ESC key or red cross has been pressed\n");
	mlx_destroy_image(data->mlx_p, data->img[0].img_p);
	mlx_destroy_image(data->mlx_p, data->img[1].img_p);
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
				player->x = x * TILE_SIZE + (TILE_SIZE / 2);
				player->y = y * TILE_SIZE + (TILE_SIZE / 2);
			}
			x++;
		}
		y++;
	}
}

int	is_wall(t_map *map, float x, float y)
{
	char	c;
	int		map_x;
	int		map_y;

	map_x = x / TILE_SIZE;
	map_y = y / TILE_SIZE;
	c = map->map_tab[map_y][map_x];
	if (map_x < 0 || map_x >= map->width || map_y < 0 || map_y >= map->height)
		return (1);
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (0);
	return (1);
}

void	draw_player_circle(t_imag *img, t_map *map, t_player *p)
{
	int	size;
	int	j;
	int	i;

	size = TILE_SIZE / 4;
	j = -size;
	while (j <= size)
	{
		i = -size;
		while (i <= size)
		{
			if (i * i + j * j <= size * size)
				put_pixel(img, map, p->x + i, p->y + j, GREEN_C);
			i++;
		}
		j++;
	}
}

void	draw_ray(t_player *player, t_fov *fov, t_imag *img, t_map *map)
{
	int		i;
	float	px;
	float	py;
	float	player_angle;

	i = 0;
	while (1)
	{
		px = player->x + (fov->ray_dir_x * i);
		py = player->y + (fov->ray_dir_y * i);
		if (is_wall(map, px, py))
		{
			fov->distance = sqrtf(pow((px - player->x), 2) + pow((py
							- player->y), 2));
			player_angle = atan2(player->dir_y, player->dir_x);
			fov->distance *= cos(fov->ray_angle - player_angle);
			fov->wall_height = (TILE_SIZE * HEIGHT / fov->distance);
			break ;
		}
		put_pixel(img, map, px, py, GREEN_C);
		i++;
	}
}

void	draw_wall(float x, t_fov *fov, t_imag *img, t_map *map)
{
	int	draw_start;
	int	draw_end;
	int	i;

	draw_start = -fov->wall_height / 2 + HEIGHT / 2;
	draw_end = fov->wall_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	while (draw_start <= draw_end)
	{
		i = 0;
		while (i < COLUMN_SIZE)
		{
			put_pixel(img, map, x + i, draw_start, RED_C);
			i++;
		}
		draw_start++;
	}
}

void	draw_player_fov(t_imag *img, t_player *p, t_map *map, int check)
{
	t_fov	fov;
	int		i;
	float	step;
	float	start_angle;

	step = FOV / NUM_RAYS;
	start_angle = atan2(p->dir_y, p->dir_x) - (FOV / 2);
	i = 0;
	while (i < NUM_RAYS)
	{
		fov.ray_angle = start_angle + (i * step);
		fov.ray_dir_x = cos(fov.ray_angle);
		fov.ray_dir_y = sin(fov.ray_angle);
		draw_ray(p, &fov, img, map);
		if (check == 0)
			draw_wall(i * COLUMN_SIZE, &fov, img, map);
		i++;
	}
}

void	put_player(t_map *map, t_imag *img, t_player *player)
{
	where_player(map, player);
	draw_player_circle(img, map, player);
	draw_player_fov(img, player, map, 0);
}

void	move_player(t_data *data, int up_or_down)
{
	float	new_x;
	float	new_y;

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
	if (!is_wall(&data->map, new_x, data->player.y))
		data->player.x = new_x;
	if (!is_wall(&data->map, data->player.x, new_y))
		data->player.y = new_y;
}

void	rotate_player(t_player *player, float angle)
{
	float	old_dir_x;
	float	old_dir_y;

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

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		closer(data);
	if (keycode == XK_w)
		move_player(data, 1);
	if (keycode == XK_s)
		move_player(data, 0);
	if (keycode == XK_a)
		rotate_player(&data->player, -0.10);
	if (keycode == XK_d)
		rotate_player(&data->player, 0.10);
	clear_image(data->img, &data->map);
	draw_player_fov(data->img, &data->player, &data->map, 0);
	make_map(&data->map, data->img);
	draw_player_circle(data->img, &data->map, &data->player);
	draw_player_fov(data->img, &data->player, &data->map, 1);
	mlx_put_image_to_window(data->mlx_p, data->win_p,
		data->img[data->map.check_img].img_p, 0, 0);
	return (0);
}

int	execution(t_data *data)
{
	if (wind_init(data))
		return (1);
	data->img[0].addr = mlx_get_data_addr(data->img[0].img_p,
			&data->img[0].bits_per_pixel, &data->img[0].line_lenght,
			&data->img[0].endian);
	data->img[1].addr = mlx_get_data_addr(data->img[1].img_p,
			&data->img[1].bits_per_pixel, &data->img[1].line_lenght,
			&data->img[1].endian);
	make_map(&data->map, data->img);
	put_player(&data->map, data->img, &data->player);
	mlx_put_image_to_window(data->mlx_p, data->win_p,
		data->img[data->map.check_img].img_p, 0, 0);
	mlx_hook(data->win_p, 17, 0, closer, data);
	mlx_hook(data->win_p, 2, 1L << 0, key_hook, data);
	mlx_loop(data->mlx_p);
	return (0);
}
