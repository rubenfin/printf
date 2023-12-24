/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_x_X.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 11:30:44 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/11/16 11:34:53 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	arg_x_upp_x(char const format, va_list args)
{
	if (format == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	return (0);
}
