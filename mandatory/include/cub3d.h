/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:46:54 by norban            #+#    #+#             */
/*   Updated: 2025/07/23 21:53:57 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../libft/headers/libft.h"
# include "../../minilibx-linux/mlx.h"
# include "../../minilibx-linux/mlx_int.h"
# include "define.h"
# include "struct.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <sys/time.h>

/*===============================GAME==================================*/

int		game_loop(t_data *data);
void	render(t_data *data, Bool check);
void	move_player(t_data *data, int up_or_down);
void	strafe_player(t_data *data, int right_or_left);
void	rotate_player(t_player *player, double angle);
void	where_player(t_map *map, t_player *player);
int		is_wall(t_map *map, int x, int y);
int		init_textures(t_data *data);
void	destroy_textures(t_data *data);
int		wind_init(t_data *data);
int		init_data(t_data *data, char *path);
void	print_error(int id);
void	destroy_texture(t_data *data);
int		closer(t_data *data);

/*===============================PARSING==================================*/

int		get_assets(t_assets *assets, int fd);
int		get_squared_map(t_map *map);
void	get_map_dimension(t_map *map);
void	remove_map_nl(t_map *map);
int		get_map(t_map *map, int fd);
int		parse_map_border(t_map *map);
int		is_it_end(int fd, char *line);
int		line_full_space(char *line);
int		get_rgb_assets(t_assets *assets, char *line);

/*===============================RAYCASTING==================================*/

int		get_rgb_color(int *color);
int		get_color_tile(t_map *map, int x, int y);
void	put_pixel(t_data *data, int x, int y, int color);
void	raycasting(t_data *data);
void	display_wall(int x, t_fov *fov, t_data *data);
void	draw_ray(t_player *player, t_fov *fov, t_map *map);

#endif
