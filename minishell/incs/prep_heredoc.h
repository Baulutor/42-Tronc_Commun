/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_heredoc.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:00:27 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/27 16:43:01 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREP_HEREDOC_H
# define PREP_HEREDOC_H

typedef struct t_prep
{
	int		compt;
	int		i;
	int		j;
	t_cell	*tmp;
	char	*buf;
	char	*buff;
	char	*stop;
	char	*rd_line;
}	t_prep;

typedef struct t_prep_hist
{
	int		i;
	int		j;
	int		k;
	int		test_buff;
	char	*buf;
	char	*buff;
	char	*stop;
	char	*rd_line;
	char	**rdline;
	t_cell	*tmp;
	t_cell	*unt_lst;
}	t_prep_hist;

int		handle_hist(int compt, t_list *spt, t_cmd *pip);

void	search_hd(t_prep *p);

int		verif_status_hd(t_prep *p, t_cmd *pip);

#endif