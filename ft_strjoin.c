/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:57:44 by ialdidi           #+#    #+#             */
/*   Updated: 2023/11/02 20:25:09 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		length;

	length = strlen(s1) + strlen(s2);
	str = (char *)calloc((length + 1), sizeof(char));
	if (!str)
		return (0);
	ft_strlcat(str, s1, (ft_strlen(s1) + 1));
	ft_strlcat(str, s2, (length + 1));
	return (str);
}
