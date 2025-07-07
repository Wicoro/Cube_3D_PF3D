/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:57:39 by norban            #+#    #+#             */
/*   Updated: 2025/06/30 18:00:30 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3d.h"

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
		return (free_split(rgb), print_error(ARG_ERROR), 1);
	i = 0;
	while (i < 3)
	{
		asset_id[i] = ft_atoi(rgb[i]);
		if (asset_id[i] < 0 || asset_id[i] > 255)
			asset_id[i] = 0;
		i++;
	}
	free_split(rgb);
	return (0);
}

static int	compare_assets(t_assets *assets, char **split)
{
	if (ft_strncmp(split[0], "NO", 3) == 0)
		assets->no_path = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "SO", 3) == 0)
		assets->so_path = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "EA", 3) == 0)
		assets->ea_path = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "WE", 3) == 0)
		assets->we_path = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "F", 2) == 0
		|| ft_strncmp(split[0], "C", 2) == 0)
	{
		if (get_rgb_assets(assets, split[1], split[0][0]) == 1)
			return (1);
	}
	return (0);
}

/*
We go to search for the 6 lines ignoring the empty lines
We then check if it ended because we got all 6 lines or because the file ended
*/
int	get_assets(t_assets *assets, int fd)
{
	char	*line;
	char	**split;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line && count < 6)
	{
		if (ft_strlen(line) != 0 && !(ft_strlen(line) == 1 && line[0] == '\n'))
		{
			split = ft_split(line, ' ');
			if (!split)
				return (free(line), print_error(MALLOC_ERROR), 1);
			else if (compare_assets(assets, split) == 1)
				return (free_split(split), free(line), 1);
			free_split(split);
			count++;
		}
		free_char(&line);
		if (count < 6)
			line = get_next_line(fd);
	}
	if (count < 6)
		return (free(line), print_error(ARG_ERROR), 1);
	return (free(line), 0);
}
