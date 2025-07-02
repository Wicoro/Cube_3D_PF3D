/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:21:57 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/02 17:52:55 by stdevis          ###   ########.fr       */
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
	if (!map || !map->map_tab)
		return (0x0);
	else if (y < 0 || y >= map->height)
		return (0x0);
	else if (x < 0 || x >= map->width)
		return (0x0);
	else if (map->map_tab[y][x] == ' ')
		return (0xA0A0A0);
	else if (map->map_tab[y][x] == '1')
		return (0x202020);
	else if (map->map_tab[y][x] == '0')
		return (0xFFFFFF);
	else if (map->map_tab[y][x] == 'P')
		return (0xCC0000);
	else
		return (0x0);
}

void	put_pixel(t_imag *img, t_map *map, int x, int y)
{
	int	x_sized;
	int	y_sized;
	int	index;

	x_sized = x + WIDTH / 4;
	y_sized = y + HEIGHT / 4;
	if (x_sized < 0 || x_sized >= WIDTH || y_sized < 0 || y_sized >= HEIGHT)
		return ;
	index = y_sized * img->line_lenght + (x_sized * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + index) = get_color(map, x, y);
}

void	draw_tile(t_imag *img, t_map *map, int x, int y)
{
	int	start_x;
	int	start_y;
	int	i;
	int	j;

	start_x = x * TILE_SIZE;
	start_y = y * TILE_SIZE;
	j = 0;
	while (j < TILE_SIZE)
	{
		i = 0;
		while (i < TILE_SIZE)
		{
			put_pixel(img, map, start_x + i, start_y + j);
			i++;
		}
		j++;
	}
}

void	make_imag(t_map *map, t_imag *img)
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

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		closer(data);
	return (0);
}

int	execution(t_data *data)
{
	if (wind_init(data))
		return (1);
	data->img->addr = mlx_get_data_addr(data->img->img_p,
			&data->img->bits_per_pixel, &data->img->line_lenght,
			&data->img->endian);
	make_imag(data->map, data->img);
	mlx_put_image_to_window(data->mlx_p, data->win_p, data->img->img_p, 0, 0);
	mlx_hook(data->win_p, 17, 0, closer, data);
	mlx_hook(data->win_p, 2, 1L << 0, key_hook, data);
	mlx_loop(data->mlx_p);
	return (0);
}