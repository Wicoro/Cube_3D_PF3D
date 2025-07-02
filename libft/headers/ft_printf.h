/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:11:50 by stdevis           #+#    #+#             */
/*   Updated: 2024/12/18 13:11:51 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_printf_char(char c, int *count);
void	ft_format(va_list args, char conv, int *count);
int		ft_printf(const char *str, ...);
void	ft_printf_string(char *str, int *count);
void	ft_printf_integer(int n, int *count);
void	ft_printf_unsigned(unsigned int n, int *count);
void	ft_printf_hexa(unsigned int n, int *count);
void	ft_printf_hexup(unsigned int n, int *count);
void	ft_printf_pointer(void *p, int *count);
void	ft_printf_hexa_long(unsigned long n, int *count);

#endif