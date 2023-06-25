/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:08:39 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/10 17:56:28 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_LIST_H
# define LIB_LIST_H
# include <stdlib.h>
# include <unistd.h>
# define DEBUG 1
# define NODEB 0

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

// Initailisation of head of list
t_list	*init_list(t_list *lst);

// Initialisation of datain cells
t_data	*init_data(void *d, t_type t, t_bool allow, t_data *cell);

// Stacking values in a list (add in first place)
int		stacking_list(t_list *lst, void *data, t_type t, int debug);

// Add value in a list (add in last place)
int		tailing_list(t_list *lst, void *data, t_type t, int debug);

// Remove cell from the front of list and return it
t_cell	*unstack_list(t_list *lst, int debug);

// Remove cell from the front of list and free it
void	rmstack_list(t_list *lst, t_bool allow, int debug);

// Remove cell from the back of list and return it
t_cell	*untail_list(t_list *lst, int debug);

// Remove cell from the back of list and free it
void	rmtail_list(t_list *lst, t_bool allow, int debug);
#endif
