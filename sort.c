/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:11:50 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/20 15:10:28 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_array_b(int *array, int index)
{
	
}

static int	find_next_index(int *array, int index, int used_slots)
{
	int	i;

	i = 0;
	//old move array didnt work and broke the code
	//create new function to fill array b with index in correct order
	ft_print_array(array, 10);
	while (i < used_slots)
	{
		if (index < array[i] && i > 0)
			return (array[i - 1]);
		else if (index < array[i] && i == 0)
			return (array[i]);
		i++;
	}
	return (array[0]);
}

void	main_sort(t_data *data)
{
	int		*array;
	int		i;
	int		used_slots;
	stack	*lst_a;
	stack	*lst_b;

	array = ft_calloc(data->len_a, sizeof(int));
	if (!array)
		return ;
	//rework later
	ft_push(&(data->lst_b), &(data->lst_a));
	lst_a = *(data->lst_a);
	lst_b = *(data->lst_b);
	array[0] = lst_b->index;
	used_slots = 1;
	while (used_slots < data->len_a)
	{
		i = find_next_index(array, lst_a->index, used_slots);
		while (lst_b && lst_b->index != i)
		{
			ft_rotate(&(data->lst_b));
			lst_b = *(data->lst_b);
		}
		ft_push(&(data->lst_b), &(data->lst_a));
		lst_a = *(data->lst_a);
		used_slots++;
	}
}
