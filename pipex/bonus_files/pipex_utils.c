/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:18:37 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/27 13:38:32 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strjoin_pip(char *dest, char *src)
{
	size_t	len_tot;
	char	*new;

	len_tot = ft_strlen(dest) + ft_strlen(src) + 1;
	new = (char *) malloc(sizeof(char) * len_tot);
	if (new == NULL)
		return (NULL);
	new[0] = '\0';
	ft_strlcat(new, dest, len_tot);
	if (dest)
		free(dest);
	ft_strlcat(new, src, len_tot);
	return (new);
}

void	free_here_doc(t_pipex *pip)
{
	free(pip->buf);
	close_all_pipes(pip);
	free(pip->str_heredoc);
}

int	verif_here_doc(t_pipex *pip, char **av)
{
	if (pip->here_doc == 1)
	{
		if (set_up_heredoc(av, pip) == 1)
			return (1);
	}
	return (0);
}

int	close_all_pipes(t_pipex *pi)
{
	int	j;

	j = 0;
	while (j < pi->nb_pipe)
	{
		if (close(pi->outin[j][0]) == -1)
		{
			pi->error = CLOSE_P0;
			return (errors(CLOSE_P0, "0"), anihilation((char **) pi->outin), 1);
		}
		if (close(pi->outin[j][1]) == -1)
		{
			pi->error = CLOSE_P1;
			return (errors(CLOSE_P1, "0"), anihilation((char **) pi->outin), 1);
		}
		j++;
	}
	anihilation((char **) pi->outin);
	return (0);
}
