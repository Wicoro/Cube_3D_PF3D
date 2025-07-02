/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:51:40 by stdevis           #+#    #+#             */
/*   Updated: 2025/03/28 17:38:30 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_printf_hexa_long(unsigned long n, int *count)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n > 15)
	{
		ft_printf_hexa_long(n / 16, count);
		ft_printf_hexa_long(n % 16, count);
	}
	else
		ft_printf_char(hexa[n], count);
}

void	ft_printf_pointer(void *p, int *count)
{
	unsigned long	p_temp;

	p_temp = (unsigned long)p;
	ft_printf_string("0x", count);
	ft_printf_hexa_long(p_temp, count);
}
