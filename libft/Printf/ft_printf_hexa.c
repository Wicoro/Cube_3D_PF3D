/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:08:45 by stdevis           #+#    #+#             */
/*   Updated: 2025/03/28 17:38:22 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_printf_hexa(unsigned int n, int *count)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n > 15)
	{
		ft_printf_hexa(n / 16, count);
		ft_printf_hexa(n % 16, count);
	}
	else
		ft_printf_char(hexa[n], count);
}
