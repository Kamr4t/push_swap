/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:34:10 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/31 20:02:34 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *lst)
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

void	free_lst(t_stack **lst)
{
	t_stack	*ptr;

	while (*lst != NULL)
	{
		ptr = *lst;
		*lst = ptr->next;
		free (ptr);
	}
	lst = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*lst_a;
	t_stack	*lst_b;
	t_data	data;

	lst_b = NULL;
	if (argc < 2)
		return (0);
	if (!is_valid(argc, argv))
	{
		ft_printf("Error!\n");
		return (0);
	}
	lst_a = create_list(argc, argv);
	if (!lst_a)
		return (0);
	if (is_sorted(lst_a))
	{
		free_lst(&lst_a);
		return (0);
	}
	data.lst_a = &lst_a;
	data.lst_b = &lst_b;
	main_sort(&data);
	free_lst(&lst_a);
	return (0);
}
