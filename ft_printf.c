/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuciftci <nuciftci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:13:20 by nuciftci          #+#    #+#             */
/*   Updated: 2024/11/29 14:38:12 by nuciftci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check2(char c, va_list arg)
{
	int				p;
	unsigned long	ptr;

	(void)c;
	ptr = va_arg(arg, unsigned long);
	p = 0;
	if (ptr == (unsigned long) NULL)
		p += ft_putstr("(nil)");
	else
	{
		p += ft_putstr("0x");
		p += ft_pointer(ptr);
	}
	return (p);
}

int	ft_check(char c, va_list arg)
{
	int	p;

	p = 0;
	if (c == 'c')
		p += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		p += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		p += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		p += ft_u(va_arg(arg, unsigned int));
	else if (c == 'x')
		p += ft_hex(va_arg(arg, unsigned int), 0);
	else if (c == 'X')
		p += ft_hex(va_arg(arg, unsigned int), 1);
	else if (c == 'p')
	{
		p += ft_check2(c, arg);
	}
	else if (c == '%')
		p += ft_putchar('%');
	else
		return (ft_putchar(c));
	return (p);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		check;

	va_start(arg, str);
	i = 0;
	check = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			check++;
		}
		if (str[i] == '%')
		{
			i++;
			while (str[i] == ' ' && str[i])
				i++;
			check += ft_check(str[i], arg);
		}
		i++;
	}
	va_end(arg);
	return (check);
}
