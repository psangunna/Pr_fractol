/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:09:18 by pamela            #+#    #+#             */
/*   Updated: 2024/04/09 10:09:22 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
function to free memory allocated for the content of a node.
It takes a node lst and a function pointer del as parameters.
It checks if both parameters are not NULL, and if they are valid, 
it frees the memory allocated for the content of the node using the
provided del function, and then frees the memory allocated for the node itself. 
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
