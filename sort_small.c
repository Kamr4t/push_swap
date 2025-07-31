/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:50:58 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/28 18:35:40 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	next_index_pos(t_stack *lst, int index, int len)
{
	int	pos;
	int	next_index;

	pos = 1;
	if (index == len)
		nexT_index = 1;
	else
		next_index = index + 1;
	lst = lst->next;
	if (lst->index == index - 1)
		return (0);
	if (index == 1 && lst->index == len)
		return (0);
	while (lst->index != next_index)
	{
		lst = lst->next;
		pos++;
	}
	return (pos);
}

static int	node_wrong_pos(t_data *data, int len)
{
	t_stack	*lst;
	int		index;

	lst = ;
	if (lst->index != 1)
		return (lst->index);
	while (lst)
	{
		index = lst->index;
		lst = lst->next;
		if (!lst)
			return (0);
		if (index == len)
			if (lst->index != 1)
				return (index);
		else
			if (index + 1 != lst->index)
				return (index);
	}
	return (0);
}

//use rotate handler??
static void	rotate_a(t_stack *lst, int len, int pos)
{
	if (pos < len / 2)
	{
		while()
		{
			ft_rotate();
		}
	}
	else
	{
		while()
		{
			ft_reverse_rotate();
		}
	}
}

static void	later()
{
	int	index_to_move;

	while ()
	{
		index_to_move = node_wrong_pos();
		if (!index_to_move)
			return ;
		if (next_index_pos()) == 0 || next_index_pos() == 2)
		{
			ft_swap();
		}
		else
		{
			ft_push(to b);
			rotate_a();
			ft_push(to a);
		}
	}
}

void	sort_small(t_data **data)
{
	int	len;

	later();
	rotate_a();
}
