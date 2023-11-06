/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:03:40 by ialdidi           #+#    #+#             */
/*   Updated: 2023/11/06 14:22:45 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*current;
	void	*map;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		map = f(lst->content);
		current = ft_lstnew(map);
		if (!current)
		{
			del(map);
			ft_lstclear(&head, del);
			return (head);
		}
		ft_lstadd_back(&head, current);
		lst = lst->next;
	}
	return (head);
}
