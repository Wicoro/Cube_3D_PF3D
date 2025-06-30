/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:16:57 by norban            #+#    #+#             */
/*   Updated: 2025/01/10 10:44:33 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		total_len;

	total_len = count * size;
	ptr = malloc(total_len);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_len);
	return (ptr);
}
// #include <limits.h>
// int main()
// {
// 	void *ptr1;
// 	void *ptr2;

// 	ptr1 = calloc(SIZE_T_MAX, 2);

// 	ptr2 = ft_calloc(SIZE_T_MAX, 2);
// }