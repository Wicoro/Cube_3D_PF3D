/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:22:04 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/02 13:22:29 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

long	check_range(const char *str, long sign, unsigned long result, int i)
{
	unsigned long	limit;
	long			size;

	size = 0;
	if (sign == -1)
		limit = (unsigned long)LONG_MAX + 1;
	else
		limit = (unsigned long)LONG_MAX;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		size++;
		i++;
	}
	if (result > limit || size > 19)
		return (-1);
	return (sign * result);
}

long	ft_atol(const char *str)
{
	unsigned long	result;
	long			sign;
	int				i;

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
	while (str[i] == '0')
		i++;
	return (check_range(str, sign, result, i));
}
