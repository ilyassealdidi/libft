/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:38:05 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/10 08:24:00 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	size_t	num;
	int		sign;

	num = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		sign = 1 - 2 * (*str++ == '-');
	while (ft_isdigit(*str))
	{
		if (num >= 922337203685477580)
		{
			if (((num == 922337203685477580 && *str - '0' > 7)
					|| num > 922337203685477580) && sign == -1)
				return (LONG_MIN);
			if (((num == 922337203685477580 && *str - '0' <= 7)
					|| num > 922337203685477580) && sign == 1)
				return (LONG_MAX);
		}
		num = num * 10 + *str++ - '0';
	}
	return (num * sign);
}
