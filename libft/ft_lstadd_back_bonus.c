/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:08:28 by pamela            #+#    #+#             */
/*   Updated: 2024/04/09 10:08:45 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
Adds a new node to the end of a linked list. It takes two parameters: a pointer 
to a pointer to the first node of the list (lst) and a pointer to the 
new node to be added (new). 
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
	}
	else
	{
		current = ft_lstlast(*lst);
		current->next = new;
	}
}
