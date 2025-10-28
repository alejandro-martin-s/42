/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejmart <alejmart>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 04:23:39 by alejmart          #+#    #+#             */
/*   Updated: 2025/10/12 04:23:40 by alejmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*duplicate;
	size_t	length;
	size_t	index;

	length = ft_strlen(str);
	duplicate = (char *)malloc(length + 1);
	if (!duplicate)
		return (NULL);
	index = 0;
	while (index < length)
	{
		duplicate[index] = str[index];
		index++;
	}
	duplicate[length] = '\0';
	return (duplicate);
}
