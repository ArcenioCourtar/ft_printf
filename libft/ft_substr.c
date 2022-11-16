/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:42:39 by acourtar          #+#    #+#             */
/*   Updated: 2022/10/19 15:12:55 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

// Returns a newly allocated substring from 's', starting form index 'start',
// max size 'len'.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	unsigned int	const_len;

	i = 0;
	const_len = ft_strlen(s);
	if (start > const_len)
		return (ft_strdup(""));
	if ((start + len) > const_len)
		str = ft_calloc(1, (const_len - start + 1));
	else
		str = ft_calloc(1, (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
