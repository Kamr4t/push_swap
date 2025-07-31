/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:05:37 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/31 11:16:14 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack ***lst)
{
	t_stack	*first;
	t_stack	*second;

	first = **lst;
	second = first->next;
	first->next = second->next;
	second->next = first;
	**lst = second;
	ft_printf("sa\n");
}

void	ft_push(t_stack ***lst_dest, t_stack ***lst_source)
{
	t_stack	*tmp;

	tmp = **lst_source;
	**lst_source = tmp->next;
	tmp->next = **lst_dest;
	**lst_dest = tmp;
}

void	ft_rotate(t_stack ***lst)
{
	t_stack	*first;
	t_stack	*last;

	if (!lst || !*lst || !**lst || !(**lst)->next)
		return ;
	first = **lst;
	last = **lst;
	while (last->next != NULL)
		last = last->next;
	**lst = first->next;
	first->next = NULL;
	last->next = first;
}

void	ft_reverse_rotate(t_stack ***lst)
{
	t_stack	*prev;
	t_stack	*last;

	if (!lst || !*lst || !**lst || !(**lst)->next)
		return ;
	prev = NULL;
	last = **lst;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = **lst;
	**lst = last;
}
