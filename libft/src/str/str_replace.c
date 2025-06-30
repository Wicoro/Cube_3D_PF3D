/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 04:46:18 by norban            #+#    #+#             */
/*   Updated: 2025/02/06 06:11:31 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	get_str1_nb(char *src, char *str1)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (src[i])
	{
		if (src[i] == str1[0]
			&& ft_strncmp(&src[i], str1, ft_strlen(str1)) == 0)
			nb++;
		i++;
	}
	return (nb);
}

char	*create_new_str(char *src, char *str1, char *str2, int *nb)
{
	char	*new_str;

	*nb = get_str1_nb(src, str1);
	new_str = malloc(sizeof(char) * (ft_strlen(src)
				- (*nb * ft_strlen(str1)) + (*nb * ft_strlen(str2)) + 1));
	return (new_str);
}

void	setup_var(int *i, int *j, char **str2)
{
	*i = 0;
	*j = 0;
	if (!*str2)
		*str2 = "";
}

char	*str_replace(char *src, char *str1, char *str2)
{
	int		nb;
	char	*new_str;
	int		i;
	int		j;
	int		k;

	if (!str1 || !src)
		return (NULL);
	setup_var(&i, &j, &str2);
	new_str = create_new_str(src, str1, str2, &nb);
	while ((size_t) i <= ft_strlen(src)
		- (nb * ft_strlen(str1)) + (nb * ft_strlen(str2)))
	{
		if (ft_strncmp(&src[j], str1, ft_strlen(str1)) == 0)
		{
			k = 0;
			while ((size_t) k < ft_strlen(str2))
				new_str[i++] = str2[k++];
			j += ft_strlen(str1);
		}
		else
			new_str[i++] = src[j++];
	}
	return (free(src), new_str);
}

// int main(int ac, char **av)
// {
// 	char *line;
// 	char *line2;

// 	line = ft_strdup(av[1]);
// 	line2 = str_replace(line, av[2], av[3]);
// 	printf("%s | %s\n", av[1], line2);
// 	free(line2);
// }