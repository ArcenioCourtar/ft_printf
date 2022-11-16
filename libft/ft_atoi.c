/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:30:28 by acourtar          #+#    #+#             */
/*   Updated: 2022/11/01 09:16:13 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	atoi_isspace(const char *str);

// Return int equivalent of string 'str'.
int	ft_atoi(const char *str)
{
	long	number;
	int		is_negative;

	number = 0;
	is_negative = 0;
	while (atoi_isspace(str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_negative = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number *= 10;
		number += *str - '0';
		str++;
	}
	if (is_negative == 1)
		number *= -1;
	return ((int) number);
}

// Similar to the other 'isx' functions, but checks for spaces and
// space-like characters.
// Why isn't this part of libft?????? cringe.
static int	atoi_isspace(const char *str)
{
	if (*str == ' ' || *str == '\n' || *str == '\f')
		return (1);
	if (*str == '\r' || *str == '\t' || *str == '\v')
		return (1);
	return (0);
}
