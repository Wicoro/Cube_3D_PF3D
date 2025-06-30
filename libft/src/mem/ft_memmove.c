/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:39:25 by norban            #+#    #+#             */
/*   Updated: 2025/01/10 10:45:42 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isoverlap(void *dst, const void *src)
{
	if (dst > src)
		return (1);
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	i;

	if (!dst && !src)
		return (NULL);
	if (ft_isoverlap(dst, src) == 1)
	{
		i = len - 1;
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
