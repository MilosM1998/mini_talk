/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:19:44 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/02 14:13:09 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c -= 32;
	}
	return (c);
}
/*void    ft_putchar(char c)
{
    write(1, &c, 1);
}

#include <ctype.h>
#include <unistd.h>
int main()
{
	char *str; 
	str = "testing";
	int i;
	i = 0;
	while(str[i] != '\0')
	{
		ft_putchar(ft_toupper(str[i]));
	//	printf("%c", ft_toupper(str[i]));
		i++;
	}	
}*/
