/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:22:22 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/17 09:55:50 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void	print_array(int	array[10])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		printf("%d, ", array[i]);
		i++;
	}
}

static int	insert_loop(int	array[10], int nbr, int i)
{
	int	j;
	int	tmp;

	j = 0;
	while (array[i + j] != 0)
	{
		tmp = array[i + j];
		array[i + j] = nbr;
		nbr = tmp;
		j++;
	}
	array[i + j] = nbr;
	return (0);
}

static int	insert_array(int array[10], int nbr)
{
	int	i;

	i = 0;
	while (1)
	{
		if (array[i] == 0)
		{
			array[i] = nbr;
			break ;
		}
		else if (nbr > array[i])
		{
			insert_loop(array, nbr, i);
			break ;
		}
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;
	int	array[10];
	int	nbr;
	int	test;

	i = 0;
	while (i < 10)
	{
		array[i] = 0;
		i++;
	}
	array[0] = 7;
	array[1] = 5;
	array[2] = 4;
	array[3] = 2;
	if (argc != 2)
	{
		printf("Invalid Arguments!");
		return (-1);
	}
	nbr = atoi(argv[1]);
	test = insert_array(array, nbr);
	print_array(array);
	printf("\ni = %d\n", test);
	return (0);
}
