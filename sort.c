/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:55:48 by codespace         #+#    #+#             */
/*   Updated: 2025/07/18 17:28:39 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/*
postive numbers fail because i minus is done first and info stack doesnt work as intented i guess
perhaps again have different functions for negative and positive
while loop needs a stop point
needs to sort the b stack after getting all numbers sorted by first digit
new array for count of same first digits per digit count????
doesnt make sense
*/

void	ft_sort_by_first_nbr(t_data ***data, int i, int j)
{
	stack	***lst_a;
	int		index;
	int		test;

	test = 0;
	lst_a = &(*(*data))->lst_a;
	while (test < 100)
	{
		test++;
		if ((*(*lst_a))->digit_count == (j + 1))
		{
			index = 1;
			while (index < 10)
			{
				if ((*(*lst_a))->first_digit == index)
				{
					(*(*data))->len_b++;
					ft_push((&(*(*data))->lst_b), (&(*(*data))->lst_a));
					(*(*data))->info_array[i][j]--;
				}
				index++;
			}
		}
		else
			ft_reverse_rotate(&(*(*data))->lst_a);
	}
}

/*
if array > 10
	while ((*(*data))->info_array[i][j] > 0)
		if ((*(*lst_a))->digit_count == (j + 1))
			while intex > 0 or whatever
				if (*(*lst_a))->first_digit == sort
					push and etc
		else
			reverse rotate
*/


//add check for minus and plus
void ft_sort_by_digit(t_data **data, int i, int j)
{
	//change later for cleaner code, not 2 functions that almost do the same
	//just split negative and postive numbers
	stack	***lst_a;

	lst_a = &(*data)->lst_a;
	if ((*data)->info_array[i][j] > 10)
		ft_sort_by_first_nbr(&data, i, j);
	else
	{
		while ((*data)->info_array[i][j] > 0)
		{
			if ((*(*lst_a))->digit_count == (j + 1) && (*(*lst_a))->nbr >= 0)
			{
				(*data)->len_b++;
				ft_push((&(*data)->lst_b), (&(*data)->lst_a));
				(*data)->info_array[i][j]--;
			}
			else
				ft_reverse_rotate(&(*data)->lst_a);
		}
	}
}

void ft_sort_by_digit_n(t_data **data, int i, int j)
{
	//change later for cleaner code, not 2 functions that almost do the same
	//just split negative and postive numbers
	stack	***lst_a;

	lst_a = &(*data)->lst_a;
	if ((*data)->info_array[i][j] > 10)
		ft_sort_by_first_nbr(&data, i, j);
	else
	{
		while ((*data)->info_array[i][j] > 0)
		{
			if ((*(*lst_a))->digit_count == (j + 1) && (*(*lst_a))->nbr < 0)
			{
				(*data)->len_b++;
				ft_push((&(*data)->lst_b), (&(*data)->lst_a));
				(*data)->info_array[i][j]--;
			}
			else
				ft_reverse_rotate(&(*data)->lst_a);
		}
	}
}

void	ft_sort_loop(t_data *data)
{
	int	i;

	i = 9;
	while (i >= 0)
	{
		if (data->info_array[1][i] > 0)
		{
 			ft_sort_by_digit(&data, 1 , i);
			ft_sort_stack_b(&data);
			ft_push_b_to_a(&data);
		}
		i--;
	}
	i = 0;
	while (i <= 9)
	{
		if (data->info_array[0][i] > 0)
		{
			ft_sort_by_digit_n(&data, 0 , i);
			ft_sort_stack_b(&data);
			ft_push_b_to_a(&data);
		}
		i++;
	}
}

