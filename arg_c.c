/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_c.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 11:15:58 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/11/16 11:23:28 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	arg_c(va_list args)
{
	return (ft_putchar(va_arg(args, int)));
}
