/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shokahn <shokahn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:40:28 by stdevis           #+#    #+#             */
/*   Updated: 2025/05/29 15:01:40 by shokahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_calloc(int count, int size)
{
	void	*temp;

	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, (count * size));
	return (temp);
}

/*int main ()
{
	printf ("%s\n", ft_calloc(10, 8));
	printf ("%s\n", calloc(10, 8));
}*/