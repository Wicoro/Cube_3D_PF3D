/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:46:11 by stdevis           #+#    #+#             */
/*   Updated: 2025/05/30 16:53:34 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	ft_free_tab(char ***tab)
{
	int	i;

	if (!tab || !*tab)
		return ;
	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
	*tab = NULL;
}

void	ft_free_array(int ***array, int len)
{
	int	i;

	if (!array || !*array)
		return ;
	i = 0;
	while (i < len)
	{
		free((*array)[i]);
		i++;
	}
	free(*array);
	*array = NULL;
}

void	ft_free_index(char ***split, int j)
{
	int	i;

	i = 0;
	if (!split || !*split)
		return ;
	while (i < j)
	{
		free((*split)[i]);
		i++;
	}
	free(*split);
	*split = NULL;
}

void	ft_free_str(char **str)
{
	if (!str | !*str)
		return ;
	free(*str);
	*str = NULL;
}

void	ft_free_int(int **ptr)
{
	if (!ptr || !*ptr)
		return ;
	free(*ptr);
	*ptr = NULL;
}
