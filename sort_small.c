/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:50:58 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/28 18:03:13 by ancamara         ###   ########.fr       */
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

static int	next_index_pos(t_stack *lst, int next_index)
{
	int	pos;

	pos = 0;
	while (lst->index != next_index)
	{
		lst = lst->next;
		pos++;
	}
	return (pos);
}

void	sort_small(t_data **data, int *array)
{
	t_stack	*lst;

	lst = *(*data)->lst_a;

	while ()
	{
		
	}
}
