/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:47:31 by ialdidi           #+#    #+#             */
/*   Updated: 2023/11/13 09:58:26 by ialdidi          ###   ########.fr       */
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
	char	*str;

	num = n;
	n_len = number_length(num);
	str = (char *)ft_calloc(n_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (n_len)
	{
		str[--n_len] = (num % 10) * (1 - 2 * (num < 0)) + '0';
		num /= 10;
	}
	*str = *str - 3 * (n < 0);
	return (str);
}
