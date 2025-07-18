/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:03:34 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/18 09:43:47 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_loop(int	array[10], int nbr, int i)
{
	int	j;
	int	tmp;

	j = 0;
	while (array[i + j] != 0)
	{
		tmp = array[i + j];
		array[i + j] = nbr;
		nbr = tmp;
		j++;
	}
	array[i + j] = nbr;
}

static int	insert_array(int array[10], int nbr)
{
	int	i;

	i = 0;
	while (array[i] != nbr)
	{
		if (array[i] == 0)
		{
			array[i] = nbr;
			break ;
		}
		else if (nbr > array[i])
		{
			insert_loop(array, nbr, i);
			break ;
		}
		i++;
	}
	return (i);
}

void	insertion_sort(t_data ***data, int i)
{
	int	j;

	j = i;
	while (i > 0)
	{
		ft_swap(&(*(*data))->lst_b);
		if (i != 1)
			ft_rotate(&(*(*data))->lst_b);
		i--;
	}
	while (j > 1)
	{
		ft_reverse_rotate(&(*(*data))->lst_b);
		j--;
	}
}

//does not include 0 atm
static int	count_array(int array[10])
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 10)
	{
		if (array[i] != 0)
			count++;
		i++;
	}
	return (count);
}

void	ft_sort_stack_b(t_data **data)
{
	stack	***lst;
	int		array[10];
	int		i;

	i = 0;
	while (i < 10)
	{
		array[i] = 0;
		i++;
	}
	lst = &(*data)->lst_b;
	while ((*data)->len_b != count_array(array))
	{
		i = insert_array(array, (*(*lst))->nbr);
		if (i == 1)
			ft_swap(&(*data)->lst_b);
		else if (i > 1)
			insertion_sort(&data, i);
		else
			ft_reverse_rotate(&(*data)->lst_b);
	}
}

void	ft_push_b_to_a(t_data **data)
{
	static int	count = 0;
	stack		***a;
	stack		***b;
	int			i;

	a = &(*data)->lst_a;
	b = &(*data)->lst_b;
	if (count != 0)
	{
		while ((*(*a))->nbr != count)
			ft_rotate(&(*data)->lst_a);
	}
	i = 0;
	while (i < (*data)->len_b)
	{
		ft_push(&(*data)->lst_a, &(*data)->lst_b);
		i++;
	}
	count = (*(*a))->nbr;
	(*data)->len_b = 0;
}
