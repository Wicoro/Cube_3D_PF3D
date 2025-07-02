/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shokahn <shokahn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:20:12 by stdevis           #+#    #+#             */
/*   Updated: 2025/05/29 15:01:40 by shokahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memset(void *s, int c, int len)
{
	unsigned char	*temp;
	int				i;

	temp = (unsigned char *)s;
	i = 0;
	while (len > 0)
	{
		temp[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (s);
}

/*int main()
{
	char str[] = "Hello everybody";
	printf("%s\n", str);
	printf("%s\n", memset(str+5, '.', 5));
	printf("%s\n", ft_memset(str+5, '.', 5));
}*/