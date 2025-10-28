/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejmart <alejmart>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 04:23:59 by alejmart          #+#    #+#             */
/*   Updated: 2025/10/12 05:03:33 by alejmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	limited_strlen(const char *s, size_t limit)
{
	size_t	len;

	len = 0;
	while (len < limit && s[len])
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	index;

	dst_len = limited_strlen(dst, size);
	src_len = ft_strlen(src);
	if (dst_len == size)
		return (src_len + size);
	index = 0;
	while (src[index] && dst_len + index + 1 < size)
	{
		dst[dst_len + index] = src[index];
		index++;
	}
	if (dst_len + index < size)
		dst[dst_len + index] = '\0';
	return (dst_len + src_len);
}
