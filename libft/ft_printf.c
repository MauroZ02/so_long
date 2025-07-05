/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:10:41 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/05 22:33:08 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		print_char((int)str[i]);
		i++;
	}
	return (i);
}

int	print_format(char specifier, va_list args)
{
	int	i;

	i = 0;
	if (specifier == 'c')
		i += print_char(va_arg(args, int));
	else if (specifier == 's')
		i += print_str(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		i += print_dec(va_arg(args, int));
	else if (specifier == 'x' || specifier == 'X')
	{
		if (specifier == 'x')
			i += print_hex(va_arg(args, unsigned int), HEX_LOW_BASE);
		else
			i += print_hex(va_arg(args, unsigned int), HEX_UPP_BASE);
	}
	else if (specifier == 'u')
		i += print_unsigned(va_arg(args, unsigned int));
	else if (specifier == 'p')
		i += print_ptr((void *)va_arg(args, unsigned long), HEX_LOW_BASE);
	else
		i += write(1, &specifier, 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				i += write(1, "%", 1);
			else
				i += print_format(*format, args);
		}
		else
			i += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (i);
}

// int	main()
// {
// 	int	count;

// 	/*count = ft_printf("Test s: Hello %s\n", "Mauro");
// 	ft_printf("The chars written are %d\n", count);
// 	count = printf("printf: Hello %s\n", "Mauro");
// 	printf("The chars written are %d\n\n", count);

// 	count = ft_printf("Test x: %x\n", -42);
// 	ft_printf("The chars written are %d\n", count);
// 	count = printf("printf: %x\n", -42);
// 	printf("The chars written are %d\n\n", count);

// 	count = ft_printf("Test d: %d\n", -42);
// 	ft_printf("The chars written are %d\n", count);
// 	count = printf("printf: %d\n", -42);
// 	printf("The chars written are %d\n\n", count);

// 	count = ft_printf("Test X: %X\n", -42);
// 	ft_printf("The chars written are %d\n", count);
// 	count = printf("printf: %X\n", -42);
// 	printf("The chars written are %d\n\n", count);

// 	char *n = "08343489";
// 	count = ft_printf("Test p: %p\n", n);
// 	ft_printf("The chars written are %d\n", count);
// 	count = printf("printf: %p\n", n);
// 	printf("The chars written are %d\n\n", count);

// 	count = ft_printf("Test u: %u\n", 42);
// 	ft_printf("The chars written are %d\n", count);
// 	count = printf("printf: %u\n", 42);
// 	printf("The chars written are %d\n\n", count);

// 	count = ft_printf("Test p0: %p\n", 0);
// 	ft_printf("The chars written are %d\n", count);
// 	count = printf("printf0: %p\n", NULL);
// 	printf("The chars written are %d\n\n", count);*/

// 	// ft_printf("Test 2:\n");
// 	// count = ft_printf(" %p ", -1);
// 	// ft_printf("\nThe chars written are %d", count);

// 	// count = printf(" %p ", -1);
// 	// printf("\nThe chars written are %d", count);

// 	// ft_printf("\nTest 3:\n");
// 	// count = ft_printf(" %p ", 15);
// 	// ft_printf("\nThe chars written are %d", count);

// 	// count = printf(" %p ", 15);
// 	// printf("\nThe chars written are %d", count);

// 	/*ft_printf("\nTest 8:\n");
// 	count = ft_printf(" %p ", 9223372036854775808);
// 	ft_printf("\nThe chars written are %d", count);

// 	count = printf(" %p ", 9223372036854775808);
// 	printf("\nThe chars written are %d", count);*/
// }