/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:07:35 by stdevis           #+#    #+#             */
/*   Updated: 2025/05/28 17:15:14 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	ft_wcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_wcreate(int start, int end, const char *str)
{
	char	*word;
	int		j;

	j = 0;
	word = malloc(sizeof(char) * ((end - start) + 1));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[j] = str[start];
		start++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_makesplit(char **split, const char *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start < i)
		{
			split[j] = ft_wcreate(start, i, s);
			if (!split[j++])
			{
				ft_free_index(&split, j - 1);
				return (NULL);
			}
		}
		split[j] = NULL;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	**result;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * ft_wcount(s, c));
	if (!split)
		return (NULL);
	result = ft_makesplit(split, s, c);
	if (!result)
		return (NULL);
	return (split);
}

/*int	main(void)
{
	int i;
	char **split;
	char *str = "      split       this for   me  !       ";
	char c = ' ';

	i = 0;
	split = ft_split(str, c);
	while (split[i])
	{
		printf("%s \n", split[i]);
		free(split[i]);
		i++;
	}
	free(split);
}*/
