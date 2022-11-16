/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:41:55 by acourtar          #+#    #+#             */
/*   Updated: 2022/10/26 14:34:53 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

// Perform function 'f' on each character in string 's' (does not modify 's').
// Returning the result as a newly allocated string.
// 'f' args: index of the string, character to be modified.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = ft_calloc((ft_strlen(s) + 1), 1);
	if (str == NULL)
		return (NULL);
	while (*s != '\0')
	{
		str[i] = f(i, *s);
		i++;
		s++;
	}
	return (str);
}
