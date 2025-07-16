#include "../../include/cub3d.h"

static void	add_minimap_pixel(t_imag *img, int x, int y, int color)
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
			add_minimap_pixel(img, start_x + i, start_y + j, get_color_tile(map, x,
						y));
			i++;
		}
		j++;
	}
}

void display_tiles(t_map *map, t_imag *img, t_player *player)
{
	int	i;
	int	j;
    int range_y;
    int range_x;

    range_y = (int)(MINIMAP_H / TILE_SIZE / 2);
    range_x = (int)(MINIMAP_W / TILE_SIZE / 2);
	j = 0;
	while (map->map_tab[j])
	{
		i = 0;
		while (map->map_tab[j][i])
		{
			if (fabs(i - player->x) <= range_x && fabs(j - player->y) <= range_y)
				display_map_tile(img, map, i, j, player->x - MINIMAP_W * 0.5, player->y - MINIMAP_H * 0.5);
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

	size = TILE_SIZE * 0.25;
	j = -size;
	while (j <= size)
	{
		i = -size;
		while (i <= size)
		{
			if (i * i + j * j <= size * size)
				add_minimap_pixel(img, MINIMAP_W * 0.5 + i, MINIMAP_H * 0.5 + j, GREEN_C);
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
		if (is_wall(map, (int)px, (int)py) || is_wall(map, (int)px_n, (int)py_n))
			break ;
		add_minimap_pixel(img, (int)(px - player->x) + MINIMAP_W * 0.5, (int)(py - player->y) + MINIMAP_H * 0.5, GREEN_C);
		i++;
	}
}

void	display_border(t_imag *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_H)
	{
		j = 0;
		while (j < MINIMAP_W)
		{
			if (i < MINIMAP_BORDER_SIZE || i > MINIMAP_H - MINIMAP_BORDER_SIZE)
				add_minimap_pixel(img, j, i, GREEN_C);
			else if (j < MINIMAP_BORDER_SIZE || j > MINIMAP_W - MINIMAP_BORDER_SIZE)
				add_minimap_pixel(img, j, i, GREEN_C);
			j++;
		}
		i++;
	}
}
