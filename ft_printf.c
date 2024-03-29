/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:48:43 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/29 21:35:33 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_address(unsigned long nbr)
{
	static int		written;

	if (written == 0)
	{
		ft_putstr_fd("0x", 1);
		written += 2;
	}
	if (nbr >= 16)
	{
		written += ft_print_address(nbr / 16);
		return (written += ft_print_address(nbr % 16));
	}
	else
	{
		ft_putchar_fd("0123456789abcdef"[nbr], 1);
		written++;
	}
	return (written);
}

static int	ft_putnbr_base(long nbr, int base, unsigned char is_upper)
{
	char	*arr;
	int		written;

	written = 0;
	arr = "0123456789ABCDEF";
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		written++;
		nbr = -nbr;
	}
	if (nbr >= base)
	{
		written += ft_putnbr_base(nbr / base, base, is_upper);
		return (written += ft_putnbr_base(nbr % base, base, is_upper));
	}
	else
	{
		if (is_upper)
			ft_putchar_fd(arr[nbr], 1);
		else
			ft_putchar_fd(ft_tolower(arr[nbr]), 1);
		written++;
	}
	return (written);
}

static int	check_format(char format, va_list args)
{
	char	*str;

	if (format == 'd' || format == 'i')
		return (ft_putnbr_base(va_arg(args, int), 10, 0));
	else if (format == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), 10, 0));
	else if (format == 'x')
		return (ft_putnbr_base((long)va_arg(args, unsigned int), 16, 0));
	else if (format == 'X')
		return (ft_putnbr_base((long)va_arg(args, unsigned int), 16, 1));
	else if (format == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1), 1);
	else if (format == '%')
		return (ft_putchar_fd('%', 1), 1);
	else if (format == 'p')
		return (ft_print_address((unsigned long)va_arg(args, void *)) + 2);
	else if (format == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		return (ft_putstr_fd(str, 1), ft_strlen(str));
	}
	else
		return (ft_putchar_fd(format, 1), 1);
}

int	ft_printf(const char *s, ...)
{
	int		written;
	va_list	args;

	if (write(1, "", 0) < 0)
		return (-1);
	va_start(args, s);
	written = 0;
	while (*s)
	{
		if (*s == '%' && *(s + 1))
			written += check_format(*++s, args);
		else
			written += write(1, s, 1);
		s++;
	}
	va_end(args);
	return (written);
}
