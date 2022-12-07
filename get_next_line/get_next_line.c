/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:34:48 by dbaule            #+#    #+#             */
/*   Updated: 2022/12/07 15:27:09 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_new_line(char *tmp)
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

char	*ft_read_check(int fd, char *str)
{
	ssize_t	x;
	char	j[BUFFER_SIZE + 1];

	x = 1;
	if (!str)
		str = ft_calloc(1, 1);
	while (x > 0 && ft_check_new_line(j) == -1)
	{
		x = read(fd, j, BUFFER_SIZE);
		if (x == -1)
		{
			if (str)
				free (str);
			return (NULL);
		}
		j[x] = 0;
		str = ft_clean_buffer(str, j);
	}
	return (str);
}

char	*ft_str_new_line(char *tmp)
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
		return (NULL);
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

char	*ft_clean_buffer(char *buffer, char *buf)
{
	char	*s;

	s = ft_strjoin(buffer, buf);
	free(buffer);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*tmp;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	tmp = ft_read_check(fd, str);
	if (!tmp)
		return (NULL);
	buffer = ft_str_new_line(tmp);
	str = ft_strchr(tmp);
	return (buffer);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str;
// 	int	i = 0;
// 	fd = open("test.txt", O_RDONLY);
// 	while (i < 100)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s", str);
// 		free(str);
// 		i++;
// 	}
// close(fd);
// }
