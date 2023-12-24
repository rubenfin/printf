/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_p.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 11:36:27 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/11/16 15:29:46 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	arg_p(va_list args)
{
	void	*ptr;
	int		char_counter;
	int		result;

	char_counter = 0;
	ptr = va_arg(args, void *);
	if (!ptr)
		return (write(1, "(nil)", 5));
	else
	{
		result = ft_putstr("0x");
		if (result == -1)
			return (-1);
		char_counter += result;
		result = ft_putnbr_base((unsigned long long)ptr, "0123456789abcdef");
		if (result == -1)
			return (-1);
		char_counter += result;
	}
	return (char_counter);
}
