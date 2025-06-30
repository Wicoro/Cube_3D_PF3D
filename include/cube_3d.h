/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:46:54 by norban            #+#    #+#             */
/*   Updated: 2025/06/30 16:43:28 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft.h"
# include <stdio.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>

# define ARG_COUNT_ERROR 1
# define ARG_ERROR 2
# define MALLOC_ERROR 3

typedef struct	s_assets
{
	char	*no_path;
	char	*so_path;
	char	*ea_path;
	char	*we_path;
	int		fl_color[3];
	int		ce_color[3];
}	t_assets;

typedef struct	s_data
{
	char	**map;
	t_assets	assets;
}	t_data;

#endif
