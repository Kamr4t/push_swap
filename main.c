/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:34:10 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/18 12:08:12 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Array for saving the number of digits
//     0   1   2   3   4   5   6   7   8   9
// 0 {-1, -2, -3, -4, -5, -6, -7 ,-8, -9,- 10}
// 1 { 1,  2,  3,  4,  5,  6,  7 , 8,  9,  10}
// each position saves how many numbers with the same amount of digits
static void	add_info(stack *lst, t_data *data)
{
	int		tmp_nbr;
	int		i;

	ft_memset((*data).info_array[0], 0, 10 * sizeof(int));
	ft_memset((*data).info_array[1], 0, 10 * sizeof(int));
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
		if (lst->first_digit < 0)
			(*data).info_array[0][i - 1]++;
		else
			(*data).info_array[1][i - 1]++;
		lst->digit_count = i;
		lst = lst->next;
	}
	i = 0;
	tmp_nbr = lst->nbr;
	while (tmp_nbr != 0)
	{
		lst->first_digit = tmp_nbr % 10;
		tmp_nbr /= 10;
		i++;
	}
	if (lst->first_digit < 0)
		(*data).info_array[0][i - 1]++;
	else
		(*data).info_array[1][i - 1]++;
	lst->digit_count = i;
	lst = lst->next;
}

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
	add_info(lst_a, &data);
	lst_len_add(&data);
	data.len_b = 0;
	ft_sort_loop(&data);
	ft_printf("list a:\n");
	ft_lst_print_nbr(data.lst_a);
	// ft_printf("list b:\n");
	// ft_lst_print_nbr(data.lst_b);
	ft_printf("Operations: %d\n", operation_counter() - 1);

	return (0);
}
