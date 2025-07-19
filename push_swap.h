/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:35:34 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/19 11:34:41 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/printf/ft_printf.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct	stack {
	int				nbr;
	int				digit_count;
	int				first_digit;
	struct stack	*next;
} stack;

typedef struct s_data {
	stack	**lst_a;
	int		len_a;
	stack	**lst_b;
	int		len_b;
	int		info_array[2][10];
} t_data;


//main
int		main(int argc, char **argv);

//create stack
stack	*create_list(int argc, char **argv);

//opeartions1
void	ft_swap(stack ***lst);
void	ft_push(stack ***lst_dest, stack ***lst_source);
void	ft_rotate(stack ***lst);
void	ft_reverse_rotate(stack ***lst);

//sort
void	ft_sort_loop(t_data *data);
int		is_sorted(stack *lst);

//sort b
void	ft_sort_stack_b(t_data **data);
void	ft_push_b_to_a(t_data **data);

//helper
void	ft_lst_print_nbr(stack **lst);
void	ft_print_array(int	array[2][10]);
int		operation_counter(void);
void	lst_len_add(t_data *data);
