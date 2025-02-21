/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:41:27 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/23 20:10:52 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
/* void    delete_node(void *content)
{
	free(content);
}
#include <stdio.h>

int	main(void)
{
	t_list	*test;
	t_list	*temp;

	test = NULL;
	ft_lstadd_front(&test, ft_lstnew(ft_strdup("Hello World!")));
	ft_lstadd_back(&test, ft_lstnew(ft_strdup("This is!")));
	ft_lstadd_back(&test, ft_lstnew(ft_strdup("a test")));
	temp = test;
	while(temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	ft_lstclear(&test, delete_node);
	if(!test)
		printf("%s\n", "memory cleared");
}
 */