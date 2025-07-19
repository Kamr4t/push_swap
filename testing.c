/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:22:22 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/19 10:53:14 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int	power_of(int power)
{
	int	base10;
	int	i;

	i = 1;
	base10 = 10;
	while (i < power)
	{
		base10 *= 10;
		i++;
	}
	return (base10);
}

int	main(int argc, char **argv)
{
	int	test;

	
	test = power_of(atoi(argv[1]));
	printf("%d\n", test);
}
