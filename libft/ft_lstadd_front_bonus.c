/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:36:59 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/23 20:05:37 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/* #include <stdio.h>
int	main(void)
{

	t_list *first = NULL;
	t_list *current;

	ft_lstadd_front_bonus(&first, ft_lstnew("Hello"));
	ft_lstadd_front_bonus(&first, ft_lstnew("World"));
	ft_lstadd_front_bonus(&first, ft_lstnew("First"));
	current = first;
	while(current)
	{
		printf("%s -> ", (char *)current->content);
		current = current->next;
	}
} */
