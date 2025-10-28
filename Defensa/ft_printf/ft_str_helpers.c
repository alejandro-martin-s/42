/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejmart <alejmart>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 04:21:09 by alejmart          #+#    #+#             */
/*   Updated: 2025/10/12 04:21:10 by alejmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Handles NULL string and returns the appropriate string.
 */
char	*ft_handle_null_str(char *stri, t_format *format)
{
	if (stri == NULL)
	{
		if (format->precision >= 0 && format->precision < 6)
			return ("");
		else
			return (NULLSTRING);
	}
	return (stri);
}

/**
 * @brief Calculates the effective length considering precision.
 */
int	ft_get_effective_len(char *str, t_format *format)
{
	int	len;

	len = ft_strlen(str);
	if (format->precision >= 0 && format->precision < len)
		len = format->precision;
	return (len);
}
