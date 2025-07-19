/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:35:34 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/19 17:18:58 by ancamara         ###   ########.fr       */
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


//main			1
int		main(int argc, char **argv);

//debugging		2
void	ft_lst_print_nbr(stack **lst, char *lst_name);
void	ft_print_array(int	array[2][10]);

//create list	3
stack	*create_list(int argc, char **argv);

//helper		2
int		is_sorted(stack *lst);
int		operation_counter(void);
