/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:46:54 by norban            #+#    #+#             */
/*   Updated: 2025/07/21 17:02:44 by norban           ###   ########.fr       */
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
# include <sys/time.h>

# define ARG_COUNT_ERROR 1
# define ARG_ERROR 2
# define MALLOC_ERROR 3
# define INVALID_MAP 4

# define HEIGHT 600
# define WIDTH 800
# define MINIMAP_H ((HEIGHT / 100) * 30)
# define MINIMAP_W MINIMAP_H
# define MINIMAP_BORDER_SIZE 5
# define MINIMAP_OFFSET_X (WIDTH - MINIMAP_W - MINIMAP_W / 10)
# define MINIMAP_OFFSET_Y (HEIGHT - MINIMAP_H - MINIMAP_H / 10)

# define MAX_DOORS 64
# define DOOR_MAX_STATE 20

# define TILE_SIZE 16
# define SPEED 0.2
# define ROT_SPEED
# define ROT_THRESHOLD (WID)
# define MAX_ROTATION_PER_FRAME 0.05
# define GREEN_C 0x2ecc71
# define RED_C 0x7b241c
# ifndef M_PI
#  define M_PI 3.14159265359
# endif
# define FOV (60 * M_PI / 180)

typedef struct s_assets
{
	char		*no_path;
	char		*so_path;
	char		*ea_path;
	char		*we_path;
	char		*do_path;
	int			fl_color[3];
	int			ce_color[3];
}				t_assets;

typedef struct s_textures
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_textures;

typedef struct s_door
{
	int	x;
	int	y;
	int	state;
}	t_door;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		angle;
}				t_player;

typedef struct s_fov
{
	double		ray_angle;
	double		ray_dir_x;
	double		ray_dir_y;
	double		distance;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		wall_height;
	double		wall_hit_x;
	int			nbr_rays;
	int			side;
	int			isdoor;
}				t_fov;

typedef struct s_map
{
	char		**map_tab;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	Bool		check_img;
	int			width;
	int			height;
}				t_map;

typedef struct s_imag
{
	void		*img_p;
	char		*addr;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
}				t_imag;

typedef struct s_mouse
{
	int			delta_x;
	int			prev_x;
}				t_mouse;

typedef struct s_data
{
	void		*mlx_p;
	void		*win_p;
	t_player	player;
	t_map		map;
	t_imag		img[3];
	t_assets	assets;
	t_textures	textures[5];
	t_mouse		mouse;
	long		time;
	t_door		doors[MAX_DOORS];
	int			door_count;
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
void			draw_wall(float x, t_fov *fov, t_data *data);
void			display_border(t_imag *img);
int				get_color_tile(t_map *map, int x, int y);
int				is_wall(t_map *map, int x, int y);
void			display_ray(t_player *player, t_fov *fov, t_imag *img,
					t_map *map);
void			display_player(t_imag *img);
void			display_tiles(t_map *map, t_imag *img, t_player *player);
void			display_wall(int x, t_fov *fov, t_data *data);
void			put_pixel(t_imag *img, t_map *map, int x, int y, int color);
void			draw_ray(t_player *player, t_fov *fov, t_map *map);

#endif
