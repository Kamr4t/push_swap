/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:34:10 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/06 14:55:57 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_addback(stack *lst, stack *new_node)
{
	stack	*ptr;

	
	while (lst->next != NULL)
	{
		ptr = lst;
		lst = ptr->next;
	}
	lst->next = new_node;
}

stack	*lst_test(stack *lst, char *n)
{
	stack	*new_node;
	int		nbr;

	nbr = ft_atoi(n);
	new_node = malloc(sizeof(stack));
	new_node->nbr = nbr;
	new_node->next = NULL;
	if (!lst)
		return (new_node);
	else
		ft_lst_addback(lst, new_node);
	return (lst);
}

int	main(int argc, char **argv)
{
	stack	*lst;
	char	**array;
	int		i;
	
	i = 1;
	lst = NULL;
	if (argc > 2)
	{
		while (i < argc)
		{
			lst = lst_test(lst, argv[i]);
			i++;
		}
	}
	else if (argc == 2)
	{
		array = ft_split(argv[1], ' ');
		i = 0;
		while (array[i] != NULL)
		{
			lst = lst_test(lst, array[i]);
			i++;
		}
	}
	else
		ft_printf("Inavalid Arguments!");
	return (0);
}
