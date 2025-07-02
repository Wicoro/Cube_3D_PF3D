/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shokahn <shokahn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:05:30 by stdevis           #+#    #+#             */
/*   Updated: 2025/05/29 15:02:08 by shokahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_strlcat(char *dst, const char *src, unsigned int dstsize)
{
	unsigned int	i;
	unsigned int	dst_len;
	unsigned int	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize == 0 || dstsize <= dst_len)
		return (dstsize + src_len);
	while (src[i] && i < dstsize - dst_len - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*int	main(void)
{
	char	dest[50] = "123456";
	char	src[] = "abcdefghi";
	char	dest1[50] = "123456";
	char	src1[] = "abcdefghi";

	printf("%zu \n", ft_strlcat(dest, src, 9));
	printf("%s\n", dest);
	printf("%lu \n", strlcat(dest1, src1, 9));
	printf("%s\n", dest1);
}*/