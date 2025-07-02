/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:20:02 by stdevis           #+#    #+#             */
/*   Updated: 2025/05/28 17:15:30 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	ft_is_separator(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_wcount(char const *s, char *sep)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (s[i])
	{
		while (s[i] && ft_is_separator(s[i], sep))
			i++;
		if (s[i] && !ft_is_separator(s[i], sep))
		{
			count++;
			while (s[i] && !ft_is_separator(s[i], sep))
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

static char	**ft_makesplit(char **split, const char *s, char *sep)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && ft_is_separator(s[i], sep))
			i++;
		start = i;
		while (s[i] && !ft_is_separator(s[i], sep))
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

char	**ft_msplit(char const *s, char *sep)
{
	char	**split;
	char	**result;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * ft_wcount(s, sep));
	if (!split)
		return (NULL);
	result = ft_makesplit(split, s, sep);
	if (!result)
		return (NULL);
	return (split);
}
