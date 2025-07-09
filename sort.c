/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:55:48 by codespace         #+#    #+#             */
/*   Updated: 2025/07/09 11:21:20 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operation_counter(void)
{
	static int	count = 0;

	count++;
	return (count);
}

void	add_info(stack *lst)
{
	int		tmp_nbr;
	int		i;
	int		*info_array;

	while (lst->next != NULL)
	{
		i = 0;
		tmp_nbr = lst->nbr;
		while (tmp_nbr != 0)
		{
			lst->first_digit = tmp_nbr % 10;
			tmp_nbr /= 10;
			i++;
		}
		lst->digit_count = i;
		lst = lst->next;
	}
}

