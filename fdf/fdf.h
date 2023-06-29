/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:42:44 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/28 22:51:42 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct data
{
	void	*mlx;
	void	*win;

	void	*img; //pour put pixel
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		height;
	int		width;
	int		fd;
	
	int		**z_matrix;
	char	*path;
	
	int		x0;
	int		x1;
	int		y0;
	int		y1;
}	t_data;

void	ft_free_z_matrix(t_data *data);

char	*get_next_line(int fd);
char	*ft_strchr_gnl(char *a);
void	*ft_calloc_gnl(size_t elementCount, size_t elementSize);
char	*ft_strjoin_gnl(char const *s1, char const *s2);

int	check_width(t_data *data, char **to_int);
#endif