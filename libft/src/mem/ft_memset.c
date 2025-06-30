/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:42:15 by norban            #+#    #+#             */
/*   Updated: 2025/01/10 10:45:45 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	i;

	i = 0;
	while (i < len)
		((unsigned char *)b)[i++] = (unsigned char)c;
	return (b);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	int a[5];
// 	int b[5];
// 	ft_memset(a, '0', 3);
// 	memset(b, '0', 3);
// 	printf("%d\n", a[0]);
// 	printf("%d\n", b[0]);
// }