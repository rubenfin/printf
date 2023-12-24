/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_u.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 11:35:35 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/11/16 15:30:49 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	arg_u(va_list args)
{
	return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789"));
}
