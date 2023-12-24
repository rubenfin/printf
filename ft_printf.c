/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/19 10:06:30 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/12/15 17:21:41 by rfinneru      ########   odam.nl         */
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
	if (format[*i] == '%' && ft_strchr("cspdiuxX", format[*i + 1]))
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
	else if (format[*i] == '%' && format[*i + 1] == '\0')
		return (-1);
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

// int	main(void)
// {
// 	printf("erterterw");
// 	return (0);
// }
int	main(void)
{
	ft_printf("aaauauu%iee", ft_printf("dnafsjhy%i\n", 943));
	return (0);
}
// int	main(int argc, char **argv)
// {
// 	argc = 1;
// 	int return_val = ft_printf(argv[1]);
// 	printf("%d", return_val);
// 	return (0);
// }

// int	main(void)
// {
// 	int		i;
// 	int		j;
// 	char	string1[] = "A%%%w";
// 	char	*string2;

// 	string2 = "123456%%";
// 	i = ft_printf(string1, string2);
// 	printf("\n%d\n", i);
// 	j = printf(string1, string2);
// 	printf("\n%d", j);
// 	if (i != j)
// 	{
// 		printf("\n\nThe value is incorrect!\ni = %d\nj =%d\n\n", i, j);
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	void	*p;

// 	p = NULL;
// 	printf("%d\n", ft_printf("       Single characters: %c\n", 'c'));
// 	printf("%d\n", printf("printf Single characters: %c\n", 'c'));
// 	printf("%d\n", ft_printf("       String: %s\n", "hello"));
// 	printf("%d\n", printf("printf String: %s\n", "hello"));
// 	printf("%d\n", ft_printf("       Void pointer: %p\n", p));
// 	printf("%d\n", printf("printf Void pointer: %p\n", p));
// 	printf("%d\n", ft_printf("       Decimal (base 10): %d\n", -156734560));
// 	printf("%d\n", printf("printf Decimal (base 10): %d\n", -156734560));
// 	printf("%d\n", ft_printf("       Integer (base 10): %i\n", -15077634));
// 	printf("%d\n", printf("printf Integer (base 10): %i\n", -15077634));
// 	printf("%d\n", ft_printf("       Unsigned decimal (base 10):%u\n", 122));
// 	printf("%d\n", printf("printf Unsigned decimal (base 10):%u\n", 122));
// 	printf("%d\n", ft_printf("       Hexadecimal lowercase: %x\n", 40044));
// 	printf("%d\n", printf("printf Hexadecimal lowercase: %x\n", 40044));
// 	printf("%d\n", ft_printf("       Hexadecimal uppercase: %X\n", 40044));
// 	printf("%d\n", printf("printf Hexadecimal uppercase: %X\n", 40044));
// 	printf("%d\n", ft_printf("       Percent: %%%%\n"));
// 	printf("%d\n", printf("printf Percent: %%%%\n"));
// 	return (0);
// }

// int	main(void)
// {
// 	// printf("%c && %s\n", "string" ,'c');
// 	ft_printf("%c && %s\n", "string" ,'c');
// 	return (0);
// }
