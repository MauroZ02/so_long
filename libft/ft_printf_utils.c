/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:10:47 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/05 20:10:30 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_dec(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		i += 1;
		n = -n;
	}
	if (n > 9)
		i += print_dec(n / 10);
	i += print_char(n % 10 + '0');
	return (i);
}

int	print_hex(unsigned int n, const char *symbols)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += print_hex(n / 16, symbols);
	i += print_char(symbols[n % 16]);
	return (i);
}

int	print_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
		i += print_unsigned(n / 10);
	i += print_char((unsigned int)n % 10 + '0');
	return (i);
}

int	print_long(unsigned long n, const char *symbols)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += print_long(n / 16, symbols);
	i += print_char(symbols[n % 16]);
	return (i);
}

int	print_ptr(void *n, const char *symbols)
{
	unsigned long	nb;
	int				i;

	i = 0;
	nb = (unsigned long)n;
	if (n == 0)
		return (write(1, "(nil)", 5));
	i += write(1, "0x", 2);
	i += print_long(nb / 16, symbols);
	i += print_char(symbols[nb % 16]);
	return (i);
}
