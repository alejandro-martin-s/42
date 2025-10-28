/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejmart <alejmart>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 04:21:24 by alejmart          #+#    #+#             */
/*   Updated: 2025/10/12 05:45:44 by alejmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define NULLSTRING "(null)"
# ifdef __APPLE__
#  define NULLPOINTER "0x0"
# else
#  define NULLPOINTER "(nil)"
# endif

# define HEXAUP "0123456789ABCDEF"
# define HEXALOW "0123456789abcdef"

/*
 * @brief Structure representing a format specifier in ft_printf.
 * @param minus: Flag for left-justification.
 * @param zero: Flag for zero-padding.
 * @param precision: Precision for the output.
 * @param hash: Flag for alternate form.
 * @param space: Flag for space before positive number.
 * @param plus: Flag for sign before number.
 * @param field_width: Minimum number of characters to output.
 * @param specifier: The conversion specifier.
 */
typedef struct s_format
{
	int		minus;
	int		zero;
	int		precision;
	int		hash;
	int		space;
	int		plus;
	int		field_width;
	char	specifier;
}	t_format;

int			ft_print_char(int c, t_format *format);
int			ft_print_str(char *stri, t_format *format);
int			ft_print_int(int n, t_format *format);
int			ft_print_ui(unsigned int n, t_format *format);
int			ft_print_hex(unsigned int n, int hex_up, t_format *format);
int			ft_print_ptr(unsigned long long n, int hex_up, t_format *format);

void		ft_add_hex_prefix(char **str, int hex_up);
void		ft_zero_padding(char *str, char **pad, t_format *format, int len);
char		*ft_precision_format(char *str, t_format *format);
char		*ft_plus_space_format(int n, char *str, t_format *format);
char		*ft_field_width(char *str, t_format *format);

void		ft_swap_ptr(char *s1, char *s2);
char		*ft_strrev(char *str);
char		*ft_itoa_base(unsigned long long int n, int base, int flag_hex_up);
char		*ft_handle_null_str(char *stri, t_format *format);
int			ft_get_effective_len(char *str, t_format *format);

int			ft_handle_specifier(t_format *format, va_list args);
t_format	*ft_parse_format_specifier(const char *str, int *i);

int			ft_printf(const char *frmt, ...);

#endif
