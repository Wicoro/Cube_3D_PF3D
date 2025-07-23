/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_assets_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:57:39 by norban            #+#    #+#             */
/*   Updated: 2025/07/23 22:09:34 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	compare_asset(char	**path, char **split, char *ref)
{
	if (ft_strncmp(split[0], ref, 3) == 0
		&& ft_strncmp(&split[1][ft_strlen(split[1]) - 4], ".xpm", 4) == 0
		&& !(*path))
		*path = ft_substr(split[1], 0, ft_strlen(split[1]));
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
	compare_asset(&assets->no_path, split, "NO");
	compare_asset(&assets->so_path, split, "SO");
	compare_asset(&assets->ea_path, split, "EA");
	compare_asset(&assets->we_path, split, "WE");
	compare_asset(&assets->do_path, split, "DO");
	return (free(trim), ft_free_tab(&split), 0);
}

int	get_assets(t_assets *assets, int fd)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line && count < 7)
	{
		if (ft_strlen(line) != 0 && !(ft_strlen(line) == 1 && line[0] == '\n'))
		{
			if (compare_assets(assets, line) == 1)
				return (free(line), 1);
			count++;
		}
		ft_free_str(&line);
		if (count < 7)
			line = get_next_line(fd);
	}
	if (count < 7)
		return (free(line), 1);
	return (free(line), 0);
}
