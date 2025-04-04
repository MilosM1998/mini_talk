/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:12:30 by mmilicev          #+#    #+#             */
/*   Updated: 2024/11/19 23:02:36 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

static int	ft_putptr(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_putptr(n / 16);
		count += ft_putptr(n % 16);
	}
	else
	{
		if (n <= 9)
			count += ft_putchar(n + '0');
		else
			count += ft_putchar(n - 10 + 'a');
	}
	return (count);
}

int	ft_printp(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (count += ft_printstr("(nil)"));
	else
	{
		count += ft_printstr("0x");
		count += ft_putptr(ptr);
	}
	return (count);
}
