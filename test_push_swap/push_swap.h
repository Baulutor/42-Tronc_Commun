/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:59:21 by dbaule            #+#    #+#             */
/*   Updated: 2023/01/24 18:26:03 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include <unistd.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>

struct s_numbers_list
{
	int	*array_a;
	int	count;
	int	*array_b;

}	typedef	a_b_list;

struct s_linked_list
{
	int value;
	struct s_linked_list *next;
}typedef list;

void	instruct_sa(int a);
char	*join_numbers(char **argv);
int		verif(char **argv);
int		count_numbers(char **buf);
int		error_overflow(char *numbers);
int		check_duplicate(a_b_list array);
list	*linked_list_initialise(a_b_list elem);

#endif