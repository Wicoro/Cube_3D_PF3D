/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shokahn <shokahn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:58:15 by stdevis           #+#    #+#             */
/*   Updated: 2025/05/29 15:01:40 by shokahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memcpy(void *dst, const void *src, int n)
{
	unsigned char	*d;
	unsigned char	*s;
	int				i;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	while (n > 0)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (dst);
}

/*int	main(void)
{
	char *src = NULL;
	char *dst = NULL;
	printf("Source -> %s\nDest --> %s\n", src, ft_memcpy(dst, src, 3));
	printf("Source -> %s\nDest --> %s\n", src, memcpy(dst, src, 3));
}*/