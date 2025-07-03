/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:46:54 by norban            #+#    #+#             */
/*   Updated: 2025/07/03 19:55:31 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/headers/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <math.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

# define ARG_COUNT_ERROR 1
# define ARG_ERROR 2
# define MALLOC_ERROR 3
# define HEIGHT 1200
# define WIDTH 1200
# define TILE_SIZE 30


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

typedef struct s_map
{
	char		**map_tab;
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
	t_player	*player;
	t_map		*map;
	t_imag		*img;
	t_assets	assets;
}				t_data;

void			print_error(int id);
void			create_map(t_data *data, char **av);
int				execution(t_data *data);
void			initialisation(t_data *data);

#endif
