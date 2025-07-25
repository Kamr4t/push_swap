/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:59:17 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/26 16:32:00 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handler_both_r(t_data ***data, int index, int next_index)
{
	t_stack	***lst_a;
	t_stack	***lst_b;

	lst_a = &((*(*data))->lst_a);
	lst_b = &((*(*data))->lst_b);
	while ((*(*lst_a))->index != index && (*(*lst_b))->index != next_index)
	{
		ft_rotate(&((*(*data))->lst_a));
		ft_rotate(&((*(*data))->lst_b));
		ft_printf("rr\n");
	}
	while ((*(*lst_a))->index != index)
	{
		ft_rotate(&((*(*data))->lst_a));
		ft_printf("ra\n");
	}
	while ((*(*lst_b))->index != next_index)
	{
		ft_rotate(&((*(*data))->lst_b));
		ft_printf("rb\n");
	}
}

void	handler_a_r_b_rr(t_data ***data, int index, int next_index)
{
	t_stack	***lst_a;
	t_stack	***lst_b;

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
	t_stack	***lst_a;
	t_stack	***lst_b;

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
		ft_printf("rb\n");
	}
}

void	handler_both_rr(t_data ***data, int index, int next_index)
{
	t_stack	***lst_a;
	t_stack	***lst_b;

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
