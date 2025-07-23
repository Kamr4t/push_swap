/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:11:50 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/23 11:00:41 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	find_next_index(int *array, int index, bool shift_array)
{
	int			i;
	int			next_index;
	static int	used_slots = 0;
	bool		is_zero;

	i = 0;
	next_index = 0;
	is_zero = false;
	while (i < used_slots)
	{
		if (index > array[i])
		{
			next_index = array[i];
			is_zero = true;
			break ;
		}
		i++;
	}
	used_slots++;
	if (next_index == 0 && !is_zero)
	{
		if (shift_array)
			shift_index_array(array, i, array[0], used_slots);
		return (array[0]);
	}
	if (shift_array)
		shift_index_array(array, i, index, used_slots);
	return (next_index);
}

static void	add_operation_count_b(t_data ***data, int index, int lst_a_nbr)
{
	int		i;
	stack	*lst_a;
	stack	*lst_b;

	i = 0;
	lst_a = *((***data).lst_a);
	lst_b = *((***data).lst_b);
	if (!lst_b)
		return ;
	while (lst_b->index != index)
	{
		lst_b = lst_b->next;
		i++;
	}
	while (lst_a->nbr != lst_a_nbr)
		lst_a = lst_a->next;
	if (i < (***data).len_b / 2)
	{
		if (lst_a->direction == 1)
		{
			lst_a->operations -= i;
			if (lst_a->operations < 0)
				lst_a->operations = - lst_a->operations;
		}
		else
		{
			lst_a->operations += i;
			lst_a->operations = 0;
		}
	}
	else
	{
		if (lst_a->direction == -1)
		{
			lst_a->operations -= i;
			if (lst_a->operations < 0)
				lst_a->operations = - lst_a->operations;
		}
		else
		{
			lst_a->operations += i;
			lst_a->operations = 0;
		}
	}
}

static void	add_operation_count(t_data **data, int *array)
{
	int		i;
	stack	*lst;

	i = 0;
	(void)array;
	lst = *((*data)->lst_a);
	while (lst)
	{
		if (i < (*data)->len_a / 2)
		{
			(*(*(*data)->lst_a)).operations = i;
			(*(*(*data)->lst_a)).direction = 1;
		}
		else
		{
			(*(*(*data)->lst_a)).operations = (*data)->len_a - i;
			(*(*(*data)->lst_a)).direction = -1;
		}
		add_operation_count_b(&data, find_next_index(array, lst->index, false), lst->nbr);
		lst = lst->next;
		i++;
	}
}

static void	move_node(t_data **data, int *array)
{
	stack	*lst;
	int		op_count;

	op_count = 0;
	lst = *((*data)->lst_a);
	op_count = lst->operations;
	while (lst)
	{
		lst = lst->next;
		if (op_count > lst->operations)
			op_count = lst->operations;
	}
	lst = *((*data)->lst_a);
	while (lst->operations != op_count)
		lst = lst->next;
	while ((*(*(*data)->lst_a)).index != lst->index)
	{
		if (lst->direction == 1)
	}
}

//sort function 
//add operation count to every node in b
//than add operation count to every node in a;
//than compare by adding a and b, or in case of same direction substract
//chooses lowest number(safe index of lowest operation count, while count through the lst)
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
		//ft_push(&(data->lst_b), &(data)->lst_a);
		add_operation_count(&data, array);
		// next_index = find_next_index(array, lst_a->index);
		// rotate_to_index(&data, next_index);
		// ft_push(&(data->lst_b), &(data)->lst_a);
		data->len_a--;
		lst_a = *(data->lst_a);
		break ;
	}
}
