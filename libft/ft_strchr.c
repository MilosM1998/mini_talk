/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:40:07 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/21 11:40:13 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	int				i;

	i = 0;
	uc = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == uc)
			return ((char *)&s[i]);
		i++;
	}
	if (uc == '\0')
		return ((char *)&s[i]);
	return (0);
}
/*#include <stdio.h>
#include <bsd/string.h>

int main()
{
	char *str;
	char *ptr;
	char *ptr2;
	char *str2 = "testingsd";
	str = "testingsd";
	ptr = ft_strchr(str, '\0');
	ptr2 = strchr(str2, '\0');
	printf("org: %p\nMy:%p\n", ptr, ptr2);
}*/
