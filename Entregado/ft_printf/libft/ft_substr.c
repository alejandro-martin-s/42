/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejmart <alejmart>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 04:24:31 by alejmart          #+#    #+#             */
/*   Updated: 2025/10/12 04:24:32 by alejmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	available;
	size_t	index;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return ((char *)ft_calloc(1, sizeof(char)));
	available = ft_strlen(s + start);
	if (len < available)
		available = len;
	substring = (char *)malloc(available + 1);
	if (!substring)
		return (NULL);
	index = 0;
	while (index < available)
	{
		substring[index] = s[start + index];
		index++;
	}
	substring[available] = '\0';
	return (substring);
}
