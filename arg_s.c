/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_s.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 11:23:46 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/11/16 11:26:51 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	arg_s(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (write(1, "(null)", 6));
	return (ft_putstr(str));
}
