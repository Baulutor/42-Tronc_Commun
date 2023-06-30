/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:42:44 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/30 14:15:11 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"
# include <stdio.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct data
{
	void	*mlx;
	void	*win;
	int 	check;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		height;
	int		width;
	int		fd;
	int		zoom;
	
	int		**z_matrix;
	char	*path;
	
	
	int		limit;
	int		*arr;
	
	int		x0;
	float	x1;
	int		y0;
	float	y1;
	int		z0;
	int		z1;
	float	new_x;
	float	new_y;
	float	x_step;
	float	y_step;
}	t_data;

void	ft_free_z_matrix(t_data *data, int y);

int	ft_close(t_data *data);

char	*get_next_line(int fd, int check);
char	*ft_strchr_gnl(char *a);
void	*ft_calloc_gnl(size_t elementCount, size_t elementSize);
char	*ft_strjoin_gnl(char const *s1, char const *s2);

void	get_width(char **to_int, t_data *data);
int		check_width(t_data *data, char **to_int);

void	ft_free_double_char(char **tofree);

int		check_str(char a);

int		drawing(t_data *data);
void	assign_pos(t_data *data, float *coor_x, float *coor_y);

char	**ft_split(char const *s, char c);

int	zoom_key(t_data *data, int key);
int	hooks(int key, t_data *data);
#endif