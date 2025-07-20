/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 09:42:03 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/20 15:07:47 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_array(int *array, int nbr, int i)
{
	int	j;
	int	tmp;

	j = 0;
	while (array[i + j] != 0)
	{
		tmp = array[i + j];
		array[i + j] = nbr;
		nbr = tmp;
		j++;
	}
	array[i + j] = nbr;
}

static void	insert_array(int *array, int nbr, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (array[i] == 0)
		{
			array[i] = nbr;
			break ;
		}
		else if (nbr < array[i])
		{
			move_array(array, nbr, i);
			break ;
		}
		i++;
	}
}

static int	*sort_array(stack *lst, int lst_len)
{
	//does not handle 0 correct
	//int	used_slots???
	int		*array;

	array = ft_calloc(lst_len, sizeof(int));
	if (!array)
		return (NULL);
	while (lst)
	{
		insert_array(array, lst->nbr, lst_len);
		lst = lst->next;
	}
	return (array);
}

static void	fill_index(stack ***lst, int *array, int len)
{
	stack	*tmp;
	int		i;

	tmp = **lst;
	while (tmp)
	{
		i = 0;
		while (i < len)
		{
			if (tmp->nbr == array[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	find_index(t_data *data)
{
	int	*array;

	data->len_a = lst_len(data);
	array = sort_array(*(data->lst_a), data->len_a);
	if (!array)
		return ;
	fill_index(&(data)->lst_a, array, data->len_a);
	free (array);
}
