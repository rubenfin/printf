/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/02 12:39:13 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/11/17 10:38:48 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, sizeof(char)));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (write(1, str, i) == -1)
		return (-1);
	return (i);
}
