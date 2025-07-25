/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:12:17 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/26 16:39:21 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//./push_swap $(shuf -i 1-50 -n 50)
// for testing with random numbers

#include "push_swap.h"

void	ft_lst_print_nbr(t_stack **lst, char *lst_name)
{
	t_stack	*tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	ft_printf("%s\n", lst_name);
	while (tmp)
	{
		ft_printf("Nbr:   %d\n", tmp->nbr);
		ft_printf("index: %d\n", tmp->index);
		tmp = tmp->next;
	}
	ft_printf("==========\n");
}

// void	ft_print_array(int *array, int len)
// {
// 	ft_printf("Array for -digits: ");
// 	for (int i = 0; i < len; i++)
// 	{
// 		ft_printf("%d, ", array[i]);
// 	}
// 	ft_printf("\n");
// }

int	operation_counter(void)
{
	static int	count = 0;

	count++;
	return (count);
}
