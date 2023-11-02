/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection_parent.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:22:39 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/30 10:57:45 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_REDIRECTION_PARENT_H
# define CHECK_REDIRECTION_PARENT_H

typedef struct t_red_par
{
	char	**tmp;
	int		file;
	int		compt;
	char	**buf;
}	t_red_par;

int	search_open_file(t_red_par *red, t_cmd *struc);

int	write_hd_to_pip_par(t_cmd *struc);

int	initialise_redir_parent(t_red_par *red, char **arg, t_cmd *struc);

#endif
