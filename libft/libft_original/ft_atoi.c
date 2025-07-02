/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:43:41 by stdevis           #+#    #+#             */
/*   Updated: 2025/03/28 17:40:40 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

long	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (sign * result);
}
/*int main()
{
	printf("%d \n", ft_atoi(" 			-1234ab567"));
	printf("%d \n", ft_atoi(" 			-a34ab567"));
	printf("%d \n", ft_atoi("+1234ab567"));

	printf("%d \n", atoi(" 			-1234ab567"));
	printf("%d \n", atoi(" 			-a34ab567"));
	printf("%d \n", atoi("+1234ab567"));
}*/