/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:35:11 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/30 16:05:13 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <dirent.h>
# include <sys/ioctl.h>

# include "../libft/libft.h"

# define CON_C SIGINT
# define IGN SIG_IGN
# define QUIT SIGQUIT
# define DEBUG 1
# define ERR STDERR_FILENO

extern unsigned char	g_status;

typedef enum e_error{
	ADD_LIST,
	MALLOC,
	CALLOC,
	TAILING,
	CMD,
	JOIN,
	PIPE,
	FORK,
	SPLIT,
	EXEC,
	TOO_MANY_ARG,
	CLOSE,
	TOKEN,
	OPEN,
	DUP,
	STRDUP,
	WRITE,
	SYNTAX,
	NUM_ARG,
	DIREC,
	PERM,
	FILES,
	NVALID
}	t_error;

typedef struct t_cmd
{
	int		nb_pipe;
	int		status_hd;
	int		nb_proc;
	int		parent_builtin;
	char	**save_path;
	int		builtin;
	int		heredoc;
	int		ind_hd;
	int		ani_flag;
	int		flag;
	int		*here_pipe;
	int		**pipe;
	char	**hd_history;
	char	**env;
	char	**exp_env;
	t_bool	in;
	t_bool	out;
}	t_cmd;

// Générals
void			error(t_error err, char *cmd);

void			quit(void);

void			silent_quit(void);

int				historic_fct(char *rd_line, t_cmd *pip);

char			*verif_read(char *rd_line, t_cmd *pip);

int				cpy_env(char **env, t_cmd *pip);

int				check_heredoc(char **arg, t_cmd *struc);

// Signals
void			main_signals(void);

void			exec_signals(void);

void			unset_signals(void);

void			hd_signals(void);

void			hsigint(int sig);

void			hsigint_exec(int sig);

void			hsigint_hd(int sig);

void			hsigquit(int sig);

// Builtins
int				parent_builtins(t_cmd *pip, char **exec_cmd);

int				search_builtins(char **spt, t_cmd *pip);

char			*pwd(void);

void			env(char **envir);

unsigned char	intermediate_exit(char **tmp);

unsigned char	exitt(unsigned char ret_value);

void			echo(char **arg, int option);

void			cd(char **path, t_cmd *pip);

int				export(t_cmd *pip, char *name_value);

void			print_export(char **exp_env);

int				initialize_exp_env(t_cmd *pip, char **env);

int				add_exp_env(t_cmd *pip, char *str);

int				unset(t_cmd *pip, char *name_value);

char			*rm_char(char *str, char c);

char			*rm_char_exp(char *str, char c);

char			*check_quote(char *str);

char			*trash_quote(char *str);

char			*trash_quote_buil_exec(char *str);

int				position_echo_n(char **arg, int *j, int *flag, int *option);

int				count_name_env(char *str);

int				check_zero(char *str);

// Free functions

void			anihilation(char **str);

void			free_all(t_cmd *pip);

void			free_tab_pid(pid_t *tab, int size);

// Fork and pipes
int				close_all_pipes(t_cmd *pi);

// Commands
char			*cmd_build(char *str, char **env);

int				cmd_center_simple(char **str, t_cmd *pip);

char			*expand(char *rd_line, t_cmd *pip, int *expand_flag);

int				*counting_arg(int count, t_list *spt);

char			**string_for_cmd_center(int *tab, int i, t_list *spt);

char			**check_redirection(char **arg, t_cmd *pip);

char			**check_redirection_parent(char **arg, t_cmd *struc);

char			**prep_hd(t_cmd *pip, t_list *spt);

int				execution_center(t_list *spt, t_cmd *pip);

// Parsing

int				parsing(const char *rd_line, int *flag, t_list *spt);

int				ft_is_redirection(const char *str, int i);

#endif
