/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejmart <alejmart>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 04:21:38 by alejmart          #+#    #+#             */
/*   Updated: 2025/10/12 04:21:39 by alejmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*skip_whitespace(const char *str)
{
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	return (str);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	str = skip_whitespace(str);
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	while (ft_isdigit(*str))
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return ((int)(result * sign));
}
