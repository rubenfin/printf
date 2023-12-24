/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 12:01:31 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/11/09 12:01:33 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num)
{
	int	i;

	i = 0;
	if (num == -2147483648)
	{
		i += ft_putchar('-');
		i += ft_putchar('2');
		num = 147483648;
	}
	if (num < 0)
	{
		num = -num;
		i += ft_putchar('-');
	}
	if (num > 9)
	{
		i += ft_putnbr(num / 10);
		i += ft_putnbr(num % 10);
	}
	if (num <= 9)
	{
		i += ft_putchar(num + '0');
	}
	return (i);
}
