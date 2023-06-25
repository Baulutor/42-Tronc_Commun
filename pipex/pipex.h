/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:31:47 by eslamber          #+#    #+#             */
/*   Updated: 2023/06/20 11:08:36 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>

typedef enum e_errors{
	PIPE,
	CONDITIONS,
	FORK,
	OPEN,
	DUP,
	CLOSE,
	SPLIT,
	CMD,
	EXEC,
	CLOSE_P0,
	CLOSE_P1,
	JOIN,
}	t_errors;

void	errors(t_errors error, char *cmd);

int		close_pipe(int outin[2]);

void	anihilation(char **double_array);

char	*cmd_build(char *str, char **env);

int		child(int outin[2], char **av, char **environ);

int		parent(int outin[2], char **av, char **environ);

#endif
