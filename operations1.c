/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:05:37 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/10 14:18:03 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(stack **lst)
{
	stack	*lst_ptr;
	stack	*tmp_ptr;
	int		tmp_nbr;

	lst_ptr = *lst;
	tmp_ptr = lst_ptr;
	tmp_nbr = lst_ptr->nbr;
	lst = &lst_ptr->next;
	tmp_ptr->nbr = lst_ptr->nbr;
	lst_ptr->nbr = tmp_nbr;
}

void	ft_push(stack **lst_dest, stack **lst_source) 
{
	stack	*tmp_stack;

    if (*lst_source == NULL)
        return;
    tmp_stack = *lst_source;
    *lst_source = (*lst_source)->next;
    tmp_stack->next = *lst_dest;
    *lst_dest = tmp_stack;
}

void	ft_rotate(stack **lst)
{
	stack	*first;
	stack	*last;

	first = *lst;
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	*lst = first->next;
	first->next = NULL;
	last->next = first;
}

void	ft_reverse_rotate(stack **lst)
{
	stack *prev = NULL;
	stack *last = *lst;

	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *lst;
	*lst = last;
}
