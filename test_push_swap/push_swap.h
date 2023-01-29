/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:59:21 by dbaule            #+#    #+#             */
/*   Updated: 2023/01/26 18:28:48 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include <unistd.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

struct s_numbers_list
{
	int	*array_a;
	int	count;
	int	*array_b;

}	typedef	a_b_list;

struct s_linked_list_a
{
	int value;
	int	count_a;
	struct s_linked_list_a *next;
}typedef a_list;

a_list	*ft_lst_new(int content);
a_list	*ft_lst_last(a_list *lst);
void	ft_lstadd(a_list **lst, a_list *new);
a_list	*linked_list_initialise(a_b_list elem);
void	ft_lst_add_front(a_list **lst, a_list *new);



void	instruct_sa(int a);
char	*join_numbers(char **argv);
int		verif(char **argv);
int		count_numbers(char **buf);
int		error_overflow(char *numbers);
int		check_duplicate(a_b_list array);
a_list	*linked_list_initialise(a_b_list elem);


void	sa_instruct(a_list *lst, a_list *new);
void	ss_instruct(a_list *array);
void	ra_instruct(a_list **lst);
void	rra_instruct(a_list **lst);

void	sb_instruct(a_list **lst);

#endif