/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:20:39 by ialdidi           #+#    #+#             */
/*   Updated: 2023/11/04 19:50:01 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || !*(s + 1)))
			cnt++;
		s++;
	}
	return (cnt);
}

void	*memfree(char **strs, int k)
{
	while (strs[k--])
		free(strs[k]);
	free(strs);
	return (0);
}

static char	**splited_split(char **strs, char const *s, char c)
{
	int	i;
	int	k;

	k = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = 0;
		if (*s)
		{
			while (s[i] && s[i] != c)
				i++;
			strs[k] = (char *)malloc(sizeof(char) * i + 1);
			s += i;
			if (!strs[k])
				return (memfree(strs, k));
			ft_strlcpy(strs[k], s - i, i + 1);
			k++;
		}
	}
	strs[k] = 0;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		words_count;

	if (!s)
		return (0);
	strs = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (0);
	return (splited_split(strs, s, c));
}
