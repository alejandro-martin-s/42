/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejmart <alejmart>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 04:23:07 by alejmart          #+#    #+#             */
/*   Updated: 2025/10/12 04:23:08 by alejmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*source;

	if (!dst && !src)
		return (NULL);
	if (dst == src || n == 0)
		return (dst);
	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	if (dest < source)
	{
		ft_memcpy(dst, src, n);
		return (dst);
	}
	while (n--)
		dest[n] = source[n];
	return (dst);
}
