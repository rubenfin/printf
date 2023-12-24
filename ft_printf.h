/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 16:15:09 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/12/04 15:12:21 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

// main functions
int	ft_printf(const char *format, ...);

// functions
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr_base(unsigned long long num, char *base);
int	print_num(unsigned long long num, char *base, int baselength);
int	num_lower_than_0(unsigned long long num);
int	is_valid_base(char *base);
int	ft_putnbr(int num);

// arg converter
int	arg_c(va_list args);
int	arg_s(va_list args);
int	arg_d_i(va_list args);
int	arg_x_upp_x(char const format, va_list args);
int	arg_u(va_list args);
int	arg_p(va_list args);

#endif
