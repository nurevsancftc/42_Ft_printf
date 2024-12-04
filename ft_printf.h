/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuciftci <nuciftci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:13:30 by nuciftci          #+#    #+#             */
/*   Updated: 2024/12/01 13:57:20 by nuciftci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_putstr(char *str);
int	ft_u(unsigned int u);
int	ft_pointer(unsigned long p);
int	ft_hex(unsigned int x, int b);
int	ft_putchar(char c);
int	ft_putnbr(int nb);

#endif
