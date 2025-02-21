/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:33:41 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/23 20:11:59 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	alloc_checker(t_list *new_lst, void *content, void (*del)(void *))
{
	if (!content)
	{
		ft_lstclear(&new_lst, del);
		return (0);
	}
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	new_lst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		if (!alloc_checker(new_lst, new_content, del))
			return (NULL);
		new_node = ft_lstnew(new_content);
		if (!alloc_checker(new_lst, new_node, del))
		{
			del(new_content);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
/*
void	*copy_node(void *content)
{
   char	*old_str;
   char	*new;
   size_t	i;

   i = 0;
   old_str = (char *)content;
   new = malloc(sizeof(char) * ft_strlen(content) + 1);
   if (!new)
		return (NULL);
   while (old_str[i])
   {
		new[i] = old_str[i];
		i++;
   }
   new[i] = '\0';
   return (new);
}
void	del(void *content)
{
   free(content);
}
#include <stdio.h>

int	main(void)
{
   t_list *old;
   t_list *new;
   t_list *curr;

   old = NULL;
   ft_lstadd_back(&old, ft_lstnew(ft_strdup("Hello")));
   ft_lstadd_back(&old, ft_lstnew(ft_strdup("World")));
   printf("old:\n");
   curr = old;
   while (curr)
   {
		printf("%s\n", (char *)curr->content);
		curr = curr->next;
   }
   new = ft_lstmap(old, copy_node, del);
   printf("New:\n");
   curr = new;
   while (curr)
   {
		printf("%s\n", (char *)curr->content);
		curr = curr->next;
   }
   ft_lstclear(&old, del);
   ft_lstclear(&new, del);
   ft_lstclear(&curr, del);
}  */