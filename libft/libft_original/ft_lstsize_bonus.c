/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdevis <stdevis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:45:55 by stdevis           #+#    #+#             */
/*   Updated: 2025/03/28 17:40:40 by stdevis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

/*int	main(void)
{
	t_list *content = ft_lstnew("1");
	content->next = ft_lstnew("2");
	content->next->next = ft_lstnew("3");
	printf("%d\n", ft_lstsize(content));
}*/
