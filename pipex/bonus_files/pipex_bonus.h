/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:35:27 by eslamber          #+#    #+#             */
/*   Updated: 2023/06/25 15:59:03 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>

# define HERE_FILE ".here_doc.tmp"

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
	OK,
	OPEN_HERE_DOC,
	GNL,
	STRDUP,
	WRITE,
	UNLINK,
}	t_errors;

typedef struct s_pipex {
	int			**outin;
	int			ind_child;
	int			nb_pipe;
	int			nb_proc;
	int			here_doc;

	char		*str;
	char		*buf;
	int			lenght;

	t_errors	error;
}	t_pipex;

int		exec(t_pipex *struc, int ac, char **av, char **environ);

void	errors(t_errors error, char *cmd);

void	errors_bonus(t_errors error);

void	close_pipe(int outin[2]);

void	anihilation(char **double_array);

char	*cmd_build(char *str, char **env);

int		child(int outin[2], char **av, char **environ);

int		parent(int outin[2], char **av, char **environ);

int		prep_pipe(t_pipex *pip, char **av, int ac);

int		close_all_pipes(t_pipex *struc);
#endif
