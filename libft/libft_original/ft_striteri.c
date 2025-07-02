/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:49:08 by stdevis           #+#    #+#             */
/*   Updated: 2025/03/28 17:40:40 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/*void f(unsigned i, char *c)
{
	unsigned int	i;
	int				i;

	if (i % 2 == 0)
		if (*c >= 'a' && *c <= 'z')
			*c -= 32;
}*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*int main()
{
	char s[] = "yo la team des vrai beau gosse";
	ft_striteri(s, f);
	printf("%s\n", s);
}*/