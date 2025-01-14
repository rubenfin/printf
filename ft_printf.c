/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/19 10:06:30 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/11/17 14:15:45 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_printer(const char format, va_list args)
{
	if (format == 'c')
		return (arg_c(args));
	else if (format == 's')
		return (arg_s(args));
	else if (format == 'd' || format == 'i')
		return (arg_d_i(args));
	else if (format == 'x' || format == 'X')
		return (arg_x_upp_x(format, args));
	else if (format == 'u')
		return (arg_u(args));
	else if (format == 'p')
		return (arg_p(args));
	return (0);
}

int	error_check(const char *format, va_list args, int *i)
{
	if (format[*i] == '%' && format[*i + 1] == '\0')
		return (-1);
	else if (format[*i] == '%' && ft_strchr("cspdiuxX", format[*i + 1]))
	{
		*i += 2;
		return (format_printer(format[*i - 1], args));
	}
	else if (format[*i] == '%' && format[*i + 1] == '%')
	{
		*i += 2;
		return (ft_putchar('%'));
	}
	else if (!ft_strchr("cspdiuxX", format[*i + 1]))
		return (ft_putchar(format[(*i)++]));
	else if (format[*i] != '%')
		return (ft_putchar(format[(*i)++]));
	return (0);
}

int	handle_format(const char *format, va_list args)
{
	int	char_count;
	int	i;
	int	result;

	result = 0;
	char_count = 0;
	i = 0;
	while (format[i])
	{
		result = error_check(format, args, &i);
		if (result == -1)
			return (-1);
		char_count += result;
	}
	return (char_count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		char_count;

	if (!format)
		return (-1);
	va_start(args, format);
	char_count = handle_format(format, args);
	va_end(args);
	return (char_count);
}

int	main(void)
{
	void	*p;

	p = NULL;
	printf(" - %d\n", ft_printf("       Single characters: %c", 'c'));
	printf(" - %d\n", printf("printf Single characters: %c", 'c'));
	printf(" - %d\n", ft_printf("       String: %s", "hello"));
	printf(" - %d\n", printf("printf String: %s", "hello"));
	printf(" - %d\n", ft_printf("       Void pointer: %p", p));
	printf(" - %d\n", printf("printf Void pointer: %p", p));
	// printf(" - %d\n", ft_printf("       Decimal (base 10): %d", -INT_MIN));
	// printf(" - %d\n", printf("printf Decimal (base 10): %d", -INT_MIN));
	printf(" - %d\n", ft_printf("       Integer (base 10): %i", INT_MAX));
	printf(" - %d\n", printf("printf Integer (base 10): %i", INT_MAX));
	printf(" - %d\n", ft_printf("       Unsigned decimal (base 10):%u", 122));
	printf(" - %d\n", printf("printf Unsigned decimal (base 10):%u", 122));
	printf(" - %d\n", ft_printf("       Hexadecimal lowercase: %x", 40044));
	printf(" - %d\n", printf("printf Hexadecimal lowercase: %x", 40044));
	printf(" - %d\n", ft_printf("       Hexadecimal uppercase: %X", 78696754));
	printf(" - %d\n", printf("printf Hexadecimal uppercase: %X", 78696754));
	printf(" - %d\n", ft_printf("       Percent: %%%%%%"));
	printf(" - %d\n", printf("printf Percent: %%%%%%"));
	return (0);
}
