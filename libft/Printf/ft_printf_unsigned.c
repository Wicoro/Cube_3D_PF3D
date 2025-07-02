/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:28:51 by stdevis           #+#    #+#             */
/*   Updated: 2025/03/28 17:38:35 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_printf_unsigned(unsigned int n, int *count)
{
	if (n > 9)
	{
		ft_printf_unsigned(n / 10, count);
		ft_printf_unsigned(n % 10, count);
	}
	else
		ft_printf_char(n + 48, count);
}
