/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejmart <alejmart>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:30:00 by alejmart          #+#    #+#             */
/*   Updated: 2025/11/01 20:36:45 by alejmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	test_basic_conversions(void)
{
	ft_printf("\n=== CONVERSIONES BÁSICAS ===\n");
	ft_printf("Char: %c\n", 'A');
	ft_printf("String: %s\n", "Hola, mundo!");
	ft_printf("String NULL: %s\n", (char *)NULL);
	ft_printf("Entero: %d\n", 42);
	ft_printf("Entero negativo: %d\n", -42);
	ft_printf("Unsigned: %u\n", 424242u);
	ft_printf("Hex lowercase: %x\n", 255);
	ft_printf("Hex uppercase: %X\n", 255);
	ft_printf("Percent: %%\n");
}

static void	test_flags(void)
{
	ft_printf("\n=== FLAGS ===\n");
	ft_printf("Plus flag: %+d, %+d\n", 42, -42);
	ft_printf("Space flag: % d, % d\n", 42, -42);
	ft_printf("Hash hex: %#x, %#X\n", 0x2a, 0x2a);
	ft_printf("Hash con 0: %#x\n", 0);
	ft_printf("Zero padding: %05d\n", 42);
	ft_printf("Zero con negativo: %05d\n", -42);
}

static void	test_width(void)
{
	ft_printf("\n=== FIELD WIDTH ===\n");
	ft_printf("Width 10: |%10d|\n", 42);
	ft_printf("Width 10 left: |%-10d|\n", 42);
	ft_printf("Width string: |%20s|\n", "test");
	ft_printf("Width char: |%5c|\n", 'X');
	ft_printf("Width hex: |%15x|\n", 0xabcd);
}

static void	test_precision(void)
{
	ft_printf("\n=== PRECISION ===\n");
	ft_printf("Precision 5: %.5d\n", 42);
	ft_printf("Precision con negativo: %.5d\n", -42);
	ft_printf("Precision 0: %.0d\n", 0);
	ft_printf("Precision string: %.5s\n", "Hello World");
	ft_printf("Precision NULL: %.3s\n", (char *)NULL);
	ft_printf("Precision hex: %.8x\n", 0xff);
}

static void	test_combined(void)
{
	ft_printf("\n=== COMBINACIONES ===\n");
	ft_printf("Width + precision: |%10.5d|\n", 42);
	ft_printf("Zero + width: |%010d|\n", 42);
	ft_printf("Plus + width: |%+10d|\n", 42);
	ft_printf("Minus + width: |%-10d|\n", 42);
	ft_printf("Hash + width + precision: |%#15.8x|\n", 0xabcd);
	ft_printf("Todo: |%+015.10d|\n", 42);
}

static void	test_pointers(void)
{
	int		num;
	char	*str;

	num = 42;
	str = "test";
	ft_printf("\n=== POINTERS ===\n");
	ft_printf("Pointer int: %p\n", (void *)&num);
	ft_printf("Pointer string: %p\n", (void *)str);
	ft_printf("Pointer NULL: %p\n", (void *)NULL);
	ft_printf("Pointer con width: |%20p|\n", (void *)&num);
	ft_printf("Pointer left: |%-20p|\n", (void *)&num);
}

static void	test_edge_cases(void)
{
	ft_printf("\n=== CASOS EXTREMOS ===\n");
	ft_printf("INT_MIN: %d\n", -2147483648);
	ft_printf("INT_MAX: %d\n", 2147483647);
	ft_printf("UINT_MAX: %u\n", 4294967295u);
	ft_printf("Cero: %d, %u, %x\n", 0, 0u, 0);
	ft_printf("String vacío: '%s'\n", "");
	ft_printf("Multiple specs: %d %s %c %x\n", 42, "test", 'A', 0xff);
}

int	main(void)
{
	int	total;

	ft_printf("╔════════════════════════════════════════╗\n");
	ft_printf("║   TESTING FT_PRINTF IMPLEMENTATION     ║\n");
	ft_printf("╚════════════════════════════════════════╝\n");
	
	test_basic_conversions();
	test_flags();
	test_width();
	test_precision();
	test_combined();
	test_pointers();
	test_edge_cases();
	
	ft_printf("\n=== COMPARACIÓN CON PRINTF REAL ===\n");
	total = ft_printf("ft_printf: %+10.5d | %#x | %-15s\n", 42, 0xff, "test");
	ft_printf("Caracteres escritos: %d\n", total);
	
	ft_printf("\n✓ Tests completados\n");
	return (0);
}
