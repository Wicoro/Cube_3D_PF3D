/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shokahn <shokahn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:26:25 by stdevis           #+#    #+#             */
/*   Updated: 2025/05/29 15:03:00 by shokahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	i;
	int	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

/*int	main(void)
{
	char	src1[] = "Skibidi";
	char	dest1[] = "powpow";

	char	src2[] = "Skibidi";
	char	dest2[] = "powpow";

	printf("%zu \n", ft_strlcpy(dest1, src1, 6));
	printf("%zu \n", ft_strlcpy(dest1, src1, 0));
	printf("%zu \n", ft_strlcpy(dest1, src1, 25));
	printf("%s \n", dest1);

	printf("%zu \n", strlcpy(dest2, src2, 6));
	printf("%zu \n", strlcpy(dest2, src2, 0));
	printf("%zu \n", strlcpy(dest2, src2, 25));
	printf("%s \n", dest2);
}*/