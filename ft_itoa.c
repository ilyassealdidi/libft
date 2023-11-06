/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:16:06 by ialdidi           #+#    #+#             */
/*   Updated: 2023/11/04 18:08:12 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_length(int n)
{
	int	len;

	len = 1 + (n < 0);
	n /= 10;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		num_len;
	char	*str;

	num_len = num_length(n);
	str = (char *)calloc(num_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	nbr = n;
	if (nbr <= 0)
	{
		str[0] = '-' * (nbr < 0) + '0' * (nbr == 0);
		nbr = -nbr;
	}
	while (nbr)
	{
		str[--num_len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
