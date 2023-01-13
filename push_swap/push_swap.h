/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:59:21 by dbaule            #+#    #+#             */
/*   Updated: 2023/01/13 15:33:56 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H

#include <unistd.h>
#include "libft/libft.h"
#include <stdio.h>

void	instruct_sa(int a);
char	*join_numbers(char **argv);
int	verif(char **argv);
int count_numbers(char **buf);
int ft_strlen_double(char **argv);


# endif