/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:34:10 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/09 11:57:11 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	stack	*lst_a;
	stack	*lst_b;
	int		*info_array;
	int		i;
	int		test;

	if (argc < 2)
	{
		ft_printf("Inavalid Arguments!", argc);
		return (0);
	}
	else
		lst_a = create_list(argc, argv);
	info_array = add_info(lst_a);
	// while (lst_a->next != NULL)
	// {
	// 	ft_printf("Number: %d\ndigit count: %d\nFirst Number: %d\n", lst_a->nbr, lst_a->digit_count, lst_a->first_digit);
	// 	lst_a = lst_a->next;
	// }
	i = 0;
	while (info_array[i] != 0 && i < 10)
		i++;
	if (lst_a->digit_count == (i + 1) && lst_a->nbr > 0)
	{
		ft_push(&lst_b, &lst_a);
		ft_rotate
		test = operation_counter();
	}
	lst_a = lst_a->next;
	ft_printf("%d\n", test);
	return (0);
}
