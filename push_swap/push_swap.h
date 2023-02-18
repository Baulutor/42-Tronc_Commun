/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:59:21 by dbaule            #+#    #+#             */
/*   Updated: 2023/02/18 17:03:18 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include <unistd.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef	struct s_numbers_list
{
	int	*array_a;
	int	count;
}	t_a_b_list;

typedef struct t_linked_list
{
	int value;
	int count_a;
	struct t_linked_list	*pos_b;
	struct t_linked_list	*next;
}	t_stacklist;



// typedef struct data
// {
// 	int	len_a;
// 	int	len_b;
// 	t_stack *list_a;
// 	t_stack *list_b;
// }	t_data;

// typedef struct t_list
// {
// 	int value;
// 	int	index;
// 	struct t_list *next;
// }	t_stack;

t_stacklist	*ft_lst_new(int content);
t_stacklist	*ft_lst_last(t_stacklist *lst);
void	ft_lstadd(t_stacklist **lst, t_stacklist *new);
t_stacklist	*linked_list_initialise(t_a_b_list elem);
void	ft_lst_add_front(t_stacklist **lst, t_stacklist *new);

void	ft_lst_add_front_b(t_stacklist **lst, t_stacklist *new);
t_stacklist	*ft_lst_new_b(int content);
t_stacklist	*ft_lst_last_b(t_stacklist *lst);
void	ft_lstadd_b(t_stacklist **lst, t_stacklist *new);

void	instruct_sa(int a);
char	*join_numbers(char **argv);
int		verif(char **argv);
int		count_numbers(char **buf);
int		error_overflow(char *numbers);
int		check_duplicate(t_a_b_list array);
t_a_b_list	stacks_a(char *numbers);
t_stacklist *error_check_and_initialize(char ** argv);
t_stacklist	*linked_list_initialise(t_a_b_list elem);


void	sa_instruct(t_stacklist *lst);
void	ss_instruct(t_stacklist *array);
void	ra_instruct(t_stacklist **lst);
void	rra_instruct(t_stacklist **lst);
void	pa_instruct(t_stacklist **lst_a, t_stacklist **lst_b);

void	sb_instruct(t_stacklist **lst);
void	pb_instruct(t_stacklist **lst_a, t_stacklist **lst_b);
void	rb_instruct(t_stacklist **lst);
void	rr_instruct(t_stacklist **lst_a, t_stacklist **lst_b);
void	rrb_instruct(t_stacklist **lst);
void	rrr_instruct(t_stacklist **lst_a, t_stacklist **lst_b);

#endif