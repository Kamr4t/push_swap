/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:25:19 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/25 12:34:23 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	lst_len(t_data *data)
{
	int		i;
	stack	*lst;

	i = 0;
	lst = *(data->lst_a);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	is_sorted(stack *lst)
{
	int	tmp;

	tmp = lst->nbr;
	lst = lst->next;
	while (lst)
	{
		if (tmp > lst->nbr)
			return (0);
		tmp = lst->nbr;
		lst = lst->next;
	}
	return (1);
}

//lst_member
// 0 = nbr
// 1 = index
// 2 = operations
int	node_pos(stack *lst, int value, int lst_member)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	if (lst_member == 0)
		while (lst && lst->nbr != value)
		{
			lst = lst->next;
			i++;
		}
	else if (lst_member == 1)
		while (lst && lst->index != value)
		{
			lst = lst->next;
			i++;
		}
	else if (lst_member == 2)
		while (lst && lst->operations != value)
		{
			lst = lst->next;
			i++;
		}
	return (i);
}

int	find_next_index(int *array, int index, int lst_len)
{
	int			i;
	int			next_index;
	bool		is_zero;

	i = 0;
	next_index = 0;
	is_zero = false;
	while (i < lst_len + 1)
	{
		if (index >= array[i])
		{
			next_index = array[i];
			is_zero = true;
			break ;
		}
		i++;
	}
	if (next_index == 0 && !is_zero)
		return (array[0]);
	return (next_index);
}
