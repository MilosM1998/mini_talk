/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:32:47 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/14 19:07:55 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}
/*#include <stdio.h>
#include <bsd/string.h>
int main()
{
	char *str;
	char *ptr;
	char *ptr2;

	str = "testing";
	ptr = ft_strrchr(str, 't');
	ptr2 = strrchr(str, 't');
	printf("org:%s\n, my:%s\n", ptr, ptr2);
}*/
