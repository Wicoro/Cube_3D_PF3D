/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:21:57 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/03 19:56:53 by stdevis          ###   ########.fr       */
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
	data->img->img_p = mlx_new_image(data->mlx_p, WIDTH, HEIGHT);
	if (!data->img->img_p)
		return (print_error(3), mlx_destroy_window(data->mlx_p, data->win_p),
			mlx_destroy_display(data->mlx_p), 1);
	return (0);
}

int	get_color(t_map *map, int x, int y)
{
	char	c;

	if (!map || !map->map_tab)
		return (0x0);
	else if (y < 0 || y >= map->height)
		return (0x0);
	else if (x < 0 || x >= map->width)
		return (0x0);
	c = map->map_tab[y][x];
	if (c == ' ')
		return (0x0);
	else if (c == '1')
		return (0x911010);
	else if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (0xA0A0A0);
	else
		return (0x0);
}

void	put_pixel(t_imag *img, t_map *map, int x, int y, int check)
{
	int	x_sized;
	int	y_sized;
	int	index;

	x_sized = x + WIDTH / 4;
	y_sized = y + HEIGHT / 4;
	if (x_sized < 0 || x_sized >= WIDTH || y_sized < 0 || y_sized >= HEIGHT)
		return ;
	index = y_sized * img->line_lenght + (x_sized * (img->bits_per_pixel / 8));
	if (check == 0)
		*(unsigned int *)(img->addr + index) = get_color(map, x / TILE_SIZE, y
				/ TILE_SIZE);
	else if (check == 1)
		*(unsigned int *)(img->addr + index) = 0x212f3d ; 
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
	while (j < TILE_SIZE)
	{
		i = 1;
		while (i < TILE_SIZE)
		{
			put_pixel(img, map, start_x + i, start_y + j, 0);
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
	mlx_destroy_image(data->mlx_p, data->img->img_p);
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
				player->x = x * TILE_SIZE;
				player->y = y * TILE_SIZE;
			}
			x++;
		}
		y++;
	}
}

void	draw_player_circle(float x, float y, t_imag *img, t_map *map)
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
			if ( i * i + j * j <= size * size)
				put_pixel(img, map, x + i, y + j, 1);
			i++;
		}
		j++;
	}
}

void	draw_player_line(float x, float y, t_imag *img, t_player *p, t_map *map)
{
	int i;
	int px;
	int py;
	
	i = 0;
	while (i < TILE_SIZE / 2.5)
	{
		px = (x + (p->dir_x * i));
		py = (y + (p->dir_y * i));
		put_pixel(img, map, px, py, 1);
		i++;
	}
}

void	draw_player(t_player *player, t_imag *img, t_map *map)
{
	float	x_sized;
	float	y_sized;

	x_sized = (player->x) + (TILE_SIZE / 2);
	y_sized = (player->y) + (TILE_SIZE / 2);
	draw_player_circle(x_sized, y_sized, img, map);
	draw_player_line(x_sized, y_sized, img, player, map);
}

void	put_player(t_map *map, t_imag *img, t_player *player)
{
	where_player(map, player);
	draw_player(player, img, map);
}

int	is_wall(t_map *map, float x, float y)
{
	char c;
	int map_x;
	int map_y;
	
	map_x = (x + (TILE_SIZE / 2)) / TILE_SIZE;
	map_y = (y + (TILE_SIZE / 2)) / TILE_SIZE;
	c = map->map_tab[map_y][map_x];
	if (map_x < 0 || map_x >= map->width || map_y < 0 || map_y >= map->height)
		return (1);
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (0);
	return (1);
}

void	move_player(t_data *data, float dx, float dy)
{
	float new_x;
	float new_y;
	
	new_x = data->player->x + dx;
	new_y = data->player->y + dy;
	if (!is_wall(data->map, new_x, data->player->y))
		data->player->x = new_x;
	if (!is_wall(data->map, data->player->x, new_y))
		data->player->y = new_y;
}

void	rotate_player(t_player *player, float angle)
{
	float old_dir_x;
	float old_dir_y;
	
	old_dir_x = player->dir_x;
	old_dir_y = player->dir_y;
	
	player->dir_x = old_dir_x * cos(angle) - old_dir_y * sin(angle);
	player->dir_y = old_dir_y * sin(angle) + old_dir_y * cos(angle);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		closer(data);
	if (keycode == XK_w)
			move_player(data, 0, -2);
	if (keycode == XK_s)
			move_player(data, 0, 2);
	if (keycode == XK_a)
			rotate_player(data->player, -0.05);
	if (keycode == XK_d)
			rotate_player(data->player, 0.05);
	make_map(data->map, data->img);
	draw_player(data->player, data->img, data->map);
	mlx_put_image_to_window(data->mlx_p, data->win_p, data->img->img_p, 0, 0);
	return (0);
}

int	execution(t_data *data)
{
	if (wind_init(data))
		return (1);
	data->img->addr = mlx_get_data_addr(data->img->img_p,
			&data->img->bits_per_pixel, &data->img->line_lenght,
			&data->img->endian);
	make_map(data->map, data->img);
	put_player(data->map, data->img, data->player);
	mlx_put_image_to_window(data->mlx_p, data->win_p, data->img->img_p, 0, 0);
	mlx_hook(data->win_p, 17, 0, closer, data);
	mlx_hook(data->win_p, 2, 1L << 0, key_hook, data);
	mlx_loop(data->mlx_p);
	return (0);
}
