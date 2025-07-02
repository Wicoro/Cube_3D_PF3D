/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:04:49 by stdevis           #+#    #+#             */
/*   Updated: 2025/05/30 16:54:05 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_memcmp(const void *s1, const void *s2, int n)
{
	int				i;
	unsigned char	*s1_temp;
	unsigned char	*s2_temp;

	s1_temp = (unsigned char *)s1;
	s2_temp = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s1_temp[i] == s2_temp[i] && i < n - 1)
		i++;
	return (s1_temp[i] - s2_temp[i]);
}

/*int	main(void)
{
	char s1[] = "teste";
	char s2[] = "teste";
	int n = 0;
	printf("%d \n", ft_memcmp(s1, s2, n));
	printf("%d \n", memcmp(s1, s2, n));
}*/
