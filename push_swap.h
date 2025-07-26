/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:35:34 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/26 16:37:34 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/printf/ft_printf.h"
#include <stdlib.h>
#include <stdbool.h>

//direction:
// 0 = both r
// 1 = a r / b rr
// 2 = a rr / b r
// 3 = both rr
typedef struct t_stack {
	int				nbr;
	int				index;
	int				operations;
	int				direction;
	struct t_stack	*next;
}	t_stack;

typedef struct s_data {
	t_stack	**lst_a;
	int		len_a;
	t_stack	**lst_b;
	int		len_b;
}	t_data;

//main			1
int		main(int argc, char **argv);

//operation handler
void	handler_both_r(t_data ***data, int index, int next_index);
void	handler_a_r_b_rr(t_data ***data, int index, int next_index);
void	handler_a_rr_b_r(t_data ***data, int index, int next_index);
void	handler_both_rr(t_data ***data, int index, int next_index);

//debugging		2
void	ft_lst_print_nbr(t_stack **lst, char *lst_name);
void	ft_print_array(int *array, int len);
int		operation_counter(void);

//create list	3
t_stack	*create_list(int argc, char **argv);

//helper		2
int		is_sorted(t_stack *lst);
int		lst_len(t_data *data);
int		node_pos(t_stack *lst, int value, int lst_member);
int		find_next_index(int *array, int index, int lst_len);

//find index
void	find_index(t_data *data);

//operations
void	ft_push(t_stack ***lst_dest, t_stack ***lst_source);
void	ft_rotate(t_stack ***lst);
void	ft_reverse_rotate(t_stack ***lst);

//sort
void	main_sort(t_data *data);

//operation count
void	add_operation_count(t_data **data, int *array);
