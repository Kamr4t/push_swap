/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:14:54 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/22 16:22:46 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_list;
	t_list	*ptr;

	new_list = NULL;
	ptr = lst;
	while (ptr != NULL)
	{
		new_node = malloc(sizeof(t_list));
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_node->content = f(ptr->content);
		new_node->next = NULL;
		ft_lstadd_back(&new_list, new_node);
		ptr = ptr->next;
	}
	return (new_list);
}
