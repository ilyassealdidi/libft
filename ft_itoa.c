/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:47:31 by ialdidi           #+#    #+#             */
/*   Updated: 2023/11/09 08:33:59 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_length(int num)
{
	int	cnt;

	cnt = 1;
	while (num / 10)
	{
		cnt++;
		num /= 10;
	}
	return (cnt + (num < 0));
}

char	*ft_itoa(int n)
{
	int		num;
	int		n_len;
	char	*ascii;

	num = n;
	n_len = number_length(num);
	ascii = (char *)ft_calloc(n_len + 1, sizeof(char));
	if (!ascii)
		return (NULL);
	while (n_len)
	{
		ascii[--n_len] = (num % 10) * (1 - 2 * (num < 0)) + '0';
		num /= 10;
	}
	*ascii = *ascii - 3 * (n < 0);
	return (ascii);
}
