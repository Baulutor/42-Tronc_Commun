/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:44:06 by dbaule            #+#    #+#             */
/*   Updated: 2023/04/28 16:10:17 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F2F_H
# define F2F_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct data
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		color;
	int		zoom;
	
	int		**z_matrix;
} t_data;

# include <fcntl.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <math.h>

# include "get_next_line/get_next_line.h"
# include "mlx/mlx_linux/mlx.h"
# include "mlx/mlx_linux/mlx_int.h"
# include "ft_printf/ft_printf.h"
 
int	verif(char *str);
char	**ft_split(char const *s, char c);

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *string);
char	*ft_strchr(char *a);
void	*ft_calloc(size_t elementCount, size_t elementSize);

t_data	*get_width_and_height(char *argv, t_data *data);

void bresenham(float x, float y, float x1, float y1, t_data *data);
void drawing(t_data *data);


void	free_double_array(char **array);

#endif