/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:26:44 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/14 11:34:02 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((const unsigned char *)s1)[i] != ((const unsigned char *)s2)[i])
			return (((const unsigned char *)s1)[i] - 
			((const unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	int	a;
	char	*test1;
	char	*test2;

	test1 = "1";
	test2 = "9";

	a = memcmp("12345", "1234567", 1000);
	printf("memcmp: %d\n", a);

	a = ft_memcmp("12345", "1234567", 1000);
	printf("my ft: %d\n", a);
	return (0);
}*/
