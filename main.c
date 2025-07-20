/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:34:10 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/20 12:16:42 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	stack	*lst_a;
	stack	*lst_b;
	t_data	data;
	
	lst_b = NULL;
	if (argc < 2)
		return (0);
	else
		lst_a = create_list(argc, argv);
	if (is_sorted(lst_a))
		return (0);
	data.lst_a = &lst_a;
	data.lst_b = &lst_b;
	find_index(&data);
	main_sort(&data);
	ft_lst_print_nbr(data.lst_b, "List B");
	ft_printf("Operations: %d\n", operation_counter() - 1);

	return (0);
}
