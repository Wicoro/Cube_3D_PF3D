/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:48:46 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/22 19:31:33 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	clear_image(t_imag *img, t_map *map)
{
	int	img_size;

	img_size = HEIGHT * WIDTH * 4;
	map->check_img = !map->check_img;
	ft_memset(img[map->check_img].addr, 0, img_size);
}

void	render(t_data *data, Bool check)
{
	if (check)
		clear_image(data->img, &data->map);
	raycasting(data);
	mlx_put_image_to_window(data->mlx_p, data->win_p,
		data->img[data->map.check_img].img_p, 0, 0);
}

static int	closer_printf(t_data *data)
{
	ft_printf("the ESC key or red cross has been pressed\n");
	closer(data);
	return (0);
}

static int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		closer_printf(data);
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
	render(data, 1);
	return (0);
}

int	game_loop(t_data *data)
{
	int	i;

	i = 0;
	if (wind_init(data))
		closer(data);
	while (i < 2)
	{
		data->img[i].addr = mlx_get_data_addr(data->img[i].img_p,
				&data->img[i].bits_per_pixel, &data->img[i].line_lenght,
				&data->img[i].endian);
		i++;
	}
	where_player(&data->map, &data->player);
	render(data, 0);
	mlx_hook(data->win_p, 17, 0, closer_printf, data);
	mlx_hook(data->win_p, 2, 1L << 0, key_hook, data);
	mlx_loop(data->mlx_p);
	return (0);
}
