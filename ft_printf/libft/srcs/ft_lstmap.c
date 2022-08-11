/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchee <nchee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:31:15 by nchee             #+#    #+#             */
/*   Updated: 2022/07/11 19:50:49 by nchee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*nodes;

	if (!lst)
		return (0);
	new_list = 0;
	while (lst)
	{
		nodes = ft_lstnew(f(lst->content));
		if (!nodes)
		{
			ft_lstclear(&new_list, del);
			return (0);
		}
		ft_lstadd_back(&new_list, nodes);
		lst = lst->next;
	}
	return (new_list);
}
