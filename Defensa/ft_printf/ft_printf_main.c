/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejmart <alejmart>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:30:00 by alejmart          #+#    #+#             */
/*   Updated: 2025/10/28 19:12:52 by alejmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	total;

	total = 0;
	total += ft_printf("Cadena literal\n");
	total += ft_printf("Entero con signo: %+d\n", 42);
	total += ft_printf("Unsigned: %u\n", 424242u);
	total += ft_printf("Hex con prefijo: %#x\n", 0x2a2a);
	total += ft_printf("Pointer: %p\n", (void *)&total);
	ft_printf("Total impreso por ft_printf: %d\n", total);
	return (0);
}
