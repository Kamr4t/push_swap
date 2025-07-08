/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:05:37 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/08 16:17:22 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(stack *lst)
{
	stack	*tmp_ptr;
	int		tmp_nbr;

	tmp_ptr = lst;
	tmp_nbr = lst->nbr;
	lst = lst->next;
	tmp_ptr->nbr = lst->nbr;
	lst->nbr = tmp_nbr;
}

void	ft_push(stack *lst_source, stack *lst_dest)
{
	//stack	*tmp_ptr;

	(void)lst_dest;
	lst_source->nbr = 0;
	lst_source = lst_source->next;
	printf("new start: %d\n", lst_source->nbr);
	return (lst_source);
}
