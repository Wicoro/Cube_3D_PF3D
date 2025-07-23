/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:30:59 by norban            #+#    #+#             */
/*   Updated: 2025/07/23 21:54:58 by norban           ###   ########.fr       */
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

static int	rgb_assets_process(char **rgb, int *asset_id)
{
	int		i;
	char	*tmp;

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
	return (0);
}

int	get_rgb_assets(t_assets *assets, char *line)
{
	char	**rgb;
	int		*asset_id;
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
		return (asset_id[0] = -1, ft_free_tab(&rgb),
			ft_free_str(&trim_start), 1);
	if (rgb_assets_process(rgb, asset_id) == 1)
		return (0);
	ft_free_tab(&rgb);
	ft_free_str(&trim_start);
	return (0);
}
