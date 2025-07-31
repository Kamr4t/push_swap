/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:25:19 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/31 20:17:13 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi_long(const char *nptr)
{
	size_t		i;
	int			n;
	long long	nbr;

	i = 0;
	n = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			n = -1;
		i++;
	}
	nbr = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		i++;
	}
	return (nbr * n);
}

bool	check_int(long long nbr)
{
	if (nbr > INT_MAX)
		return (false);
	if (nbr < INT_MIN)
		return (false);
	return (true);
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
