/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historic.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:58:38 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/28 17:24:38 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORIC_H
# define HISTORIC_H

typedef struct t_hist
{
	int		save;
	int		flag;
	char	*tmp;
	char	*buf;
}	t_hist;

#endif