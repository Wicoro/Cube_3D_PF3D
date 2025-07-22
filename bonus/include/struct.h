/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:52:55 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/22 18:07:12 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub3d.h"

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
	int			tex_x;
}				t_textures;

typedef struct s_door
{
	int			x;
	int			y;
	int			state;
}				t_door;

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

typedef struct s_minimap
{
	int			minimap_h;
	int			minimap_w;
}				t_minimap;

typedef struct s_data
{
	void		*mlx_p;
	void		*win_p;
	t_player	player;
	t_map		map;
	t_imag		img[3];
	t_assets	assets;
	t_textures	textures[5];
	t_door		doors[MAX_DOORS];
	t_minimap	minimap;
	int			door_count;
}				t_data;

typedef struct s_map_coord
{
	int			x;
	int			y;
}				t_map_coord;

#endif