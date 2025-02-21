/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:39:27 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/23 20:09:36 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
/* #include <stdio.h>
int	main(void)
{
	t_list *lst;
	int size;

t_list	*ft_lstnew
	lst = ft_lstnew("Hello");
	lst->next = ft_lstnew("World!");
	size = ft_lstsize(lst);
	printf("%d", size);
} */