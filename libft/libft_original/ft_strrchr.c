/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:25:38 by stdevis           #+#    #+#             */
/*   Updated: 2025/03/28 17:40:40 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*result;

	i = 0;
	result = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			result = ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		result = ((char *)s + i);
	return (result);
}

/*int	main(void)
{
	char	str1[] = "Maman est belle";
	char	str2[] = "Maman est belle";

	printf("%s\n", ft_strrchr(str1, 'l'));
	printf("%s\n", strrchr(str2, 'l'));
}*/
