/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:56:46 by mmilicev          #+#    #+#             */
/*   Updated: 2024/11/19 23:05:36 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

int	format_checker(const char format, va_list ap)
{
	int	count;

	count = 0;
	if (format == 'd' || format == 'i')
		count += ft_print_nbr(va_arg(ap, int));
	else if (format == 's')
		count += ft_printstr(va_arg(ap, char *));
	else if (format == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (format == 'p')
		count += ft_printp(va_arg(ap, unsigned long));
	else if (format == 'x' || format == 'X')
		count += ft_printhex(va_arg(ap, unsigned int), format);
	else if (format == 'u')
		count += ft_print_uint(va_arg(ap, unsigned int));
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printed;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	printed = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX%", *format))
				printed += format_checker(*format++, ap);
			else
				return (-1);
		}
		else
			printed += ft_putchar(*format++);
	}
	va_end(ap);
	return (printed);
}
