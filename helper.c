/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:25:19 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/19 11:34:36 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_print_nbr(stack **lst)
{
	stack	*tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	while (tmp->next != NULL)
	{
		ft_printf("Nbr: %d\n", tmp->nbr);
		//ft_printf("Digit Count: %d\n", tmp->digit_count);
		tmp = tmp->next;
	}
	ft_printf("Nbr: %d\n", tmp->nbr);
	//ft_printf("Digit Count: %d\n", tmp->digit_count);
}

void	ft_print_array(int	array[2][10])
{
	ft_printf("Array for -digits: ");
	for (size_t i = 0; i < 10; i++)
	{
		ft_printf("%d, ", array[0][i]);
	}
	ft_printf("\nArray for +digits: ");
	for (size_t i = 0; i < 10; i++)
	{
		ft_printf("%d, ", array[1][i]);
	}
	ft_printf("\n");
}

int	operation_counter(void)
{
	static int	count = 0;

	count++;
	return (count);
}

void	lst_len_add(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->len_a = 0;
	while (i <= 1)
	{
		j = 0;
		while (j <= 9)
		{
			data->len_a += data->info_array[i][j];
			j++;
		}
		i++;
	}
}
