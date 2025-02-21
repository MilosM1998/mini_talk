/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:58:57 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/05 19:05:55 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	const char	*b;
	const char	*l;

	b = (const char *)big;
	l = (const char *)little;
	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (b[i] && i < len)
	{
		if (b[i] == l[0])
		{
			j = 0;
			while (l[j] != '\0' && (i + j) < len && b[i + j] == l[j])
				j++;
			if (l[j] == '\0')
				return ((char *)&b[i]);
		}
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>
int main()
{
    const char  *big = "123456789EFABCDEF";
    const char  *little = "CD";
    size_t  len = 15;
    char    *t;

    t = ft_strnstr(big, little, len);
    printf("Resutl: %s\n", t);
    return 0;
}*/
