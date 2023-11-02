/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_parent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:31:07 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/30 15:32:44 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
#include "../incs/builtins.h"

static unsigned char	intermediate_exit_bis(long *ret, char **tmp);

unsigned char	intermediate_exit(char **tmp)
{
	long			ret_value;
	int				len;
	unsigned char	ret;

	len = 0;
	ret = 0;
	if (tmp == NULL)
		return (exitt(0));
	while (tmp[len])
		len++;
	if (len == 1)
		return (exitt(0));
	else
		ret = intermediate_exit_bis(&ret_value, tmp);
	if (ret != 0)
		return (ret);
	if (len > 2)
		return (error(TOO_MANY_ARG, "exit"), exitt(1));
	return (exitt((unsigned char) ret_value));
}

static unsigned char	intermediate_exit_bis(long *ret, char **tmp)
{
	int		i;
	char	*buf;

	buf = (char *) tmp[1];
	if (buf != tmp[1])
		free(tmp[1]);
	tmp[1] = buf;
	i = 0;
	while (buf[i])
	{
		if (!ft_isdigit(buf[i]))
			if (i > 0 || (i == 0 && buf[i] != '-' && buf[i] != '+'))
				return (error(NUM_ARG, "0"), exitt(2));
		i++;
	}
	*ret = ft_atoi(buf);
	if (*ret == 0 && ft_strlen(buf) > 2 && check_zero(buf) == 0)
		return (ft_printf_fd(2, "Error : %s numeric argument required", buf) \
		, exitt(2));
	return (0);
}

unsigned char	exitt(unsigned char ret_value)
{
	g_status = ret_value;
	return (ret_value);
}

void	cd(char **path, t_cmd *pip)
{
	int	i;

	i = 0;
	if (!path)
		return ;
	while (path[i])
		i++;
	if (i <= 2 && path != NULL && chdir(path[1]) != 0)
	{
		g_status = 1;
		ft_printf_fd(2, "-bash: cd: %s: No such file or directory\n", path[1]);
		return ;
	}
	if (i > 2)
	{
		error(TOO_MANY_ARG, "cd");
		g_status = 1;
		return ;
	}
	g_status = 0;
	pip->builtin = TRUE;
}
