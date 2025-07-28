/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:25:19 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/28 16:58:40 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_len(t_data *data)
{
	int		i;
	t_stack	*lst;

	i = 0;
	lst = *(data->lst_a);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	is_sorted(t_stack *lst)
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
// 1 = index
// 2 = operations
int	node_pos(t_stack *lst, int value, int lst_member)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	else if (lst_member == 1)
	{
		while (lst && lst->index != value)
		{
			lst = lst->next;
			i++;
		}
	}
	else if (lst_member == 2)
	{
		while (lst && lst->operations != value)
		{
			lst = lst->next;
			i++;
		}
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

void	rotate_to_highest(t_data ***data, int direction, int last_i)
{
	t_stack	***lst;

	lst = &(*(*data))->lst_b;
	while ((*(*lst))->index != last_i)
	{
		if (direction == 0)
		{
			ft_rotate(&((*(*data))->lst_b));
			ft_printf("rb\n");
		}
		else
		{
			ft_reverse_rotate(&((*(*data))->lst_b));
			ft_printf("rrb\n");
		}
	}
}
