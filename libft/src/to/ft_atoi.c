/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:07:25 by norban            #+#    #+#             */
/*   Updated: 2025/04/23 16:45:55 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lltoobig(int mult)
{
	if (mult == -1)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			mult;
	long long	nb;

	nb = 0;
	mult = 1;
	i = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nb * 10 < 0)
			return (ft_lltoobig(mult));
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	nb *= mult;
	return (nb);
}
