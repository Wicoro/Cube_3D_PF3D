/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:14:08 by stdevis           #+#    #+#             */
/*   Updated: 2025/03/28 17:40:40 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	ft_int_len(long nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		size = 1;
	if (nb < 0)
	{
		size++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

static char	*ft_makeitoa(char *result, long nb, int size)
{
	result[size] = '\0';
	size--;
	if (nb == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		result[size--] = nb % 10 + 48;
		nb /= 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*allocation;
	char	*result;
	int		size;

	size = ft_int_len(n);
	nb = n;
	allocation = malloc(sizeof(char) * size + 1);
	if (!allocation)
		return (NULL);
	result = ft_makeitoa(allocation, nb, size);
	return (result);
}

/*int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
}*/
