/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:05:37 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/20 13:29:06 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(stack ***lst)
{
	stack	*first;
	stack	*second;

	first = **lst;
	second = first->next;
	first->next = second->next;
	second->next = first;
	**lst = second;
}

void	ft_push(stack ***lst_dest, stack ***lst_source) 
{
	stack	*tmp;

	tmp = **lst_source;
	**lst_source = tmp->next;
	tmp->next = **lst_dest;
	**lst_dest = tmp;
	operation_counter();
}

void	ft_rotate(stack ***lst)
{
	stack	*first;
	stack	*last;
	if (!lst || !*lst || !**lst || !(**lst)->next)
		return;
	first = **lst;
	last = **lst;
	while (last->next != NULL)
		last = last->next;
	**lst = first->next;
	first->next = NULL;
	last->next = first;
	operation_counter();
}

void	ft_reverse_rotate(stack ***lst)
{
	stack *prev;
	stack *last;

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
	operation_counter();
}
