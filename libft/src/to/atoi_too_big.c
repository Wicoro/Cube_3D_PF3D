/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_too_big.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:05:37 by norban            #+#    #+#             */
/*   Updated: 2025/01/10 10:43:25 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	number_check(char *str, int sign)
{
	char	nb1[6];
	int		i;

	i = -1;
	while (i++ < 4)
		nb1[i] = str[i];
	nb1[6] = '\0';
	if (ft_atoi(nb1) > 21474
		|| (ft_atoi(nb1) <= 21474 && ft_atoi(str + 5) > 83647 && sign == 1)
		|| (ft_atoi(nb1) <= 21474 && ft_atoi(str + 5) > 83648 && sign == -1))
		return (1);
	return (0);
}

int	limitcheck(char *str, int sign)
{
	if (ft_strlen(str) < 10)
		return (0);
	if (number_check(str, sign) == 1)
		return (1);
	return (0);
}

int	atoi_too_big(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (str[0] == '-')
	{
		i++;
		sign = -1;
	}
	while (str[i] && str[i] == '0')
		i++;
	if (str[i + 1])
		str += i;
	else
		return (0);
	if (str && ft_strlen(str) > 10)
		return (1);
	return (limitcheck(str, sign));
}
