/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:57:39 by norban            #+#    #+#             */
/*   Updated: 2025/07/22 13:16:46 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	get_rgb_assets(t_assets *assets, char *line, char id)
{
	char	**rgb;
	int		*asset_id;
	int		i;

	if (id == 'F')
		asset_id = assets->fl_color;
	else
		asset_id = assets->ce_color;
	rgb = ft_split(line, ',');
	if (!rgb)
		return (print_error(MALLOC_ERROR), 1);
	if (!rgb[2] || rgb[3])
		return (ft_free_tab(&rgb), print_error(ARG_ERROR), 1);
	i = 0;
	while (i < 3)
	{
		asset_id[i] = ft_atoi(rgb[i]);
		if (asset_id[i] < 0 || asset_id[i] > 255)
			asset_id[i] = 0;
		i++;
	}
	ft_free_tab(&rgb);
	return (0);
}

static int	compare_assets(t_assets *assets, char **split)
{
	if (ft_strncmp(split[0], "NO", 3) == 0)
		assets->no_path = ft_substr(split[1], 0, ft_strlen(split[1]) - 1);
	else if (ft_strncmp(split[0], "SO", 3) == 0)
		assets->so_path = ft_substr(split[1], 0, ft_strlen(split[1]) - 1);
	else if (ft_strncmp(split[0], "EA", 3) == 0)
		assets->ea_path = ft_substr(split[1], 0, ft_strlen(split[1]) - 1);
	else if (ft_strncmp(split[0], "WE", 3) == 0)
		assets->we_path = ft_substr(split[1], 0, ft_strlen(split[1]) - 1);
	else if (ft_strncmp(split[0], "DO", 3) == 0)
		assets->do_path = ft_substr(split[1], 0, ft_strlen(split[1]) - 1);
	else if (ft_strncmp(split[0], "F", 2) == 0
		|| ft_strncmp(split[0], "C", 2) == 0)
	{
		if (get_rgb_assets(assets, split[1], split[0][0]) == 1)
			return (1);
	}
	return (0);
}


int	get_assets(t_assets *assets, int fd)
{
	char	*line;
	char	**split;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line && count < 7)
	{
		if (ft_strlen(line) != 0 && !(ft_strlen(line) == 1 && line[0] == '\n'))
		{
			split = ft_split(line, ' ');
			if (!split)
				return (free(line), print_error(MALLOC_ERROR), 1);
			else if (compare_assets(assets, split) == 1)
				return (ft_free_tab(&split), free(line), 1);
			ft_free_tab(&split);
			count++;
		}
		ft_free_str(&line);
		if (count < 7)
			line = get_next_line(fd);
	}
	if (count < 7)
		return (free(line), print_error(ARG_ERROR), 1);
	return (free(line), 0);
}
