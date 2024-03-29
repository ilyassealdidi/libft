/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:41:54 by ialdidi           #+#    #+#             */
/*   Updated: 2023/11/12 07:43:43 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, int c)
{
	int	cnt;
	int	pre;

	cnt = 0;
	pre = 1;
	while (*s)
	{
		if (*s == c)
			pre = 1;
		else if (pre)
		{
			pre = 0;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static void	*free_memory(char **strs, int i)
{
	while (i--)
		free(strs[i]);
	free(strs);
	return (NULL);
}

static char	**split(char **strs, char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			strs[i] = ft_substr(s, 0, len);
			if (!strs[i])
				return (free_memory(strs, i));
			s += len;
			i++;
		}
	}
	strs[i] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = (char **)ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	return (split(strs, s, c));
}
