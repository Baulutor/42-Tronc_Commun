/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:16:58 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/27 14:47:55 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_REDIRECTION_H
# define CHECK_REDIRECTION_H

typedef struct t_red
{
	char	**tmp;
	int		file;
	int		compt;
	int		i;
	int		j;
	char	**buf;
}	t_red;

typedef struct t_write_hd
{
	int		i;
	int		compt;
	char	*tmp;
}	t_write_hd;

int	duplication(t_red *r, char **arg, t_cmd *s);

int	write_hd_to_pip(t_cmd *struc);

int	redir_in_bis(t_red *r, char **arg);

int	redit_append_bis(t_red *r, char **arg);

int	redir_out_bis(t_red *r, char **arg);

#endif
