/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:16:44 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/23 20:07:27 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
/* #include <stdio.h>

int	main(void)
{
	t_list	*first;
	t_list	*last;

	first = NULL;
	ft_lstadd_front(&first, ft_lstnew("Hello"));
	ft_lstadd_front(&first, ft_lstnew("World!"));
	ft_lstadd_front(&first, ft_lstnew("This is a test"));
	last = ft_lstlast(first);
	printf("%s", (char *)last->content);
} */
