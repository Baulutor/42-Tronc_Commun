/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:22:05 by dbaule            #+#    #+#             */
/*   Updated: 2023/05/04 16:38:14 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_hub(const char fd, const char cmd)
{
	if (open(fd, O_RDONLY) == -1)
		return (ft_printf ("Error, do you have the right name of the file ? \
				or did you have the right acces to it ?"), -1);
	exevce();
}