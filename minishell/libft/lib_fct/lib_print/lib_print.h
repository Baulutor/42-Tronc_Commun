/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_print.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:56:43 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/25 17:11:32 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PRINT_H
# define LIB_PRINT_H
# include <unistd.h>
# include <stdarg.h>

// Macro to print "Error\n" on right file descriptor
# define ER 2
# define MSG "Error\n"

typedef struct s_print{
	size_t	ind;
	int		fd;
}	t_print;

typedef struct s_print_a{
	int	mod;
	int	fd;
}	t_print_a;

// Write caractere c in descriptor file fd
size_t	ft_putchar_fd(char c, int fd);

// Write string s in descriptor file fd
size_t	ft_putstr_fd(char *s, int fd);

// Write string s in descriptor file fd with end line
size_t	ft_putendl_fd(char *s, int fd);

// Write integer n in descriptor file fd with end line
size_t	ft_putnbr_fd(int n, int fd);

// Printf by 42
int		ft_printf(const char *str, ...);

// Printf_fd by 42
int		ft_printf_fd(int fd, const char *str, ...);

// Convert integer from base 10 to base 16
void	conv_ten_to_hex(int nbr, char dep, int *res);

// Convert integer from base 10 to base 16 and print at adress format
void	print_adress(long long int nbr, char dep, int *res, int mod);

// Convert integer from base 10 to base 16 and put it in file fd
void	conv_ten_to_hex_fd(int nbr, char dep, int *res, t_print d);

// Convert integer from base 10 to base 16 and print at adress format in file fd
void	print_adress_fd(long long int nbr, char dep, int *res, t_print_a *m);

#endif
