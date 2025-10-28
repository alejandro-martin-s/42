/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejmart <alejmart>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 04:21:00 by alejmart          #+#    #+#             */
/*   Updated: 2025/10/12 04:21:01 by alejmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Custom implementation of the printf function.
 *
 * @param frmt The format string.
 *
 * @return The number of characters printed.
 */
int	ft_printf(const char *frmt, ...)
{
	va_list		args;
	t_format	*format;
	int			len;
	int			i;

	i = 0;
	len = 0;
	va_start(args, frmt);
	while (frmt && frmt[i])
	{
		if (frmt[i] == '%')
		{
			i++;
			format = ft_parse_format_specifier(frmt, &i);
			len += ft_handle_specifier(format, args);
			free(format);
		}
		else
			len += write(1, &frmt[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
