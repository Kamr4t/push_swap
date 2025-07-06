/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:06:44 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/19 15:02:26 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*array;
	size_t	i;

	array = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (array == NULL)
		return (0);
	i = 0;
	while (i < ft_strlen(s))
	{
		array[i] = s[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}
/*
int	main(void)
{
	char	*test;
	char	*test_malloc;

	test = "Hello World! I did all the Must exercises and \0
	will do the extra ones next week Monday";

	test_malloc = ft_strdup(test);
	printf("%s_\n", test_malloc);
	printf("%s_\n", strdup(test));
	free (test_malloc);
	return (0);
}*/
