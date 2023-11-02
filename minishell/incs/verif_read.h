/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_read.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:52:12 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/27 15:00:56 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERIF_READ_H
# define VERIF_READ_H

typedef struct t_verif
{
	int		flag;
	int		expand_flag;
	char	*save;
	char	*buff;
	char	*buf;
}	t_verif;

int	check_arg(t_list *spt);

int	check_expand(char *rd_line);

#endif
