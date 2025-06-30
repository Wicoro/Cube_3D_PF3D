/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:42:44 by norban            #+#    #+#             */
/*   Updated: 2025/01/10 10:46:41 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isstrvalid(const char *src, const char *str, int i)
{
	int	j;

	j = 0;
	while (src[i] && str[j] && src[i] == str[j])
	{
		i++;
		j++;
	}
	if (!str[j])
		return (1);
	return (0);
}

char	*ft_strnstr(const char *src, const char *str, size_t len)
{
	unsigned long	i;

	i = 0;
	if (!str[0])
		return ((char *)src);
	if (!src[0] || ft_strlen(src) < ft_strlen(str))
		return (NULL);
	while (i < len)
	{
		if (src[i] == str[0] && ft_isstrvalid(src, str, i) == 1
			&& len - i >= (unsigned long)ft_strlen(str))
			return ((char *)src + i);
		i++;
	}
	return (NULL);
}
