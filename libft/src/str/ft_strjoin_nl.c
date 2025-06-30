/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_nl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:50:21 by norban            #+#    #+#             */
/*   Updated: 2025/04/30 19:37:07 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
// #include "ft_strlcpy.c"
// #include "ft_strlcat.c"
// #include "ft_strlen.c"

char	*ft_strjoin_nl(const char *s1, const char *s2)
{
	char	*str;
	int		size;

	size = ft_strlen(s1) + ft_strlen(s2) + 2;
	str = malloc(sizeof(char) * (size));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, size);
	ft_strlcat(str, "\n", size);
	ft_strlcat(str, s2, size);
	return (str);
}

// int main()
// {
// 	char * s1 = "alpha";
// 	char * s2 = "alpha";
// 	printf("%s", ft_strjoin(s1, s2));
// }