/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:46:54 by norban            #+#    #+#             */
/*   Updated: 2025/07/21 17:14:15 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/headers/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "define.h"
# include "struct.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <sys/time.h>

/*===============================ERROR==================================*/
void	print_error(int id);

/*===============================MINIMAP==================================*/
void	display_minimap(t_data *data);
void	display_border(t_imag *img);
void	display_player(t_imag *img);
void	display_ray(t_player *player, t_fov *fov, t_imag *img, t_map *map);
void	display_tiles(t_map *map, t_imag *img, t_player *player);

/*===============================PARSING==================================*/
/*---------------------------get_assets-------------------------------*/

int		get_assets(t_assets *assets, int fd);

/*---------------------------get_map_utils-------------------------------*/

int		get_squared_map(t_map *map);
void	get_map_dimension(t_map *map);
void	remove_map_nl(t_map *map);

/*---------------------------get_map-------------------------------*/

int		get_map(t_map *map, int fd);

/*---------------------------parse_map_border.c-------------------------------*/

int		parse_map_border(t_map *map);

int		execution(t_data *data);
void	draw_wall(float x, t_fov *fov, t_data *data);
int		get_color_tile(t_map *map, int x, int y);
int		is_wall(t_map *map, int x, int y);

#endif
