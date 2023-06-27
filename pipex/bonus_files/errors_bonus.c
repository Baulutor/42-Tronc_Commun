/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:01:06 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/27 13:35:44 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#define ERR STDERR_FILENO

void	errors_bonus(t_errors error)
{
	if (error == OPEN_HERE_DOC)
		ft_printf_fd(ERR, "Error : Problem when opening file for here_doc\n");
	else if (error == GNL)
		ft_printf_fd(ERR, "Error : Problem with get_next_line function\n");
	else if (error == STRDUP)
		ft_printf_fd(ERR, "Error : Problem with ft_strdup function\n");
	else if (error == WRITE)
		ft_printf_fd(ERR, "Error : Problem with write function\n");
	else if (error == UNLINK)
		ft_printf_fd(ERR, "Error : Problem with unlink function\n");
	exit(1);
}
