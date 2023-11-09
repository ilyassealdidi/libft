/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:04:31 by ialdidi           #+#    #+#             */
/*   Updated: 2023/11/07 08:26:51 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	slen;
	size_t	i;

	i = 0;
	slen = ft_strlen(src);
	if (len)
	{
		while (*src && ++i < len)
			*dst++ = *src++;
		*dst = 0;
	}
	return (slen);
}
