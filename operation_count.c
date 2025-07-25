/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:09:49 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/25 11:24:40 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	least_operations(int pos_a, int a_len, int pos_b, int b_len)
{
	int	results[4];
	int	i;
	int	least;

	results[0] = pos_a - pos_b;
	results[1] = pos_a - (pos_b - b_len);
	results[2] = (pos_a - a_len) - pos_b;
	results[3] = (pos_a - a_len) - (pos_b - b_len);
	i = 1;
	if (results[0] < 0)
		results[0] = - results[0];
	least = results[0];
	while (i < 4)
	{
		if (results[i] < 0)
			results[i] = - results[i];
		if (least > results[i])
			least = results[i];
		i++;
	}
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
		next_index = find_next_index(array, lst->index, (*data)->len_b);
		lst->operations = least_operations(i, (*data)->len_a, node_pos(*((*data)->lst_b), next_index, 1), (*data)->len_b);
		lst = lst->next;
		i++;
	}
}
