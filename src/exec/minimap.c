#include "cub3d.h"

static void	add_pixel(t_imag *img, int x, int y, int color)
{
	int		x_sized;
	int		y_sized;
	int		index;
	char	*addr;

	x_sized = x;
	y_sized = y;
	addr = img[2].addr;
	if (x_sized < 0 || x_sized >= MINIMAP_W || y_sized < 0 || y_sized >= MINIMAP_H)
		return ;
	index = y_sized * img[2].line_lenght + (x_sized * (img[2].bits_per_pixel
				/ 8));
	*(unsigned int *)(addr + index) = color;
}

static void	display_map_tile(t_imag *img, t_map *map, int x, int y, int off_x, int off_y)
{
	int	start_x;
	int	start_y;
	int	i;
	int	j;

	start_x = (x * TILE_SIZE) - off_x;
	start_y = (y * TILE_SIZE) - off_y;
	j = 1;
	while (j <= TILE_SIZE)
	{
		i = 1;
		while (i <= TILE_SIZE)
		{
			add_pixel(img, start_x + i, start_y + j, get_color_tile(map, x,
						y));
			i++;
		}
		j++;
	}
}

static void display_tiles(t_map *map, t_imag *img, t_player *player)
{
	int	i;
	int	j;

	j = 0;
	while (map->map_tab[j])
	{
		i = 0;
		while (map->map_tab[j][i])
		{
			if (j > (player->y / TILE_SIZE) - 11 && j < (player->y / TILE_SIZE) + 11
				&& i > (player->x / TILE_SIZE) - 11 && i < (player->x / TILE_SIZE) + 11)
				display_map_tile(img, map, i, j, player->x - MINIMAP_W / 2, player->y - MINIMAP_H / 2);
			i++;
		}
		j++;
	}
}
void	display_player(t_imag *img)
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
				add_pixel(img, MINIMAP_W / 2 + i, MINIMAP_H / 2 + j, GREEN_C);
			i++;
		}
		j++;
	}
}

void	display_ray(t_player *player, t_fov *fov, t_imag *img, t_map *map)
{
	int		i;
	float	px;
	float	px_n;
	float	py;
	float	py_n;

	i = 0;
	while (1)
	{
		px = player->x + (fov->ray_dir_x * i);
		px_n = player->x + (fov->ray_dir_x * (i + 1));
		py = player->y + (fov->ray_dir_y * i);
		py_n = player->y + (fov->ray_dir_y * (i + 1));
		if (is_wall(map, px, py) || is_wall(map, px_n, py_n))
			break ;
		add_pixel(img, (px - player->x) + MINIMAP_W / 2, (py - player->y) + MINIMAP_H / 2, GREEN_C);
		i++;
	}
}

void	display_player_fov(t_data *data)
{
	t_fov	fov;
	int		i;
	float	step;
	float	start_angle;

	step = FOV / NUM_RAYS;
	start_angle = atan2(data->player.dir_y, data->player.dir_x) - (FOV / 2);
	i = 0;
	while (i < NUM_RAYS)
	{
		fov.ray_angle = start_angle + (i * step);
		fov.ray_dir_x = cos(fov.ray_angle);
		fov.ray_dir_y = sin(fov.ray_angle);
		display_ray(&data->player, &fov, data->img, &data->map);
		i++;
	}
}

void	display_minimap(t_data *data)
{
	printf("x : %f; y : %f\n", data->player.x, data->player.y);
	ft_memset(data->img[2].addr, 0, MINIMAP_H * MINIMAP_W * 4);
	display_tiles(&data->map, data->img, &data->player);
	display_player(data->img);
	display_player_fov(data);
	mlx_put_image_to_window(data->mlx_p, data->win_p, data->img[2].img_p, WIDTH - MINIMAP_W, HEIGHT - MINIMAP_H);
}
