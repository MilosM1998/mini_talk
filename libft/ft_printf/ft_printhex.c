/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 00:25:37 by mmilicev          #+#    #+#             */
/*   Updated: 2024/11/19 23:02:30 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

static int	ft_puthex(unsigned int n, const char format)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_puthex(n / 16, format);
		count += ft_puthex(n % 16, format);
	}
	else if (n <= 9)
		count += ft_putchar((n + '0'));
	else
	{
		if (format == 'x')
			count += ft_putchar((n - 10) + 'a');
		else if (format == 'X')
			count += ft_putchar((n - 10) + 'A');
	}
	return (count);
}

int	ft_printhex(unsigned int n, const char format)
{
	if (n == 0)
		return (ft_putchar('0'));
	return (ft_puthex(n, format));
}
