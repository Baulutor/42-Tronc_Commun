/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:31:44 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/27 15:08:45 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_data.h"

void	following_debugger_size(t_type t)
{
	if (t == LONG_LONG_UNSIGNED)
		write(2, "LONG_LONG_UNSIGNED\n", 19);
	if (t == LIST)
		write(2, "LIST\n", 5);
	if (t == LIST_IND)
		write(2, "LIST_IND\n", 9);
	if (t == STACK)
		write(2, "STACK\n", 6);
	if (t == QUEUE)
		write(2, "QUEUE\n", 6);
	if (t == DICO)
		write(2, "DICO\n", 5);
	if (t == TREE)
		write(2, "TREE\n", 5);
	if (t == ALEA)
		write(2, "ALEA\n", 5);
}

void	debugger_size(int debug, t_type t, int mod)
{
	if (debug == 1)
	{
		if (mod == 0)
			write(2, "DEBUG MOD : fct size : type given : ", 36);
		else
		{
			if (t == INT)
				write(2, "INT\n", 4);
			if (t == CHAR)
				write(2, "CHAR\n", 5);
			if (t == STRING)
				write(2, "STRING\n", 7);
			if (t == DOUBLE)
				write(2, "DOUBLE\n", 7);
			if (t == LONG)
				write(2, "LONG\n", 5);
			if (t == UNSIGNED)
				write(2, "UNSIGNED\n", 9);
			if (t == LONG_LONG)
				write(2, "LONG_LONG\n", 10);
			if (t == LONG_UNSIGNED)
				write(2, "LONG_UNSIGNED\n", 14);
			following_debugger_size(t);
		}
	}
}

long long int	size(t_type t, int debug)
{
	debugger_size(debug, t, 0);
	debugger_size(debug, t, 1);
	if (t == INT)
		return ((long long int)(sizeof(int)));
	else if (t == CHAR)
		return ((long long int)(sizeof(char)));
	else if (t == DOUBLE)
		return ((long long int)(sizeof(double)));
	else if (t == LONG)
		return ((long long int)(sizeof(long)));
	else if (t == UNSIGNED)
		return ((long long int)(sizeof(unsigned)));
	else if (t == LONG_LONG)
		return ((long long int)(sizeof(long long)));
	else if (t == LONG_UNSIGNED)
		return ((long long int)(sizeof(long unsigned)));
	else if (t == LONG_LONG_UNSIGNED)
		return ((long long int)(sizeof(long long unsigned)));
	else
		return (-1);
}
