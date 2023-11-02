/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:24:40 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/27 14:59:24 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECHO_H
# define ECHO_H

typedef struct t_echo
{
	int	i;
	int	j;
	int	flag;
	int	type_flag;
}	t_echo;

void	init_echo(t_echo *e);

void	echo_quote(t_echo *e, char **arg);

void	echo_quote_bis(t_echo *e, char **arg);

void	echo_quote_bis_bis(t_echo *e, char **arg);

#endif