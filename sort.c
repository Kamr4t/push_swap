/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:11:50 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/23 17:05:01 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//while lst look for least operation count
//if first in lst a push to b
//else
//write function that returns best rotation way for a and b
//use operation handler? that rotate do needed position and both if needed
//rotate und both nodes in position

static int	find_least_op(stack *lst)
{
	int		least_op;
	int		i;

	least_op = lst->operations;
	while (lst)
	{
		if (least_op < lst->operations)
			least_op = lst->operations;
		lst = lst->next;
	}
	return (least_op);
}

static int	node_best_rotate(t_data **data, int pos_a, int pos_b)
{
	int	len_a;
	int	len_b;
	int	results[4];
	int	i;

	len_a = (*data)->len_a;
	len_b = (*data)->len_b;
	results[0] = pos_a - pos_b;
	results[1] = pos_a - (pos_b - len_b);
	results[2] = (pos_a  - len_a) - pos_b;
	results[3] = (pos_a  - len_a) - (pos_b - len_b);
	i = 0;
	while (i < 4)
	{
		if (results[i] < 0)
			results[i] = - results[i];
		if (results[i] == least_operations(pos_a, len_a, pos_a, len_b))
			break ;
		i++;
	}
	return (i);
}

static void	node_move(t_data **data, int *array)
{
	stack	*lst;
	int		pos_a;
	int		pos_b;
	int		next_index;
	int		best_rotate;

	lst = *((*data)->lst_a);
	lst = *((*data)->lst_a);
	pos_a = 0;
	while (lst->operations != find_least_op(*((*data)->lst_a)));
	{
		lst = lst->next;
		pos_a++;
	}
	next_index = find_next_index(array, lst->index);
	pos_b = node_pos(*((*data)->lst_b), next_index, 1);
	best_rotate = node_best_rotate(data, pos_a, pos_b);
	if (best_rotate == 0)
		handler_both_r(&data);
	else if (best_rotate == 1)
		handler_a_r_b_rr(&data);
	else if (best_rotate == 2)
		handler_a_rr_b_r(&data);
	else
		handler_both_rr(&data);
}
//write function for filling the array
//rotate(handler)

void	main_sort(t_data *data)
{
	int		*array;
	//int		next_index;
	stack	*lst_a;

	lst_a = *(data->lst_a);
	array = ft_calloc(data->len_a, sizeof(int));
	if (!array)
		return ;
	while (data->len_a > 0)
	{
		add_operation_count(&data, array);
		//ft_push(&(data->lst_b), &(data)->lst_a);
		
		// next_index = find_next_index(array, lst_a->index);
		// rotate_to_index(&data, next_index);
		// ft_push(&(data->lst_b), &(data)->lst_a);
		data->len_a--;
		lst_a = *(data->lst_a);
		break ;
	}
}
