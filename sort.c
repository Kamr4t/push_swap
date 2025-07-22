/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:11:50 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/22 16:17:32 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//remove 
static int	find_next_index(int *array, int index)
{
	int			i;
	int			tmp;
	int			next_index;
	static int	used_slots = 0;
	int			flag;

	i = 0;
	tmp = 0;
	next_index = 0;
	flag = 0;
	while (i < used_slots)
	{
		if (index > array[i])
		{
			next_index = array[i];
			flag = 1;
			break ;
		}
		i++;
	}
	used_slots++;
	while (i < used_slots)
	{
		tmp = array[i];
		array[i] = index;
		index = tmp;
		i++;
	}
	if (next_index == 0 && flag == 0)
		return (array[0]);
	return (next_index);
}

//rename to to the new function like operation count add
static void	add_operation_count_b(t_data **data, int index)
{
	int		i;
	stack	*lst;

	i = 0;
	lst = *((*data)->lst_b);
	if (!lst)
		return ;
	while (lst->index != index)
	{
		lst = lst->next;
		i++;
	}
	if (i < (*data)->len_b / 2)
	{
		(*(*(*data)->lst_b)).operations = i;
		(*(*(*data)->lst_b)).direction = 1;
	}
	else
	{
		(*(*(*data)->lst_b)).operations = (*data)->len_b - i;
		(*(*(*data)->lst_b)).direction = -1;
	}
}

static void	add_operation_count(t_data **data, int *array)
{
	int		i;
	stack	*lst;

	i = 0;
	lst = *((*data)->lst_a);
	while (lst)
	{
		add_operation_count_b(data, find_next_index(array, lst->index));
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
			lst = lst->next;
			i++;
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
	int		next_index;
	stack	*lst_a;

	lst_a = *(data->lst_a);
	array = ft_calloc(data->len_a, sizeof(int));
	if (!array)
		return ;
	while (data->len_a > 0)
	{
		add_operation_count(data, array);
		// next_index = find_next_index(array, lst_a->index);
		// rotate_to_index(&data, next_index);
		// ft_push(&(data->lst_b), &(data)->lst_a);
		// data->len_a--;
		// lst_a = *(data->lst_a);
	}
}
