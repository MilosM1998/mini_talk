/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:57:55 by mmilicev          #+#    #+#             */
/*   Updated: 2024/11/19 23:02:23 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_printstr(char *str);
int	ft_print_nbr(int n);
int	ft_printhex(unsigned int n, const char format);
int	ft_printp(unsigned long ptr);
int	ft_print_uint(unsigned int n);
int	ft_printf(const char *format, ...);
#endif
