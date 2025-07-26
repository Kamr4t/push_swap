/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:59:17 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/25 15:09:59 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handler_both_r(t_data ***data, int index, int next_index)
{
	stack	***lst_a;
	stack	***lst_b;
	int i = 0;
	int j = 0;
	int k = 0;

	lst_a = &((*(*data))->lst_a);
	lst_b = &((*(*data))->lst_b);
	while ((*(*lst_a))->index != index && (*(*lst_b))->index != next_index)
	{
		i++;
		ft_rotate(&((*(*data))->lst_a));
		ft_rotate(&((*(*data))->lst_b));
		ft_printf("rr\n");
	}
	while ((*(*lst_a))->index != index)
	{
		j++;
		ft_rotate(&((*(*data))->lst_a));
		ft_printf("ra\n");
	}
	while ((*(*lst_b))->index != next_index)
	{
		k++;
		ft_rotate(&((*(*data))->lst_b));
		ft_printf("rb\n");
	}
	// ft_printf("len of b: %d\n", (**data)->len_b);
	// ft_printf("len of a: %d\n", (**data)->len_a);
	// ft_printf("TOTAL: %d\n", i + j + k);
	// ft_printf("rr: %d, ra: %d, rb: %d\n", i, j ,k);
}

void	handler_a_r_b_rr(t_data ***data, int index, int next_index)
{
	stack	***lst_a;
	stack	***lst_b;

	lst_a = &((*(*data))->lst_a);
	lst_b = &((*(*data))->lst_b);
	while ((*(*lst_a))->index != index)
	{
		ft_rotate(&((*(*data))->lst_a));
		ft_printf("ra\n");
	}
	while ((*(*lst_b))->index != next_index)
	{
		ft_reverse_rotate(&((*(*data))->lst_b));
		ft_printf("rrb\n");
	}
}

void	handler_a_rr_b_r(t_data ***data, int index, int next_index)
{
	stack	***lst_a;
	stack	***lst_b;

	lst_a = &((*(*data))->lst_a);
	lst_b = &((*(*data))->lst_b);
	while ((*(*lst_a))->index != index)
	{
		ft_reverse_rotate(&((*(*data))->lst_a));
		ft_printf("rra\n");
	}
	while ((*(*lst_b))->index != next_index)
	{
		ft_rotate(&((*(*data))->lst_b));
		ft_printf("ra\n");
	}
}

void	handler_both_rr(t_data ***data, int index, int next_index)
{
	stack	***lst_a;
	stack	***lst_b;

	lst_a = &((*(*data))->lst_a);
	lst_b = &((*(*data))->lst_b);
	while ((*(*lst_a))->index != index && (*(*lst_b))->index != next_index)
	{
		ft_reverse_rotate(&((*(*data))->lst_a));
		ft_reverse_rotate(&((*(*data))->lst_b));
		ft_printf("rrr\n");
	}
	while ((*(*lst_a))->index != index)
	{
		ft_reverse_rotate(&((*(*data))->lst_a));
		ft_printf("rra\n");
	}
	while ((*(*lst_b))->index != next_index)
	{
		ft_reverse_rotate(&((*(*data))->lst_b));
		ft_printf("rrb\n");
	}
}
