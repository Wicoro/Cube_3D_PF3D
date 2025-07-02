/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shokahn <shokahn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:24:21 by stdevis           #+#    #+#             */
/*   Updated: 2025/05/29 15:01:29 by shokahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	ft_bzero(void *s, int n)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)s;
	while (n > 0)
	{
		temp[i] = 0;
		n--;
		i++;
	}
}

/*int	main(void)
{
	char str[] = "Hello everybody";
	char str1[] = "Hello everybody";
	bzero(str, 17);
	ft_bzero(str1, 17);
}*/