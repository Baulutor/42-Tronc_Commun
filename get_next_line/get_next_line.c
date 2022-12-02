/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:34:48 by dbaule            #+#    #+#             */
/*   Updated: 2022/12/02 22:04:20 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check_new_line(char *tmp)
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
	size_t	x;
	size_t	y;
	char	j[BUFFER_SIZE +1];
	char	*buf;

	x = 1;
	y = 0;
//	printf("str == %s\n", str);
	if (!str)
		str = ft_calloc(1, 1);
	else 
	{
		if (ft_check_new_line(str) != -1)
			return (str);
	}
	while (x > 0 && (ft_check_new_line(j) == -1))
	{
		x = read(fd, j, BUFFER_SIZE);
		j[x] = 0;
		buf = str;
		str = ft_strjoin(buf, j);
	}
	return (str);
}

char	*ft_str_new_line(char *tmp)
{
	size_t	x;
	char	*buf;

	x = 0;
	buf = ft_calloc(sizeof(char), (ft_check_new_line(tmp) + 1));
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

char	*ft_clean_buffer(char * tmp)
{
	char	*s;

	s = tmp;
	s = ft_strchr(s, '\n');
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*tmp;
	static char	*buffer;
	
	if (!fd)
		return(NULL);
	tmp = ft_read_check(fd, str);
//	printf("tmp %s", tmp);
	buffer = tmp;
//	printf("%s\n", tmp);
	buffer = ft_str_new_line(tmp);
//	printf("%s", buffer);
//	free(tmp);
	str = ft_clean_buffer(tmp);
//	free(tmp);
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
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	//free(str);
// close(fd);
// }
