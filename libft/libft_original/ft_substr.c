/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:59:35 by stdevis           #+#    #+#             */
/*   Updated: 2025/05/30 16:55:12 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_substr(const char *s, unsigned int start, int len)
{
	int				i;
	unsigned int	str_len;
	char			*substr;

	if (!s)
		return (NULL);
	i = 0;
	str_len = ft_strlen(s);
	if (start > str_len)
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

/*int main()
{
	char str[] = "";

	printf("%s\n", ft_substr(str, 7, 24));
	//printf("%d\n", substr(str, 8, 24));
}*/