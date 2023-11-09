/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:25:27 by ialdidi           #+#    #+#             */
/*   Updated: 2023/11/07 10:07:47 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*string;

	string = (char *)s;
	while (*string)
	{
		if (*string == (char)c)
			return (string);
		string++;
	}
	if (*string == (char)c)
		return (string);
	return (0);
}
