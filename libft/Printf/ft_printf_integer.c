/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:32:55 by stdevis           #+#    #+#             */
/*   Updated: 2025/03/28 17:38:28 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_printf_integer(int n, int *count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
		return ;
	}
	if (n < 0)
	{
		ft_printf_char('-', count);
		n *= -1;
	}
	if (n > 9)
	{
		ft_printf_integer(n / 10, count);
		ft_printf_integer(n % 10, count);
	}
	else
		ft_printf_char(n + 48, count);
}
