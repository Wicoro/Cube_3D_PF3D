/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:33:17 by norban            #+#    #+#             */
/*   Updated: 2025/01/10 10:45:00 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getnbsize(long n)
{
	int	size;

	size = 1;
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n / 10 > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*nb;
	int		i;
	long	l_nb;

	l_nb = n;
	i = 0;
	size = ft_getnbsize(l_nb);
	nb = malloc(sizeof(char) * (size + 1));
	if (!nb)
		return (NULL);
	if (l_nb < 0)
	{
		nb[0] = '-';
		l_nb = -(l_nb);
	}
	while (l_nb / 10 > 0)
	{
		nb[i + size - 1] = l_nb % 10 + '0';
		i--;
		l_nb /= 10;
	}
	nb[i + size - 1] = l_nb % 10 + '0';
	nb[size] = '\0';
	return (nb);
}

// #include <stdio.h>

// int main(){
// 	printf("%s\n", ft_itoa(10000));
// }