/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:05:09 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/27 10:51:57 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lst_addback(t_stack *lst, t_stack *new_node)
{
	t_stack	*ptr;

	while (lst->next != NULL)
	{
		ptr = lst;
		lst = ptr->next;
	}
	lst->next = new_node;
}

static t_stack	*lst_new_node_add(t_stack *lst, char *n)
{
	t_stack	*new_node;
	int		nbr;

	nbr = ft_atoi(n);
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
	{
		free(new_node);
		free_lst(&lst);
		return (NULL);
	}
	new_node->nbr = nbr;
	new_node->direction = 0;
	new_node->operations = 0;
	new_node->next = NULL;
	if (!lst)
		return (new_node);
	else
		lst_addback(lst, new_node);
	return (lst);
}

t_stack	*create_list(int argc, char **argv)
{
	t_stack	*lst;
	char	**array;
	int		i;

	i = 1;
	lst = NULL;
	if (argc > 2)
	{
		while (i < argc)
		{
			lst = lst_new_node_add(lst, argv[i]);
			i++;
		}
	}
	else if (argc == 2)
	{
		array = ft_split(argv[1], ' ');
		i = 0;
		while (array[i] != NULL)
		{
			lst = lst_new_node_add(lst, array[i]);
			i++;
		}
	}
	return (lst);
}
