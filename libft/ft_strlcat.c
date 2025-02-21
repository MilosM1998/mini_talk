/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:44:03 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/21 11:44:05 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	dst_len = 0;
	if (size == 0)
		return (src_len);
	while (dst[dst_len] != '\0' && dst_len < size)
		dst_len++;
	if (dst_len == size)
		return (dst_len + src_len);
	while (src[i] != '\0' && dst_len + i + 1 < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;
	size_t	r1;
	size_t	r2;

	s1 = NULL;
	s2 = NULL;
	r1 = strlcat(s1, "Hello World!", 0);
	r2 = ft_strlcat(s2, "Hello World!", 0);
	printf("%zu: org\n", r1);
	printf("%zu: MY", r2);
}*/
