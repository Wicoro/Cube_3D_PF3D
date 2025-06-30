/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:35:32 by norban            #+#    #+#             */
/*   Updated: 2025/04/28 17:34:44 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strtrimlen(const char *str)
{
	char	*str_trim;
	int		len;

	str_trim = ft_strtrim(str, " \t\n\v\f\r");
	len = ft_strlen(str_trim);
	return (free(str_trim), len);
}
