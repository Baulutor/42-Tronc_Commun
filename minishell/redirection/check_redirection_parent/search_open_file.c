/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_open_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:56:44 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/29 15:35:53 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../incs/check_redirection_parent.h"

static int	check_input_redir(t_cmd *struc, int *i, t_red_par *red);

static int	check_output_redir(t_cmd *struc, t_red_par *red, int *i);

static int	open_double_token(t_red_par *red, int *i);

int	search_open_file(t_red_par *red, t_cmd *struc)
{
	int	i;

	i = 0;
	while (red->buf[i])
	{
		if (red->buf[i][0] == '<')
		{
			if (check_input_redir(struc, &i, red) == 1)
				return (1);
		}
		else if (red->buf[i][0] == '>')
		{
			if (check_output_redir(struc, red, &i) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

static int	check_input_redir(t_cmd *struc, int *i, t_red_par *red)
{
	struc->in = TRUE;
	if (red->buf[*i][1] == '\0')
	{
		if (red->buf[*i + 1] == NULL)
			return (anihilation(red->buf), error(TOKEN, "0"), 1);
		red->file = open(red->buf[*i + 1], O_RDONLY);
		if (red->file == -1)
			return (anihilation(red->buf), error(OPEN, "0"), g_status = 1, 1);
		close(red->file);
		*i += 1;
	}
	else if (red->buf[*i][1] == '<' && red->buf[*i][2] == '\0')
		*i += 1;
	else if (red->buf[*i][1] != '<' || red->buf[*i][2] == '\0')
	{
		red->file = open(&red->buf[*i][1], O_RDONLY);
		if (red->file == -1)
		{
			return (anihilation(red->buf), error(OPEN, "0"), g_status = 1, 1);
		}
		close(red->file);
	}
	return (0);
}

static int	check_output_redir(t_cmd *struc, t_red_par *red, int *i)
{
	struc->out = TRUE;
	if (red->buf[*i][1] == '\0')
	{
		if (red->buf[*i + 1] == NULL)
			return (anihilation(red->buf), error(TOKEN, "0"), 1);
		red->file = open(red->buf[*i + 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (red->file == -1)
			return (anihilation(red->buf), error(OPEN, "0"), g_status = 1, 1);
		close(red->file);
		*i += 1;
	}
	else if (red->buf[*i][1] == '>')
	{
		if (open_double_token(red, i) == 1)
			return (1);
	}
	else
	{
		red->file = open(&red->buf[*i][1], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (red->file == -1)
			return (anihilation(red->buf), error(OPEN, "0"), g_status = 1, 1);
		close(red->file);
	}
	return (0);
}

static int	open_double_token(t_red_par *red, int *i)
{
	if (red->buf[*i][2] == '\0')
	{
		if (red->buf[*i + 1] == NULL)
			return (anihilation(red->buf), error(TOKEN, "0"), 1);
		red->file = open(red->buf[*i + 1], O_CREAT | O_RDWR | \
		O_APPEND, 0644);
		if (red->file == -1)
			return (anihilation(red->buf), error(OPEN, "0"), \
			g_status = 1, 1);
		close(red->file);
		*i += 1;
	}
	else
	{
		red->file = open(&red->buf[*i][2], O_CREAT | O_RDWR | \
		O_APPEND, 0644);
		if (red->file == -1)
			return (anihilation(red->buf), error(OPEN, "0"), \
			g_status = 1, 1);
		close(red->file);
	}
	return (0);
}
