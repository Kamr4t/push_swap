/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:35:34 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/09 11:13:30 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/printf/ft_printf.h"
#include <stdlib.h>

typedef struct	stack {
	int				nbr;
	int				digit_count;
	int				first_digit;
	struct stack	*next;
} stack;

//main
int		main(int argc, char **argv);

//create stack
stack	*create_list(int argc, char **argv);

//opeartions1
void	ft_swap(stack *lst);
void	ft_push(stack **lst_dest, stack **lst_source);
void	ft_rotate(stack **lst);
void	ft_reverse_rotate(stack **lst);

//sort
int		operation_counter(void);
void	add_info(stack *lst);
