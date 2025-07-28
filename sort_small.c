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

static void	array_fill(int *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		array[i] = i + 1;
		i++;
	}
}

static int	next_index_pos(t_stack *lst, int *array, int index, int len)
{
	int	pos;

	pos = 0;
	if (index == 1)
		index = array[len];
	else
		index++;
	while (lst->index != index)
	{
		lst = lst->next;
		pos++;
	}
	return (pos);
}

static int	node_wrong_pos(t_data data)
{
	t_stack	*lst;
	int		index;

	lst = ;
	while (lst)
	{
		index = lst->index;
		lst = lst->next;
		if (index == 1)
			if (lst->index != array[len - 1])
				return (index);
		else
			if (index + 1 != lst->index)
				return (index);
	}
	return (0);
}

static void	later()
{
	while ()
	{
		if (next_index_pos()) == 1)
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

void	sort_small(t_data **data, int *array)
{
	t_stack	*lst;
	bool	issorted;
	int		lst_sorted;

	issorted = false;
	lst = *(*data)->lst_a;
	while (!issorted)
	{
		
	}
	
}
