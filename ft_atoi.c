/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:07:49 by ialdidi           #+#    #+#             */
/*   Updated: 2023/11/09 13:38:03 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	num;
	int					sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = 1 - 2 * (*str++ == '-');
	while (ft_isdigit(*str))
	{
		if (num > 1844674407370955161
			|| (num == 1844674407370955161 && *str - '0' > 5))
			return (-1 * (sign > 0));
		num = num * 10 + (*str++ - '0');
	}
	return (num * sign);
}
