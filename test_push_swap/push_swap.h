/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:59:21 by dbaule            #+#    #+#             */
/*   Updated: 2023/01/19 17:22:12 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include <unistd.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>

struct s_numbers_list
{
	int		content;
	int		count;
	struct s_numbers_list *next;

}	typedef	a_b_list;

struct s_List
{
    int	value;
	struct s_List *next;
}	typedef chain_list;

void	instruct_sa(int a);
char	*join_numbers(char **argv);
int		verif(char **argv);
int		count_numbers(char **buf);
int		error_overflow(char *numbers);
int		check_duplicate(a_b_list array);

#endif