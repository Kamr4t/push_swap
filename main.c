/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:34:10 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/09 10:58:01 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	stack	*lst_a;

	if (argc < 2)
	{
		ft_printf("Inavalid Arguments!", argc);
		return (0);
	}
	else
		lst_a = create_list(argc, argv);
	add_info(lst_a);
	while (lst_a->next != NULL)
	{
		ft_printf("Number: %d\ndigit count: %d\nFirst Number: %d\n", lst_a->nbr, lst_a->digit_count, lst_a->first_digit);
		lst_a = lst_a->next;
	}
	return (0);
}
