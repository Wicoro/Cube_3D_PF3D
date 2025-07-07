/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:03:27 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/07 17:00:33 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;
	int		len_s1;

	if (!s1)
		return (NULL);
	len_s1 = ft_strlen(s1);
	i = 0;
	dup = malloc(sizeof(char) * (len_s1 + 1));
	if (!dup)
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strdup_no_null(const char *s1)
{
	char	*dup;
	int		i;
	int		len_s1;

	if (!s1)
		return (NULL);
	len_s1 = ft_strlen(s1);
	i = 0;
	dup = malloc(sizeof(char) * len_s1);
	if (!dup)
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	};
	return (dup);
}

/*int	main(void)
{
	printf("%s\n", ft_strdup("ab\0cde"));
	printf("%s\n", strdup("ab\0cde"));
}*/