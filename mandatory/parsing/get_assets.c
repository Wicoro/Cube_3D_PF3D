/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/07/23 21:05:55 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static char	*get_rgb_id(char *line)
{
	int		i;

	i = 1;
	while (line[i] == ' ')
		i++;
	return (ft_substr(line, i, ft_strlen(line) - i));
}

static int	get_rgb_assets(t_assets *assets, char *line)
{
	char	**rgb;
	int		*asset_id;
	int		i;
	char	*tmp;
	char	*trim_start;
	
	if (line[0] == 'F')
		asset_id = assets->fl_color;
	else
		asset_id = assets->ce_color;
	trim_start = get_rgb_id(line);
	rgb = ft_split(trim_start, ',');
	if (!rgb)
		return (print_error(MALLOC_ERROR), 1);
	if (!rgb[1] || !rgb[2] || rgb[3] || rgb[2][0] == '\n'
		|| rgb[1][0] == '\n')
		return (asset_id[0] = -1, ft_free_tab(&rgb), ft_free_str(&trim_start), 1);
	i = 0;
	while (i < 3)
	{
		tmp = ft_strtrim(rgb[i], " 	\n");
		if (!tmp)
			return (asset_id[0] = -1, 0);
		asset_id[i] = ft_atoi(tmp);
		free(tmp);
		if (asset_id[i] < 0 || asset_id[i] > 255)
			asset_id[0] = -1;
		i++;
	}
	ft_free_tab(&rgb);
	ft_free_str(&trim_start);
	return (0);
}

static int	compare_assets(t_assets *assets, char *line)
{
	char	**split;
	char	*trim;
	
	trim = ft_strtrim(line, " 	\n");
	if (!trim)
		return (1);
	if (trim[0] == 'F' || trim[0] == 'C')
	{
		if (get_rgb_assets(assets, trim) == 1)
			return (free(trim), 1);
		return (free(trim), 0);
	}
	split = ft_split(trim, ' ');
	if (!split)
		return (free(trim), 1);
	if (!split[0] || !split[1])
		return (free(trim), ft_free_tab(&split), 0);	
	else if (ft_strncmp(split[0], "NO", 3) == 0
		&& ft_strncmp(&split[1][ft_strlen(split[1]) - 4], ".xpm", 4) == 0 && !assets->no_path)
		assets->no_path = ft_substr(split[1], 0, ft_strlen(split[1]));
	else if (ft_strncmp(split[0], "SO", 3) == 0
		&& ft_strncmp(&split[1][ft_strlen(split[1]) - 4], ".xpm", 4) == 0 && !assets->so_path)
		assets->so_path = ft_substr(split[1], 0, ft_strlen(split[1]));
	else if (ft_strncmp(split[0], "EA", 3) == 0
		&& ft_strncmp(&split[1][ft_strlen(split[1]) - 4], ".xpm", 4) == 0 && !assets->ea_path)
		assets->ea_path = ft_substr(split[1], 0, ft_strlen(split[1]));
	else if (ft_strncmp(split[0], "WE", 3) == 0
		&& ft_strncmp(&split[1][ft_strlen(split[1]) - 4], ".xpm", 4) == 0 && !assets->we_path)
		assets->we_path = ft_substr(split[1], 0, ft_strlen(split[1]));
	return (free(trim), ft_free_tab(&split), 0);
}

int	get_assets(t_assets *assets, int fd)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line && count < 6)
	{
		if (ft_strlen(line) != 0 && !(ft_strlen(line) == 1 && line[0] == '\n'))
		{
			if (compare_assets(assets, line) == 1)
				return (free(line), 1);
			count++;
		}
		ft_free_str(&line);
		if (count < 6)
			line = get_next_line(fd);
	}
	if (count < 6)
		return (free(line), 1);
	return (free(line), 0);
}
