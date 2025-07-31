/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:50:58 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/31 20:03:59 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_w(t_stack ***lst)
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
	ft_printf("ra\n");
}

void	ft_reverse_rotate_w(t_stack ***lst)
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
	ft_printf("rra\n");
}

static void	check_order(t_data ***data, t_stack *lst, int len)
{
	int	tmp;

	tmp = lst->index;
	lst = lst->next;
	if (tmp == len && lst->index != tmp - 2)
	{
		ft_swap(&((*(*data))->lst_a));
		ft_reverse_rotate_w(&((*(*data))->lst_a));
	}
	else if (tmp == len && lst->index == tmp - 2)
		ft_rotate_w(&((*(*data))->lst_a));
	else if (tmp == len - 1 && lst->index == len)
		ft_reverse_rotate_w(&((*(*data))->lst_a));
	else if (tmp == len - 1 && lst->index == tmp - 1)
		ft_swap(&((*(*data))->lst_a));
	else
	{
		ft_rotate_w(&((*(*data))->lst_a));
		ft_swap(&((*(*data))->lst_a));
		ft_reverse_rotate_w(&((*(*data))->lst_a));
	}
}

static void	rotate_a(t_data ***data, int len, int index)
{
	t_stack	***lst_a;
	int		pos;

	lst_a = &((*(*data))->lst_a);
	pos = node_pos((*(*lst_a)), index, 1);
	if (pos <= len / 2)
	{
		while ((*(*lst_a))->index != index)
		{
			ft_printf("ra\n");
			ft_rotate(&((*(*data))->lst_a));
		}
	}
	else
	{
		while ((*(*lst_a))->index != index)
		{
			ft_printf("rra\n");
			ft_reverse_rotate(&((*(*data))->lst_a));
		}
	}
}

void	sort_loop(t_data **data)
{
	int	i;
	int	len;

	len = (*data)->len_a;
	i = 1;
	while (len - i >= 3)
	{
		rotate_a(&data, (*data)->len_a, i);
		ft_push(&((*data)->lst_b), &((*data)->lst_a));
		ft_printf("pb\n");
		i++;
	}
	if ((*data)->len_a >= 3)
		check_order(&data, *((*data)->lst_a), (*data)->len_a);
	else
		ft_swap(&((*data)->lst_a));
	while (i > 1)
	{
		ft_push(&((*data)->lst_a), &((*data)->lst_b));
		ft_printf("pa\n");
		i--;
	}
}
