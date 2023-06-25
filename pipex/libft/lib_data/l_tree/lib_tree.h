/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_tree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:12:01 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/10 17:55:51 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_TREE_H
# define LIB_TREE_H
# include <stdlib.h>
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

// Prototype
typedef struct s_head_tree {
	size_t	len_uplet;
	t_data	*data;
	t_list	*leaves;
}	t_tree;

void	init_tree(void);

#endif
