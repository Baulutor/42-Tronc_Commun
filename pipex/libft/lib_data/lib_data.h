/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:38:47 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/28 16:41:56 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_DATA_H
# define LIB_DATA_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "l_simple/lib_simple.h"

# define DEBUG 1
# define NODEB 0

// Macro to print "Error\n" on right file descriptor
# define ER 2
# define MSG "Error\n"

typedef enum e_type {
	CHAR = 0,
	INT = 1,
	STRING = 2,
	DOUBLE = 3,
	LONG = 4,
	UNSIGNED = 5,
	LONG_LONG = 6,
	LONG_UNSIGNED = 7,
	LONG_LONG_UNSIGNED = 8,
	LIST = 9,
	LIST_IND = 10,
	STACK = 11,
	QUEUE = 12,
	DICO = 13,
	TREE = 14,
	ALEA = 15
}	t_type;

typedef enum e_bool{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_data {
	t_type	type_data;
	t_bool	allowed;
	void	*data;
}	t_data;

typedef struct s_cell {
	t_data			*data_cell;
	struct s_cell	*prev;
	struct s_cell	*next;
}	t_cell;

typedef struct s_list {
	size_t	len;
	size_t	len_ind;
	t_type	type_lst;
	t_cell	*head;
	t_cell	*tail;
}	t_list;

// Prototype
typedef struct s_head_tree {
	size_t	len_uplet;
	t_data	*data;
	t_list	*leaves;
}	t_tree;

typedef struct s_p {
	size_t	ind;
	int		fd;
}	t_p;

typedef struct s_p_a {
	int	mod;
	int	fd;
}	t_p_a;

/*####################### LIST ########################*/
// Initailisation of head of list
t_list			*init_list(t_list *lst);

// Stacking values in a list (add in first place)
int				stacking_list(t_list *lst, void *data, t_type t, int debug);

// Add value in a list (add in last place)
int				tailing_list(t_list *lst, void *data, t_type t, int debug);

// remove cell from the front of list and return it
t_cell			*unstack_list(t_list *lst, int debug);

// Remove cell from the front of list and free it
void			rmstack_list(t_list *lst, t_bool allow, int debug);

// Remove cell from the back of list and return it
t_cell			*untail_list(t_list *lst, int debug);

// Remove cell from the back of list and free it
void			rmtail_list(t_list *lst, t_bool allow, int debug);

/*##################### LIST_IND ######################*/
void			init_list_ind(void);

/*###################### QUEUE ########################*/
void			init_queue(void);

/*###################### STACK ########################*/
// Initialisation of queue list
t_list			*init_stack(t_list *lst);

// Add element on first index of list
int				stacking(t_list *lst, void *data, t_type t, int debug);

// Remove first element and return it
t_cell			*unstack(t_list *lst, int debug);

// Remove first element and destroy it
void			rmstack(t_list *lst, t_bool allow, int debug);

/*####################### TREE ########################*/
void			init_tree(void);

/*####################### GNRL ########################*/
// Function do nothing
void			none(void);

// Return true if type given is a list type
int				is_list(t_type t);

// Initialisation of data cells
t_data			*init_data(void *data, t_type t, t_bool allow, t_data *cell);

// Find d in list lst return 0 if not found
t_cell			*where(t_list *lst, t_type t, void *d, size_t n);

// Return size of type give to argument
// If a pointer is given as argument, return -1
long long int	size(t_type t, int debug);

// Delete data in data_cell with f and free cell
void			clear_cell(t_list *lst, t_cell *cell, void (*f)(void *));

// Delete list, f delete data in every data_cell
void			annihilation(t_list *lst, void (*f)(void *), int debug);

// Return the data contened in cell
void			*content(t_cell *cell);

// Return convert value contened in cell
int				value_int(t_cell *cell);

// Print the charactere c in file descriptor fd
size_t			ft_putchar_fd(char c, int fd);

// Print the number n in filedescriptor fd
size_t			ft_putnbr_fd(int n, int fd);

// Print the string s in file descriptor fd
size_t			ft_putstr_fd(char *s, int fd);

// Convert number in base 10 to a number in base 16
void			conv_ten_to_hex(int nbr, char dep, int *res);

// Print the adress of pointer nbr
void			print_adress(long long int nbr, char dep, int *res, int mod);

// Printf by 42
int				ft_printf(const char *str, ...);

// Printf_fd by 42
int				ft_printf_fd(int fd, const char *str, ...);

// Print the list given
void			print_list(t_list *lst);

// Convert integer from base 10 to base 16 and put it in file fd
void			conv_to_hex_fd(int nbr, char dep, int *res, t_p d);

// Convert integer from base 10 to base 16 and print at adress format in file fd
void			print_adres_fd(long long int nb, char dep, int *res, t_p_a *m);
#endif
