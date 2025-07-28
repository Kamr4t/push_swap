/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:49:23 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/28 16:10:32 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_nbr(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
		{
			while (ft_isdigit(s[i]))
				i++;
			count++;
		}
		i++;
	}
	return (count);
}

static bool	check_duplicated_n(int *array, int nbr)
{
	int			i;
	static int	used_slots = 0;

	i = 0;
	while (i < used_slots)
	{
		if (nbr == array[i])
			return (false);
		i++;
	}
	array[used_slots] = nbr;
	used_slots++;
	return (true);
}

static bool	check_single_argv(char **argv, int *digit_array)
{
	char	**array;
	int		i;
	int		j;
	int		nbr;
	
	array = ft_split(argv[1], ' ');
	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (!ft_isdigit(array[i][j]))
				return (false);
			j++;
		}
		nbr = ft_atoi(array[i]);
		if (!check_duplicated_n(digit_array, nbr))
			return (false);
		i++;
	}
	array_free(array);
	free (digit_array);
	return (true);
}

static bool	check_multi_argv(int argc, char **argv, int *digit_array)
{
	int		i;
	int		j;
	int		nbr;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (false);
			j++;
		}
		nbr = ft_atoi(argv[i]);
		if (!check_duplicated_n(digit_array, nbr))
			return (false);
		i++;
	}
	free (digit_array);
	return (true);
}

bool	is_valid(int argc, char **argv)
{
	int		*digit_array;
	int		digit_count;

	if (argc == 2)
	{
		digit_count = count_nbr(argv[1]);
		digit_array = malloc(digit_count * sizeof(int));
		if (!check_single_argv(argv, digit_array))
			return (false);
	}
	else
	{
		digit_array = malloc(argc * sizeof(int));
		if (!check_multi_argv(argc, argv, digit_array))
			return (false);
	}
	return (true);
}
