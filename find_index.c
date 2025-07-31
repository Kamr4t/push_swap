/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 09:42:03 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/31 20:27:11 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_array(int *array, int nbr, int i, int used_slots)
{
	int	j;
	int	tmp;

	j = 0;
	while (i + j < used_slots)
	{
		tmp = array[i + j];
		array[i + j] = nbr;
		nbr = tmp;
		j++;
	}
	array[i + j] = nbr;
}

static void	insert_array(int *array, int nbr)
{
	int			i;
	static int	used_slots = 0;

	i = 0;
	while (i < used_slots)
	{
		if (nbr < array[i])
		{
			move_array(array, nbr, i, used_slots);
			used_slots++;
			return ;
		}
		i++;
	}
	used_slots++;
	array[i] = nbr;
}

static int	*sort_array(t_stack *lst, int lst_len)
{
	int		*array;

	array = ft_calloc(lst_len, sizeof(int));
	if (!array)
		return (NULL);
	while (lst)
	{
		insert_array(array, lst->nbr);
		lst = lst->next;
	}
	return (array);
}

static void	fill_index(t_stack ***lst, int *array, int len)
{
	t_stack	*tmp;
	int		i;

	tmp = **lst;
	while (tmp)
	{
		i = 0;
		while (i < len)
		{
			if (tmp->nbr == array[i])
			{
				tmp->index = i + 1;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	find_index(t_data **data)
{
	int	*array;

	(*data)->len_a = lst_len(*data);
	(*data)->len_b = 0;
	array = sort_array(*((*data)->lst_a), (*data)->len_a);
	if (!array)
		return ;
	fill_index(&((*data))->lst_a, array, (*data)->len_a);
	free (array);
}
