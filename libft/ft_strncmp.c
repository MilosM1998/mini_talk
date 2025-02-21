/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:15:34 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/07 14:52:08 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
/*#include <bsd/string.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	if(argc > 1)
	{
		int dif = ft_strncmp(argv[1], argv[2], 3);
		int dif2 = strncmp(argv[1], argv[2], 3);
		printf("org:%d\nmy:%d\n", dif, dif2);
	}
	else
		return 0;
}*/
