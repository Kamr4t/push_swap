/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:25:19 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/20 13:18:27 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operation_counter(void)
{
	static int	count = 0;

	count++;
	return (count);
}

int	lst_len(t_data *data)
{
	int		i;
	stack	*lst;

	i = 0;
	lst = *(data->lst_a);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

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
