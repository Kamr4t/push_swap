/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:25:19 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/10 13:38:47 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_print_nbr(stack *lst)
{
	stack	*tmp;

	tmp = lst;
	while (tmp->next != NULL)
	{
		ft_printf("Nbr: %d\n", tmp->nbr);
		tmp = tmp->next;
	}
	ft_printf("Nbr: %d\n", tmp->nbr);
}
