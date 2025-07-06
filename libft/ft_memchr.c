/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:03:30 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/14 11:07:17 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;

	c = c & 0xFF;
	i = 0;
	while (i < n)
	{
		if (((const unsigned char *)str)[i] == c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*test;
	void	*ptr;
	char	*edge = "Hi";

	printf("test1\n");
	test = "Where is the Needle in the Hay, 
	I cant find it. It is to much dried grass!!";
	ptr	= memchr(test, 'eeanN', 100);
	if (ptr != 0)
		printf("1: %s\n", ((char *)ptr));

	test = "Where is the Needle in the Hay, 
	I cant find it. It is to much dried grass!!";
	ptr	= ft_memchr(test, 'eeanN', 100);
	if (ptr != 0)
		printf("2: %s\n", ((char *)ptr));

	return (0);
}*/
