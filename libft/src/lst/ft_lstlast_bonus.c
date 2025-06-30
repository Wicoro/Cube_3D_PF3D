/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:10:30 by norban            #+#    #+#             */
/*   Updated: 2025/01/10 10:45:18 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// #include "ft_lstnew_bonus.c"
// #include <stdio.h>

// int	main()
// {
// 	t_list *node = ft_lstnew("hier");
// 	t_list *node2 = ft_lstnew("ajd");
// 	node->next = node2;
// 	printf("%s\n", ft_lstlast(node)->content);
// }