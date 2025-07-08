/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:46:54 by norban            #+#    #+#             */
/*   Updated: 2025/07/08 18:24:46 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/headers/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>

# define ARG_COUNT_ERROR 1
# define ARG_ERROR 2
# define MALLOC_ERROR 3
# define INVALID_MAP 4

# define HEIGHT 1440
# define WIDTH 2560
# define MINIMAP_H (20 * TILE_SIZE)
# define MINIMAP_W (20 * TILE_SIZE)

# define TILE_SIZE 15
# define SPEED 4
# define GREEN_C 0x2ecc71
# define RED_C 0x7b241c  
# ifndef M_PI
#  define M_PI 3.14159265359
# endif
# define FOV (60 * M_PI / 180)
# define NUM_RAYS 1280
# define COLUMN_SIZE (WIDTH / NUM_RAYS)

typedef struct s_assets
{
	char		*no_path;
	char		*so_path;
	char		*ea_path;
	char		*we_path;
	int			fl_color[3];
	int			ce_color[3];
}				t_assets;

typedef struct s_player
{
	float		x;
	float		y;
	float		dir_x;
	float		dir_y;
}				t_player;

typedef struct s_fov
{
	float		ray_angle;
	float		ray_dir_x;
	float		ray_dir_y;
	float		distance;
	float		wall_height;
}				t_fov;

typedef struct s_map
{
	char		**map_tab;
	int			check_img;
	int			width;
	int			height;
}				t_map;

typedef struct s_imag
{
	char		*img_p;
	char		*addr;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
}				t_imag;

typedef struct s_data
{
	void		*mlx_p;
	void		*win_p;
	t_player	player;
	t_map		map;
	t_imag		img[3];
	t_assets	assets;
}				t_data;

void			print_error(int id);
int				execution(t_data *data);
int				get_map(t_map *map, int fd);
void			remove_map_nl(t_map *map);
void			get_map_dimension(t_map *map);
int				get_squared_map(t_map *map);
int				parse_map_border(t_map *map);
int				get_assets(t_assets *assets, int fd);
void			display_minimap(t_data *data);


int	get_color_tile(t_map *map, int x, int y);
int	is_wall(t_map *map, float x, float y);

#endif
