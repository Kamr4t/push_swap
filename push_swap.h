/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:35:34 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/10 14:44:35 by ancamara         ###   ########.fr       */
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
void	ft_swap(stack **lst);
void	ft_push(stack **lst_dest, stack **lst_source);
void	ft_rotate(stack **lst);
void	ft_reverse_rotate(stack **lst);

//sort
int		operation_counter(void);
int		ft_sort_loop(stack *lst_a, stack *lst_b, int **info);
int		**add_info(stack *lst);
void	ft_sort_digit_count(stack **lst_a, stack **lst_b, int *info, int position);

//helper
void	ft_lst_print_nbr(stack *lst);
