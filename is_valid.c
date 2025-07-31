/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:49:23 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/31 20:00:18 by ancamara         ###   ########.fr       */
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

static bool	check_single_argv(char **array, int *digit_array)
{
	int			i;
	int			j;
	long long	nbr;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (!ft_isdigit(array[i][j]) && array[i][j] != '-')
				return (false);
			j++;
		}
		nbr = ft_atoi_long(array[i]);
		if (!check_int(nbr))
			return (false);
		if (!check_duplicated_n(digit_array, nbr))
			return (false);
		i++;
	}
	return (true);
}

static bool	check_multi_argv(int argc, char **argv, int *digit_array)
{
	int			i;
	int			j;
	long long	nbr;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				return (false);
			j++;
		}
		nbr = ft_atoi_long(argv[i]);
		if (!check_int(nbr))
			return (false);
		if (!check_duplicated_n(digit_array, nbr))
			return (false);
		i++;
	}
	return (true);
}

bool	is_valid(int argc, char **argv)
{
	char	**array;
	int		*digit_array;
	int		digit_count;
	bool	is_valid;

	is_valid = true;
	array = NULL;
	if (argc == 2)
	{
		array = ft_split(argv[1], ' ');
		digit_count = count_nbr(argv[1]);
		digit_array = malloc(digit_count * sizeof(int));
		if (!check_single_argv(array, digit_array))
			is_valid = false;
		array_free(array);
	}
	else
	{
		digit_array = malloc(argc * sizeof(int));
		if (!check_multi_argv(argc, argv, digit_array))
			is_valid = false;
	}
	free (digit_array);
	return (is_valid);
}
