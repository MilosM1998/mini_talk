/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:42:11 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/21 11:42:15 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	n_check(int *len, int *n, int *negative)
{
	int	temp;

	*len = 0;
	*negative = 0;
	if (*n == 0)
		*len = 1;
	else if (*n < 0)
	{
		*negative = 1;
		*n = -(*n);
	}
	temp = *n;
	while (temp > 0)
	{
		temp /= 10;
		(*len)++;
	}
}

static char	*new_str(char *str, int len, int negative, int n)
{
	while (len > 0)
	{
		str[len - 1 + negative] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	int		negative;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_check(&len, &n, &negative);
	str = (char *)malloc(sizeof(char) * (len + negative + 1));
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str[len + negative] = '\0';
	str = new_str(str, len, negative, n);
	return (str);
}
/*#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int n = INT_MAX;
	char *s;
	s = ft_itoa(n);
	printf("%s\n", s);
	free(s);
}*/
