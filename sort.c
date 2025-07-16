/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:55:48 by codespace         #+#    #+#             */
/*   Updated: 2025/07/16 15:36:33 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_size(stack *lst)
{
	int		count;
	stack	*ptr;

	count = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}

void	ft_sort_by_first_nbr(t_data ***data)
{
	(void)data;
	ft_printf("sort by first nbr\n");
}

void	ft_sort_by_digit(t_data **data, int i, int j)
{
	stack	***lst_a;
	stack	***lst_b;

	lst_a = &(*data)->lst_a;
	lst_b = &(*data)->lst_b;
	if ((*data)->info_array[i][j] > 10)
		ft_sort_by_first_nbr(&data);
	else
	{
		//ft_printf("sort by digit\n");
		while ((*data)->info_array[i][j] > 0)
		{
			if ((*(*lst_a))->digit_count == (j + 1))
			{
				if (!**lst_b || (**lst_a)->nbr > (**lst_b)->nbr)
				{
					(*data)->len_b++;
					ft_push((&(*data)->lst_b), (&(*data)->lst_a));
				}
				else
				{
					(*data)->len_b++;
					ft_push((&(*data)->lst_b), (&(*data)->lst_a));
					ft_rotate((&(*data)->lst_b));
				}
				(*data)->info_array[i][j]--;
			}
			else
			{
				ft_reverse_rotate(&(*data)->lst_a);
			}
		}
	}
}

void	ft_sort_stack_b(t_data **data)
{
	stack	**lst_b;
	stack	*second;

	lst_b = (*data)->lst_b;
	second = (*lst_b)->next;
	if ((*data)->len_b > 1)
	{
		while (is_sorted_b(data))
		{
			/* code */
		}
		
	}
	else
	{
		ft_push((&(*data)->lst_a), (&(*data)->lst_b));
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
		}
		i--;
	}
	i = 9;
	while (i <= 9)
	{
		if (data->info_array[0][i] > 0)
		{
			ft_sort_by_digit(&data, 0 , i);
		}
		i++;
	}
}

