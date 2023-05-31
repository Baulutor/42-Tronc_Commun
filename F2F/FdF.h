/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:44:06 by dbaule            #+#    #+#             */
/*   Updated: 2023/05/31 17:10:10 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F2F_H
# define F2F_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef RED
#  define RED 0x800000
# endif

# ifndef WHITE
#  define WHITE 0x800000
# endif

typedef struct data
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		color;
	int		zoom;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	
	int		pos_tabx;
	int		pos_taby;

	
	int		**z_matrix;
}	t_data;

# include <fcntl.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <math.h>

# include "mlx/mlx_linux/mlx.h"
# include "mlx/mlx_linux/mlx_int.h"

typedef struct pos_x_y
{
	float x_step;
	float y_step;
	float new_x;
	float new_y;

	int x;
	int y;
	float x1;
	float y1;
	int z;
	int	z1;
}	t_pos;
 
int		verif(char *str);
char	**ft_split(char const *s, char c);

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *string);
char	*ft_strchr(char *a);
void	*ft_calloc(size_t elementCount, size_t elementSize);

t_data	*get_width_and_height(char *argv, t_data *data);


void	drawing(t_data *data);

void	assign_pos(t_data *data, float *x1, float *y1, int *x, int *y, float *new_x, float *new_y);
int		check_inbound(float new_x, float new_y);
void	assign_zoom(t_data *data, t_pos *pos);

void	free_double_array(char **array);

#endif