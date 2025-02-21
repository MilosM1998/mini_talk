/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:18:04 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/02 14:34:54 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}
/*#include <stdio.h>
#include <ctype.h>
int main()
{
	char c; 
	c = ' ';
	printf("%d\n", isdigit(c));
	printf("%d", ft_isdigit(c));
}*/
