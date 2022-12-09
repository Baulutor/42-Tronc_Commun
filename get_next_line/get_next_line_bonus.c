/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:09:03 by dbaule            #+#    #+#             */
/*   Updated: 2022/12/09 14:49:47 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_check_new_line(char *tmp)
{
	size_t	x;

	x = 0;
	while (tmp[x])
	{
		if (tmp[x] == '\n')
			return (x);
		x++;
	}
	return (-1);
}

static char	*ft_clean_buffer(char *buffer, char *buf)
{
	char	*s;

	s = ft_strjoin(buffer, buf);
	if (!s)
		return (free(buffer), buffer = NULL, NULL);
	free(buffer);
	buffer = NULL;
	return (s);
}

static char	*ft_read_check(int fd, char *str)
{
	ssize_t	x;
	char	j[BUFFER_SIZE + 1];

	x = 1;
	if (!str)
		str = ft_calloc(1, 1);
	while (x > 0)
	{
		x = read(fd, j, BUFFER_SIZE);
		if (x == -1)
		{
			if (str)
				free (str);
			str = NULL;
			return (NULL);
		}
		j[x] = 0;
		str = ft_clean_buffer(str, j);
		if (ft_check_new_line(j) != -1)
			break ;
	}
	return (str);
}

static char	*ft_str_new_line(char *tmp)
{
	size_t	x;
	char	*buf;

	x = 0;
	if (tmp[0] == '\0')
		return (NULL);
	if (ft_check_new_line(tmp) != -1)
		buf = ft_calloc(sizeof(char), (ft_check_new_line(tmp) + 2));
	else
		buf = ft_calloc(sizeof(char), (ft_strlen(tmp) + 1));
	if (!buf)
		return (buf = NULL, NULL);
	while (tmp[x] && tmp[x] != '\n')
	{
		buf[x] = tmp[x];
		x++;
	}
	if (tmp[x] == '\n')
	{
		buf[x] = tmp[x];
		buf[x + 1] = 0;
	}
	else
		buf[x] = 0;
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		if (str[fd])
		{
			str[fd][0] = 0;
			free (str[fd]);
			str[fd] = NULL;
		}
		return (NULL);
	}
	str[fd] = ft_read_check(fd, str[fd]);
	if (!str[fd])
		return (str[fd] = NULL, NULL);
	buffer = ft_str_new_line(str[fd]);
	str[fd] = ft_strchr(str[fd]);
	if (!buffer)
	{
		free(str[fd]);
		str[fd] = NULL;
	}
	return (buffer);
}
