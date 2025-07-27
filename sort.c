/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:11:50 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/27 10:44:26 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_least_op(t_stack *lst)
{
	int		least_op;

	least_op = lst->operations;
	while (lst)
	{
		if (least_op > lst->operations)
			least_op = lst->operations;
		lst = lst->next;
	}
	return (least_op);
}

static void	shift_array(int *array, int index, int next_index, int lst_len)
{
	int	i;
	int	tmp;

	i = 0;
	while (array[i] != next_index)
		i++;
	while (i < lst_len + 1)
	{
		tmp = array[i];
		array[i] = index;
		index = tmp;
		i++;
	}
}

static void	node_move(t_data **data, int *array)
{
	t_stack	*lst_a;
	int		next_index;
	int		best_rotate;

	lst_a = *((*data)->lst_a);
	while (lst_a->operations != find_least_op(*((*data)->lst_a)))
		lst_a = lst_a->next;
	next_index = find_next_index(array, lst_a->index, (*data)->len_b);
	best_rotate = lst_a->direction;
	shift_array(array, lst_a->index, next_index, (*data)->len_b);
	if (*((*data)->lst_b) == NULL)
		return ;
	if (next_index == 0)
		next_index = array[0];
	if (best_rotate == 0)
		handler_both_r(&data, lst_a->index, next_index);
	else if (best_rotate == 1)
		handler_a_r_b_rr(&data, lst_a->index, next_index);
	else if (best_rotate == 2)
		handler_a_rr_b_r(&data, lst_a->index, next_index);
	else
		handler_both_rr(&data, lst_a->index, next_index);
}

static void	move_to_highest(t_data **data, int *array)
{
	int		last_i;
	int		pos_last;
	int		direction;
	t_stack	***lst;

	lst = &(*data)->lst_b;
	last_i = array[0];
	pos_last = node_pos(*((*data)->lst_b), last_i, 1);
	if ((*data)->len_b / 2 > pos_last)
		direction = 0;
	else
		direction = 1;
	rotate_to_highest(&data, direction, last_i);
	while ((*data)->len_b > 0)
	{
		ft_push(&((*data)->lst_a), &((*data)->lst_b));
		(*data)->len_b--;
		ft_printf("pa\n");
	}
}

void	main_sort(t_data *data)
{
	int		*array;

	array = ft_calloc(data->len_a, sizeof(int));
	if (!array)
		return ;
	while (data->len_a > 0)
	{
		add_operation_count(&data, array);
		node_move(&data, array);
		ft_push(&(data->lst_b), &(data)->lst_a);
		ft_printf("pb\n");
		data->len_a--;
		data->len_b++;
	}
	move_to_highest(&data, array);
	free (array);
}
