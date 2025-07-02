/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:42:15 by stdevis           #+#    #+#             */
/*   Updated: 2025/03/28 17:38:37 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_format(va_list args, char conv, int *count)
{
	if (conv == 'c')
		ft_printf_char(va_arg(args, int), count);
	else if (conv == 's')
		ft_printf_string(va_arg(args, char *), count);
	else if (conv == 'p')
		ft_printf_pointer(va_arg(args, void *), count);
	else if (conv == 'd' || (conv == 'i'))
		ft_printf_integer(va_arg(args, int), count);
	else if (conv == 'u')
		ft_printf_unsigned(va_arg(args, unsigned int), count);
	else if (conv == 'x')
		ft_printf_hexa(va_arg(args, unsigned int), count);
	else if (conv == 'X')
		ft_printf_hexup(va_arg(args, unsigned int), count);
	else if (conv == '%')
		ft_printf_char('%', count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!str)
		return (0);
	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_format(args, str[i], &count);
		}
		else
			ft_printf_char(str[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
