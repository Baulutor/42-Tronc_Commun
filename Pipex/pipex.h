/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:22:19 by dbaule            #+#    #+#             */
/*   Updated: 2023/05/16 17:11:44 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <errno.h>

#include <sys/types.h>
#include <sys/wait.h>

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

int	exec_hub(char *cmd);

#endif
