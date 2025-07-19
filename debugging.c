/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:12:17 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/19 17:14:13 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_print_nbr(stack **lst, char *lst_name)
{
	stack	*tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	ft_printf("%s\n", lst_name);
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
