/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:41:08 by stdevis           #+#    #+#             */
/*   Updated: 2025/03/28 17:40:40 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A'
			&& c <= 'Z'))
		return (1);
	else
		return (0);
}

/*int	main()
{
	printf("%d\n%d\n%d\n%d\n\n\n", ft_isalnum('T'), ft_isalnum('8'),
	ft_isalnum('\0'), ft_isalnum('a'));
	printf("%d\n%d\n%d\n%d\n", isalnum('T'), isalnum('8'),
	isalnum('\0'), isalnum('a'));
}*/