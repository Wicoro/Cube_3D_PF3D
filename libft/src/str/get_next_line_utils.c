/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:15:40 by norban            #+#    #+#             */
/*   Updated: 2025/01/10 10:47:02 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	gnl_strnjoin(char **dest, char **str, int str_size)
{
	char	*n_line;
	int		i;
	int		j;
	int		k;

	n_line = malloc(ft_strlen(*dest) + str_size + 1);
	if (!n_line)
		return (0);
	i = 0;
	k = 0;
	while (i < (int)ft_strlen(*dest))
		n_line[k++] = (*dest)[i++];
	j = 0;
	while (j < str_size && (*str)[j])
		n_line[i++] = (*str)[j++];
	n_line[i] = '\0';
	free(*dest);
	*dest = n_line;
	return (1);
}

char	*gnl_strdup(char *str)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	gnl_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
