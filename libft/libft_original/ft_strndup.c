/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:10:04 by stdevis           #+#    #+#             */
/*   Updated: 2025/05/30 16:54:27 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strndup(const char *s1, int n)
{
	char	*dup;
	int		i;
	int		len;

	len = 0;
	while (s1[len] && len < n)
		len++;
	i = 0;
	dup = malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}
