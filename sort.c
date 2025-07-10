/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:55:48 by codespace         #+#    #+#             */
/*   Updated: 2025/07/10 14:52:25 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operation_counter(void)
{
	static int	count = 0;

	count++;
	return (count);
}

int	**add_info(stack *lst)
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

int	ft_lst_size(stack *lst)
{
	int		count;
	stack	*ptr;

	count = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}

void	ft_move_all(stack **lst_a, stack **lst_b, int **info)
{
	int	i;
	int	j;
	int	lst_len;
	stack	*lst_a_ptr;
	stack	*lst_b_ptr;

	lst_a_ptr = *lst_a;
	lst_b_ptr = *lst_b;
	i = 9;
	j = 1;
	while(info[j][i] == 0)
	{
		i--;
		if (i < 0)
		{
			j--;
			i = 9;
		}
	}
	lst_len = ft_lst_size(lst_a_ptr);
	// j = 0;
	// while (j < lst_len)
	// {
	// 	if (lst_a_ptr->digit_count != i + 1)
	// 	{
	// 		//ft_push(&lst_b_ptr, &lst_a_ptr);
	// 		operation_counter();
	// 	}
	// 	else
	// 	{
	// 		//ft_rotate(&lst_a_ptr);
	// 		operation_counter();
	// 	}
	// 	j++;
	// }
}

void	ft_bubble_sort(stack *lst, int **info)
{
	int		i;
	int		j;
	int		position;
	stack	*tmp;

	i = 9;
	j = 1;
	while(info[j][i] == 0)
	{
		i--;
		if (i < 0)
		{
			j--;
			i = 9;
		}
	}
	tmp = NULL;

	if (lst->next == NULL)
		ft_printf("why\n");
	else
		tmp = lst->next;
	
	position = i;
	i = 0;
	//ft_printf("%d and %d\n",tmp->nbr, lst->nbr);
	// while (i < 10)
	// {
	// 	printf("test\n");
	// 	j = 0;
	// 	while (j < 10)
	// 	{
	// 		if (tmp->nbr < lst->nbr)
	// 		{
	// 			//ft_swap(&lst);
	// 			operation_counter();
	// 		}
	// 		j++;
	// 		//ft_reverse_rotate(&lst);
	// 	}
	// 	i++;
	// }
}

int	ft_sort_loop(stack *lst_a, stack *lst_b, int **info)
{
	ft_move_all(&lst_a, &lst_b, info);
	// ft_printf("lst a:\n");
	// ft_lst_print_nbr(lst_a);
	// ft_printf("lst b:\n");
	// ft_lst_print_nbr(lst_b);
	//ft_bubble_sort(lst_a, info);
	return (1);
}

