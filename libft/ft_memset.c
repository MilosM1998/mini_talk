/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:58:32 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/05 21:17:58 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char )c;
		i++;
	}
	return (s);
}
/*#include <string.h>

int main ()
{
   char str[40];

   strcpy(str, "Testing this shit");
   puts(str);
   ft_memset(str, 97, 7);
   puts(str);

   return(0);
}*/
