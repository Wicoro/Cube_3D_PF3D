/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:16:35 by norban            #+#    #+#             */
/*   Updated: 2025/01/10 10:46:44 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned long	i;
	char			*s_copy;

	i = ft_strlen(s);
	s_copy = (char *)s;
	while (s[i] != (char)c && i != 0)
		i--;
	if (s[i] == (char)c)
		return (s_copy + i);
	return (NULL);
}
