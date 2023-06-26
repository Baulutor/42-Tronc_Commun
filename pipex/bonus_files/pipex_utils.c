/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:18:37 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/26 21:04:10 by dbaule           ###   ########.fr       */
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
