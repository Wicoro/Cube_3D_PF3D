/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:13:13 by stdevis           #+#    #+#             */
/*   Updated: 2025/05/30 16:54:11 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memmove(void *dst, const void *src, int len)
{
	unsigned char	*d;
	unsigned char	*s;
	int				i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else if (s > d)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

/*int	main(void)
{
	char	str[] = "Start stop";
	char	str1[] = "Start stop";

	printf("%s\n", str);
	memmove(str + 3, str, 4);
	printf("%s\n", str);
	printf("%s\n", str1);
	ft_memmove(str1 + 3, str1, 4);
	printf("%s\n", str1);
}*/
