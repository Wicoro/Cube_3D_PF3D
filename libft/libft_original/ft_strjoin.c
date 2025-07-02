/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:57:41 by stdevis           #+#    #+#             */
/*   Updated: 2025/05/30 16:54:21 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		total_len;
	char	*str_join;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	str_join = malloc(sizeof(char) * (total_len + 1));
	if (!str_join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str_join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str_join[i + j] = s2[j];
		j++;
	}
	str_join[i + j] = '\0';
	return (str_join);
}

/*int main()
{
	char	*str1 = "Hello je t'aime bcp";
	char	*str2 = ", j'ai menti je te déteste!";

	printf("s1 = %s\ns2 = %s\n%s\n", str1, str2, ft_strjoin(str1, str2));
	//printf("%d\n", strjoin(str1, str2));
}*/