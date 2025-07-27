/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:09:49 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/27 10:46:37 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

static int	least_operations(int pos_a, int len_a, int pos_b, int len_b)
{
	int	results[4];
	int	i;
	int	least;

	results[0] = max(pos_a, pos_b);
	results[1] = pos_a + (len_b - pos_b);
	results[2] = (len_a - pos_a) + pos_b;
	results[3] = max(len_a - pos_a, len_b - pos_b);
	i = 1;
	least = results[0];
	while (i < 4)
	{
		if (least > results[i])
			least = results[i];
		i++;
	}
	return (least);
}

static int	direction(int pos_a, int len_a, int pos_b, int len_b)
{
	int	results[4];
	int	i;
	int	least;
	int	direction;

	results[0] = max(pos_a, pos_b);
	results[1] = pos_a + (len_b - pos_b);
	results[2] = (len_a - pos_a) + pos_b;
	results[3] = max(len_a - pos_a, len_b - pos_b);
	i = 1;
	direction = 0;
	least = results[0];
	while (i < 4)
	{
		if (least > results[i])
		{
			direction = i;
			least = results[i];
		}
		i++;
	}
	return (direction);
}

void	add_operation_count(t_data **data, int *array)
{
	t_stack	*lst;
	int		pos_a;
	int		next_index;
	int		pos_b;

	lst = *((*data)->lst_a);
	pos_a = 0;
	while (lst)
	{
		next_index = find_next_index(array, lst->index, (*data)->len_b);
		pos_b = node_pos(*((*data)->lst_b), next_index, 1);
		lst->operations = least_operations
			(pos_a, (*data)->len_a, pos_b, (*data)->len_b);
		lst->direction = direction
			(pos_a, (*data)->len_a, pos_b, (*data)->len_b);
		lst = lst->next;
		pos_a++;
	}
}
