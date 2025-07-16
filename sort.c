/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:55:48 by codespace         #+#    #+#             */
/*   Updated: 2025/07/10 16:25:00 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operation_counter(void)
{
	static int	count = 0;

	count++;
	return (count);
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

static void	ft_move_all(t_data ***data)
{
	int	i;
	int	j;
	int	lst_len;
	stack	*lst;

	i = 9;
	j = 1;
	while((**data)->info_array[j][i] == 0)
	{
		i--;
		if (i < 0)
		{
			j--;
			i = 9;
		}
	}
	lst_len = ft_lst_size((**data)->lst_a);
	j = 0;
	while (j < lst_len)
	{
		lst = (**data)->lst_a;
		if ((lst->digit_count) != i + 1)
		{
			ft_push(&(**data)->lst_b, &(**data)->len_a);
			operation_counter();
		}
		else
		{
			ft_rotate(&(**data)->lst_a);
			operation_counter();
		}
		j++;
	}
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

int	ft_sort_loop(t_data **data)
{
	ft_move_all(&data);
	// ft_printf("lst a:\n");
	// ft_lst_print_nbr(lst_a);
	// ft_printf("lst b:\n");
	// ft_lst_print_nbr(lst_b);
	//ft_bubble_sort(lst_a, info);
	return (1);
}

