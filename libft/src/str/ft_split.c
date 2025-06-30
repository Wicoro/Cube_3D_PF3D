/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:06:09 by norban            #+#    #+#             */
/*   Updated: 2025/01/10 10:46:09 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strctrim(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == c)
		i++;
	return (str + i);
}

static int	ft_get_strc(const char *str, char c)
{
	int	i;
	int	strc;

	if (ft_strlen(str) == 0)
		return (0);
	i = 0;
	strc = 1;
	while (str[i])
	{
		while (str[i] && str[i] != c)
			i++;
		while (str[i] && str[i] == c)
		{
			if (str[i + 1] == c && str[i + 1])
				i++;
			else
			{
				i++;
				strc++;
			}
		}
	}
	if (i > 0 && str[i - 1] == c)
		strc--;
	return (strc);
}

static void	ft_freetab(char ***tab, int strc)
{
	int	i;

	i = 0;
	while (i < strc)
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
	*tab = NULL;
}

static char	*ft_get_next_string(const char *str, char c, int j)
{
	int		len;
	char	*substr;
	int		i;

	if (!str)
		return (NULL);
	len = 0;
	while (str[j + len] != c && str[j + len])
		len++;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (str[j] != c && str[j])
		substr[i++] = str[j++];
	substr[i] = '\0';
	return (substr);
}

char	**ft_split(const char *str, char c)
{
	int		strc;
	int		i;
	int		j;
	char	**tab;

	if (!str)
		return (NULL);
	str = ft_strctrim((char *)str, c);
	strc = ft_get_strc(str, c);
	tab = malloc(sizeof(char *) * (strc + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (i < strc)
	{
		tab[i] = ft_get_next_string(str, c, j);
		if (!tab[i])
			return (ft_freetab(&tab, i), NULL);
		j += ft_strlen(tab[i++]);
		while (str[j] && str[j] == c)
			j++;
	}
	tab[i] = 0;
	return (tab);
}

// #include <stdio.h>
// #include <unistd.h>
// #include "ft_strlen.c"
// #include "ft_strchr.c"
// #include "ft_substr.c"
// #include "ft_strdup.c"
// #include "ft_bzero.c"

// int	main()
// {
// 	char *str = "hello!";
// 	char c = 32;
// 	char **tab;

// 	tab = ft_split(str, c);
// 	int i = 0;
// 	while (tab && tab[i])
// 	{
// 		printf("%s = %d\n", tab[i], i);
// 		i++;
// 	}
// 	//system("leaks a.out");
// }