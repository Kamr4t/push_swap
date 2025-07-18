/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:55:48 by codespace         #+#    #+#             */
/*   Updated: 2025/07/18 15:22:08 by ancamara         ###   ########.fr       */
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

void	ft_sort_by_first_nbr(t_data ***data)
{
	(void)data;
	// int		index;
	// int		check;
	// stack	***lst;

	// lst = &(*(*data))->lst_a;
	// index = 1;
	// while ((*(*data))->info_array[i][j] > 0)
	// {
	// 	if ((*(*lst))->digit_count == (j + 1) && (*(*data))->info_array[i][j] <= power_of(index))
	// 	{
	// 		check = 1;
	// 		while (check <= index && check_digit((*(*lst))->nbr, check))
	// 		{
	// 			check++;
	// 		}
	// 	}
	// 	(*(*data))->info_array[i][j]--; //correct position?
	// 	index++;
	// }
}

/*
while (i < digit position to check && check true)
 function ()
  if (digit position = needed number to sort)
  	return true
  else
   return false
   i++;
if (i == digit count)
	move to b

*/

//add check for minus and plus
void ft_sort_by_digit(t_data **data, int i, int j)
{
	stack	***lst_a;

	lst_a = &(*data)->lst_a;
	if ((*data)->info_array[i][j] > 10)
		ft_sort_by_first_nbr(&data);
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
	stack	***lst_b;

	lst_a = &(*data)->lst_a;
	lst_b = &(*data)->lst_b;
	if ((*data)->info_array[i][j] > 10)
		ft_sort_by_first_nbr(&data);
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

