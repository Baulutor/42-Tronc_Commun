/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:59:21 by dbaule            #+#    #+#             */
/*   Updated: 2023/05/16 16:45:17 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_numbers_list
{
	int	*array_a;
	int	count;
}	t_a_b_list;

typedef struct s_stacks
{
	int				value;
	int				count;
	int				index;
	int				print;
	struct s_stacks	*next;
}	t_stacks;

void		ft_lstadd(t_stacks **lst, t_stacks *new);
t_stacks	*linked_list_initialise(t_a_b_list elem);
void		ft_lst_add_front(t_stacks **lst, t_stacks *new);

char		*join_numbers(char **argv);
int			count_numbers(char **buf);
int			error_overflow(char *numbers);
int			atoi_test(size_t y, size_t index, char *numbers);
int			int_condition(char **argv, int x, int y);
t_a_b_list	stacks_a(char *numbers);
t_stacks	*linked_list_initialise(t_a_b_list elem);
t_stacks	*error_check_and_initialize(char **argv);

void		sa_instruct(t_stacks **lst);
void		ra_instruct(t_stacks **lst);
void		rra_instruct(t_stacks **lst);
void		pa_instruct(t_stacks **lst_a, t_stacks **lst_b);

void		sb_instruct(t_stacks **lst);
void		pb_instruct(t_stacks **lst_a, t_stacks **stack_b);
void		rb_instruct(t_stacks **lst);
void		rrb_instruct(t_stacks **lst);

void		ss_instruct(t_stacks **lst_a, t_stacks **lst_b);
void		rr_instruct(t_stacks **lst_a, t_stacks **lst_b);
void		rrr_instruct(t_stacks **lst_a, t_stacks **lst_b);

void		organize_index(t_stacks *stack);
void		sorting_stack(t_stacks **stack_a, t_stacks **stack_b);
void		sorting_three_numbers_initialise(t_stacks **stack_a);
void		sorting_four_numbers(t_stacks **stack_a, t_stacks **stack_b, int z);
void		sorting_five_numbers(t_stacks **stack_a, t_stacks **stack_b);
void		sorting_small_stack(t_stacks **stack_a, t_stacks **stack_b);

void		ft_free_all(t_stacks **lst_a);
void		ft_free_buf(char **buf);

t_stacks	*init_print(t_stacks **stack_a);

#endif