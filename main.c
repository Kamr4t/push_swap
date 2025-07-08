/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:34:10 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/08 16:18:01 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	stack	*lst_a;
	stack	*lst_b;

	lst_b = NULL;
	if (argc < 2)
	{
		ft_printf("Inavalid Arguments!", argc);
		return (0);
	}
	else
		lst_a = create_list(argc, argv);
	ft_swap(lst_a);
	lst_a = (lst_a, lst_b);
	while (lst_a->next != NULL)
	{
		printf("%d\n", lst_a->nbr);
		lst_a = lst_a->next;
	}
	printf("%d\n", lst_a->nbr);
	return (0);
}
