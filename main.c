/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:34:10 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/10 15:52:45 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	**add_info(stack *lst)
{
	int		tmp_nbr;
	int		i;
	int		**info_array;

	info_array = malloc(2 * sizeof(int *));
	info_array[0] = malloc(10 * sizeof(int));
	ft_memset(info_array[0], 0, 10 * sizeof(int));
	info_array[1] = malloc(10 * sizeof(int));
	ft_memset(info_array[1], 0, 10 * sizeof(int));
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
			info_array[0][i - 1]++;
		else
			info_array[1][i - 1]++;
		lst->digit_count = i;
		lst = lst->next;
	}
	return (info_array);
}

static t_data *ft_store_data(stack *lst)
{
	int		**info_array;
	t_data	*data;

	info_array = add_info(lst);
	data = malloc(sizeof(t_data *));
	return (data);
}

int	main(int argc, char **argv)
{
	stack	*lst_a;
	stack	*lst_b;
	t_data	*data;
	
	int		is_sorted;
	lst_b = NULL;
	if (argc < 2)
	{
		ft_printf("Inavalid Arguments!", argc);
		return (0);
	}
	else
		lst_a = create_list(argc, argv);
	data = ft_store_data(lst_a);
	data->lst_a = &lst_a;
	data->lst_b = &lst_b;
	is_sorted = 0;
	while (is_sorted != 1)
	{
		is_sorted = ft_sort_loop(&data);
	}
	ft_printf("%d\n", operation_counter() - 1);
	return (0);
}
