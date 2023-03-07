/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:59:21 by dbaule            #+#    #+#             */
/*   Updated: 2023/03/07 17:52:03 by dbaule           ###   ########.fr       */
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

typedef struct s_stacks
{
	int				value;
	int				count;
	int				index;
	struct s_stacks	*next;
}	t_stacks;

t_stacks	*ft_lst_new(int content);
t_stacks	*ft_lst_last(t_stacks *lst);
void		ft_lstadd(t_stacks **lst, t_stacks *new);
t_stacks	*linked_list_initialise(t_a_b_list elem);
void		ft_lst_add_front(t_stacks **lst, t_stacks *new);

void		instruct_sa(int a);
char		*join_numbers(char **argv);
int			verif(char **argv);
int			count_numbers(char **buf);
int			error_overflow(char *numbers);
int			atoi_test(size_t y, size_t index, char *numbers);
int			int_condition(char **argv, int x, int y);
int			check_duplicate(t_a_b_list array);
t_a_b_list	stacks_a(char *numbers);
t_stacks	*error_check_and_initialize(char **argv);
t_stacks	*linked_list_initialise(t_a_b_list elem);

void		sa_instruct(t_stacks **lst);
void		ss_instruct(t_stacks **lst_a, t_stacks **lst_b);
void		ra_instruct(t_stacks **lst);
void		rra_instruct(t_stacks **lst);
void		pa_instruct(t_stacks **lst_a, t_stacks **lst_b);

void		sb_instruct(t_stacks **lst);
void		pb_instruct(t_stacks **lst_a, t_stacks **stack_b);
void		rb_instruct(t_stacks **lst);
void		rr_instruct(t_stacks **lst_a, t_stacks **lst_b);
void		rrb_instruct(t_stacks **lst);
void		rrr_instruct(t_stacks **lst_a, t_stacks **lst_b);

void		ft_free_all(t_stacks **lst_a);
void		ft_free_buf(char **buf);

void		organize_index(t_stacks *stack);
void		sorting_stack(t_stacks **stack_a, t_stacks **stack_b);
void		sorting_two_numbers(t_stacks **lst_a);
void		sorting_three_numbers_initialise(t_stacks **stack_a);
void		sorting_four_numbers(t_stacks **stack_a, t_stacks **stack_b, int z);
void		sorting_five_numbers(t_stacks **stack_a, t_stacks **stack_b);

void		sorting_small_stack(t_stacks **stack_a, t_stacks **stack_b);

#endif