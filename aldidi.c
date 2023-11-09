/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aldidi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:23:34 by ialdidi           #+#    #+#             */
/*   Updated: 2023/11/09 14:24:00 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
	ascii = (char *)calloc(n_len + 1, sizeof(char));
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

int	main(int argc, char const *argv[])
{
	return (0);
}
