/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:59:18 by dbaule            #+#    #+#             */
/*   Updated: 2023/01/13 13:38:22 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// get the argv in the stacks A in one argument

int	*stacks_A(char **argv, int argc)
{
	int		*array;
	char	**to_take;
	char	**take_it;
	int		x;
	int		y;
	int z;
	(void)argc;

	x = 0;
	y = 0;
	z = 1;
	take_it = malloc(sizeof(char*) * 57);
	if (!argv[2])
	{	
		while (argv[z])
		{
			to_take = ft_split(argv[z], ' ');
			if (!to_take)
				return (NULL);
			z++;
		}
	}
	else
	{
		while (argv[z])
		{
			to_take = ft_split(argv[z], ' '); // marche bien, mais ecrase ceux d'avant,
			if (!to_take)
				return (NULL);
			take_it[x] = to_take[y];
			z++;
			x++;
		}
	}
	if (!argv[2])
		array = malloc(sizeof(int) * 10000); // prob ici comment allouer le tableau de int  mais marche dcp aucun sens?
	else
		array = malloc (sizeof(int) * 10000); // meme prob
	y = 0;
	x = 0;
	if (!argv[2])
	{
		while (to_take[y])
		{
			array[y] = ft_atoi(to_take[y]);
			y++;
		}  
	}
	else
	{
		while (take_it[y]) // ne fait qu'une seule fois la boucle avec le dernier argument, pourtant to take a bien tout
		{
			array[y] = ft_atoi(take_it[y]);
			y++;
		}
	}
	return (array);
}

// look at the argv if there is no problem

int	verif(char **argv)
{
	int x;
	int y;

	x = 1;
	y = 0;
	while (argv[x])
	{
		while (argv[x][y])
		{
			if (((argv[x][y] > '9' || argv[x][y] < '0') && (argv[x][y] != ' '))
			&& ((argv[x][y] == '-') && (argv[x][y + 1] < '0' || argv[x][y + 1] > '9'))
			&& ((argv[x][y] == '+') && (argv[x][y + 1] < '0' || argv[x][y + 1] > '9'))) // les signes nazes tu gere pas si il y a un signe seul sans rien
				return (-1);
			y++;
		}
		x++;
		y = 0;
	}
	return (0);
}

int main (int argc, char **argv)
{
	int	*gang;
	int x;
	
	if (argc > 2)
	if (verif(argv) == -1)
		return (printf("Error\n"));
	gang = stacks_A(argv, argc);
	if (gang[0] == -1 || gang[0] == 0) // c'est selon l'overflow d'atoi mais dcp marche pas si le premier argument est 0 ou -1 donc nul
		return (printf("Error\n"));
	x = 0;
	while (gang[x])
	{
		printf("%d\n", gang[x]);
		x++;
	}
	// printf("%d\n", gang[0]);
	// printf("%d\n", gang[1]);
	// printf("%d\n", gang[2]);
	return (0);
}