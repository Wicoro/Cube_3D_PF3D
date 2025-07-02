/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:33:43 by stdevis           #+#    #+#             */
/*   Updated: 2025/03/28 17:40:40 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	ft_triming(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	k = 0;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (s1[i] && ft_triming(set, s1[i]))
		i++;
	while (j > i && ft_triming(set, s1[j]))
		j--;
	str = malloc(sizeof(char) * (j - i) + 2);
	if (!str)
		return (NULL);
	while (i <= j)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}

/*int	main(void)
{
	char	s1[] = "\t   \n\n\n  \n\n\t    Hello \t  Please\n Trim me !\t\t";
	char	set[] = " \n\t";

	printf("%s\n", ft_strtrim(s1, set));
	// printf("%s\n", strtrim(s1, set));
}*/
