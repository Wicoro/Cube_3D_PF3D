/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:33:24 by norban            #+#    #+#             */
/*   Updated: 2025/01/10 10:46:02 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(long n, int fd)
{
	char	c;

	if (n > 9)
	{
		c = (n % 10) + '0';
		ft_putnbr(n / 10, fd);
		write(fd, &c, 1);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	l;

	l = n;
	if (l < 0)
	{
		write(fd, "-", 1);
		l = -l;
	}
	ft_putnbr(l, fd);
}

// #include <fcntl.h>
// #include "ft_strlen.c"
// #include "ft_itoa.c"
// #include "ft_putstr_fd.c"

// int	main(int ac, char **av)
// {
// 	ac = 0;
// 	int f = open(av[1], O_WRONLY);
// 	ft_putnbr_fd(42, f);
// }
