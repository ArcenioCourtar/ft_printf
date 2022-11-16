/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:34:26 by acourtar          #+#    #+#             */
/*   Updated: 2022/11/15 14:02:30 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>

static void	ft_putnbru_fd(unsigned int n, int fd);
static int	select_conversion(va_list args, char c);
static int	numlen_calc(long i);
static int	hex_conversion(size_t i, char c, int called);

// Mirror functionality from printf.
// Minus the hard stuff. xd
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			if (*(str + 1) == '%')
				ft_putchar_fd('%', 1);
			else
				len += select_conversion(args, str[1]) - 1;
			str++;
		}
		else
			ft_putchar_fd(*str, 1);
		len++;
		str++;
	}
	va_end(args);
	return (len);
}

// Call this function after a '%' is encountered in 'str'
// Act accordingly based on what's encountered after the '%'
static int	select_conversion(va_list args, char c)
{
	char	*str;

	if (c == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
		{
			ft_putstr_fd("(null)", 1);
			return (6);
		}
		ft_putstr_fd(str, 1);
		return ((int)ft_strlen(str));
	}
	else if (c == 'i' || c == 'd')
		return (numlen_calc(va_arg(args, int)));
	else if (c == 'u')
		return (numlen_calc(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (hex_conversion(va_arg(args, unsigned int), c, 0));
	else if (c == 'p')
		return (hex_conversion(va_arg(args, size_t), c, 0));
	else if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	return (1);
}

// Calculate and return the length of 'i' given as argument,
// Print the corresponding characters as well.
static int	numlen_calc(long i)
{
	int	numlen;

	if (i < 0)
		ft_putnbr_fd(i, 1);
	else
		ft_putnbru_fd((unsigned int) i, 1);
	if (i == 0)
		return (1);
	if (i < 0)
	{
		numlen = 2;
		i *= -1;
	}
	else
		numlen = 1;
	while (i > 9)
	{
		i = i / 10;
		numlen++;
	}
	return (numlen);
}

// Literally putnbr from libft but for unsigned ints
void	ft_putnbru_fd(unsigned int n, int fd)
{
	char	result;

	result = '0';
	if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
	}
	result += n % 10;
	write(fd, &result, 1);
}

// Converts the number 'i' into it's hex equivalent.
// Since pointers also use hex notation I handle %x, %X and %p,
// with this one function. 
static int	hex_conversion(size_t i, char c, int called)
{
	char	*hex_chars;
	int		len;

	len = 0;
	if (called == 0 && c == 'p')
	{
		ft_putstr_fd("0x", 1);
		len += 2;
	}
	if (called == 0 && i == 0)
	{
		ft_putchar_fd('0', 1);
		return (len + 1);
	}
	if (c == 'X')
		hex_chars = "0123456789ABCDEF";
	else
		hex_chars = "0123456789abcdef";
	if (i != 0)
	{
		len += hex_conversion((i / 16), c, 1);
		len++;
		ft_putchar_fd(hex_chars[i % 16], 1);
	}
	return (len);
}
