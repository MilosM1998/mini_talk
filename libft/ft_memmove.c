/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:43:03 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/24 19:25:57 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*temp;
	const unsigned char	*source;

	temp = (unsigned char *)dest;
	source = (const unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	if (source < temp)
	{
		while (n-- > 0)
			temp[n] = source[n];
	}
	else
	{
		while (i < n)
		{
			temp[i] = source[i];
			i++;
		}
	}
	return (dest);
}
/*#include <stdio.h>
int main ()
{
  char str[20] = "test this thing";
  ft_memmove( str+5, str, 15 );
  puts( str );
  return (0);
}*/
