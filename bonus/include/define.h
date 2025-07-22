/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:52:53 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/22 14:36:26 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include "./cub3d.h"

# define ARG_COUNT_ERROR 1
# define ARG_ERROR 2
# define MALLOC_ERROR 3
# define INVALID_MAP 4

# define HEIGHT 720
# define WIDTH 1000
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

#endif