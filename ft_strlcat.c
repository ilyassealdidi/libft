/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:09:09 by ialdidi           #+#    #+#             */
/*   Updated: 2024/07/03 13:16:34 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	dlen;
	size_t	slen;

	if (!len)
		return (ft_strlen(src));
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (len < dlen)
		return (len + slen);
	ft_strlcpy(dst + dlen, src, len - dlen);
	return (dlen + slen);
}
