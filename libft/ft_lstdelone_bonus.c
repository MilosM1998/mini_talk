/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:35:22 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/23 20:06:25 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/* void	delete_node(void *content)
{
	free(content);
}
#include <stdio.h>

int	main(void)
{
	t_list	*test;

	test = ft_lstnew(malloc(sizeof(char) * 6));
	ft_memcpy(test->content, "Hello", 6);
	printf("before: %s\n", (char *)test->content);
	ft_lstdelone(test, delete_node);
	test = NULL;
	if (!test)
		printf("Succesfully deleted memory.\n");
	else
		printf("lstdelone functions doesn't work.\n");
}
 */