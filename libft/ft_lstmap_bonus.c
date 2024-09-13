/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:10:21 by pamela            #+#    #+#             */
/*   Updated: 2024/04/13 15:37:13 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
function takes a list lst, a function f, and a function del as parameters 
and returns a new list resulting from applying the function f to each node 
of the original list. If the function f returns NULL at any point, the function 
releases the memory allocated for the new list and its content using the del 
function and returns NULL. 
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*item;
	void	*set;

	if (!lst)
		return (0);
	new_lst = NULL;
	while (lst)
	{
		set = f(lst->content);
		item = ft_lstnew(set);
		if (!item)
		{
			del(set);
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, item);
		lst = lst->next;
	}
	return (new_lst);
}
