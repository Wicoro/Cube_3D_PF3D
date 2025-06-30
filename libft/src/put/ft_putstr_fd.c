/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:22:33 by norban            #+#    #+#             */
/*   Updated: 2025/01/10 10:46:05 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, &s[0], ft_strlen(s));
}

// #include <fcntl.h>
// #include "ft_strlen.c"
// int	main(int ac, char **av)
// {
// 	ac = 0;
// 	int f = open(av[1], O_WRONLY);
// 	ft_putstr_fd(av[2], f);
// }