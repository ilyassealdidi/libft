/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:24:44 by ialdidi           #+#    #+#             */
/*   Updated: 2023/11/11 08:57:33 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	llen;

	i = 0;
	llen = ft_strlen(little);
	if (!llen)
		return ((char *)big);
	while (*big && i + llen <= len)
	{
		if (*big == *little && !ft_strncmp(big, little, llen))
			return ((char *)big);
		i++;
		big++;
	}
	return (0);
}
