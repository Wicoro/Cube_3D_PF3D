/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:26:10 by norban            #+#    #+#             */
/*   Updated: 2025/01/10 10:45:58 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

//  #include <fcntl.h>
// /*#include "ft_strlen.c"
// #include "ft_putstr_fd"
// #include "ft_strjoin.c" */

// int	main(int ac, char **av)
// {
// 	ac = 0;
// 	int f = open(av[1], O_WRONLY);
// 	ft_putendl_fd(av[2], f);
// }