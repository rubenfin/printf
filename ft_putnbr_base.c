/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/02 14:06:30 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/11/16 15:13:24 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_valid_base(char *base)
{
	char	*current;

	if (*base == '\0' || *(base + 1) == '\0')
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-' || (*base >= 9 && *base <= 13)
			|| *base == ' ')
			return (0);
		current = base + 1;
		while (*current)
		{
			if (*base == *current)
				return (0);
			current++;
		}
		base++;
	}
	return (1);
}

int	num_lower_than_0(unsigned long long num)
{
	int	char_counter;

	char_counter = 0;
	if (num == 0)
	{
		char_counter += write(1, "0", 1);
		if (char_counter == -1)
			return (-1);
	}
	if (num < 0)
	{
		char_counter += write(1, "-", 1);
		if (char_counter == -1)
			return (-1);
		num = -num;
	}
	return (char_counter);
}

int	print_num(unsigned long long num, char *base, int baselength)
{
	int	digits[64];
	int	char_counter;
	int	i;

	char_counter = 0;
	i = 0;
	if (num <= 0)
	{
		char_counter += num_lower_than_0(num);
		if (char_counter == -1)
			return (-1);
	}
	while (num > 0)
	{
		digits[i++] = num % baselength;
		num /= baselength;
	}
	char_counter += i;
	while (i-- > 0)
	{
		if (write(1, &base[digits[i]], 1) == -1)
			return (-1);
	}
	return (char_counter);
}

int	ft_putnbr_base(unsigned long long num, char *base)
{
	int	baselength;
	int	char_counter;

	char_counter = 0;
	if (!is_valid_base(base))
		return (0);
	baselength = 0;
	while (base[baselength])
		baselength++;
	if (baselength > 1)
		char_counter += print_num(num, base, baselength);
	return (char_counter);
}
