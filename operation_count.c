/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:09:49 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/23 16:02:44 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//write function to find the pos of lst a and b ++++
//write function to test all 4 combinations of rotate which is the smallest
//add return value to lst a
//check list a for smallest op count
//write helper function that returns best rotations for a and b
//+write function that controls the rotate using the helper
//	also checks after every rotate if postions are corret(while)
//	and only rotates the last if one lst is in position
//	after while loop use  ternary conditional operator???? if () ? a : b;

static void	shift_index_array(int *array, int pos, int index, int used_slots)
{
	int	tmp;

	while (pos < used_slots)
	{
		tmp = array[pos];
		array[pos] = index;
		index = tmp;
		pos++;
	}
}

int	least_operations(int a_index, int a_len, int b_index, int b_len)
{
	int	results[4];
	int	i;
	int	least;

	results[0] = a_index - b_index;
	results[1] = a_index - (b_index - b_len);
	results[2] = (a_index - a_len) - b_index;
	results[3] = (a_index - a_len) - (b_index - b_len);
	i = 1;
	least = results[0];
	while (i < 4)
	{
		if (least > results[i])
			least = results[i];
		i++;
	}
	if (least < 0)
		least = - least;
	return (least);
}

void	add_operation_count(t_data **data, int *array)
{
	stack	*lst;
	int		i;
	int		next_index;

	lst = *((*data)->lst_a);
	i = 0;
	while (lst)
	{
		next_index = find_next_index(array, lst->index);
		lst->operations = least_operations(i, (*data)->len_a,node_pos(*((*data)->lst_b), next_index, 1), (*data)->len_b);
		lst = lst->next;
		i++;
	}
}
