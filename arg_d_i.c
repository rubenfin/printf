/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_d_i.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 11:27:49 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/11/16 11:29:53 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	arg_d_i(va_list args)
{
	return (ft_putnbr(va_arg(args, int)));
}
