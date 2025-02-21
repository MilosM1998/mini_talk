/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:13:32 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/02 14:17:27 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
/*#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
int main()
{
	char str[] = "TESTING";
	int i; 
	i = 0;
	while(str[i] != '\0')
	{
		ft_putchar(ft_tolower(str[i]));
		i++;
	}
}*/
