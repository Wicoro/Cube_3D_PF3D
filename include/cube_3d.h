/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:46:54 by norban            #+#    #+#             */
/*   Updated: 2025/06/30 13:58:20 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft.h"
# include <stdio.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>

typedef struct	s_data
{
	struct	s_asset	*asset;
}	t_asset;

typedef struct	s_asset
{
	char	*no_path;
	char	*so_path;
	char	*ea_path;
	char	*we_path;
	int		fl_color[3];
	int		ce_color[3];
}	t_asset;

#endif