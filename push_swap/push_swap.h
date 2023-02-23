/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:59:21 by dbaule            #+#    #+#             */
/*   Updated: 2023/02/23 16:52:36 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include <unistd.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_numbers_list
{
	int	*array_a;
	int	count;
}	t_a_b_list;

typedef struct s_stack
{
	int value;
	int count;
	int	index;
	struct s_stack *next;
}	s_stack;

s_stack 	*ft_lst_new(int content);
s_stack		*ft_lst_last(s_stack *lst);
void		ft_lstadd(s_stack **lst, s_stack *new);
s_stack		*linked_list_initialise(t_a_b_list elem);
void		ft_lst_add_front(s_stack **lst, s_stack *new);

// void		ft_lst_add_front_b(s_stack *lst, s_stack new);
// t_stacklist	*ft_lst_new_b(int content);
// t_stacklist	*ft_lst_last_b(s_stack lst);
// void		ft_lstadd_b(s_stack *lst, s_stack new);

void		instruct_sa(int a);
char		*join_numbers(char **argv);
int			verif(char **argv);
int			count_numbers(char **buf);
int			error_overflow(char *numbers);
int			check_duplicate(t_a_b_list array);
t_a_b_list	stacks_a(char *numbers);
s_stack 	*error_check_and_initialize(char ** argv);
s_stack		*linked_list_initialise(t_a_b_list elem);

void		sa_instruct(s_stack **lst);
void		ss_instruct(s_stack **lst_a, s_stack **lst_b);
void		ra_instruct(s_stack **lst);
void		rra_instruct(s_stack **lst);
void		pa_instruct(s_stack **lst_a, s_stack **lst_b);

void		sb_instruct(s_stack **lst);
void		pb_instruct(s_stack **lst_a, s_stack **stack_b);
void		rb_instruct(s_stack **lst);
void		rr_instruct(s_stack **lst_a, s_stack **lst_b);
void		rrb_instruct(s_stack **lst);
void		rrr_instruct(s_stack **lst_a, s_stack **lst_b);

void		ft_free_all(s_stack **lst_a, s_stack **lst_b);
void		ft_free_buf(char **buf);

void		organize_index(s_stack *stack);
s_stack		*sorting_stack(s_stack *stack_a, s_stack *stack_b);

#endif