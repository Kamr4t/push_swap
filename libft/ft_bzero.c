/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:26:43 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/23 11:53:41 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}
/*
int	main(void)
{

	char test1[] = "Hello World!";
	char test2[] = "Hello World!";
	size_t	len1 = strlen(test1);
	size_t	len2 = strlen(test2);
	size_t	i;
	size_t	del = 11;

	printf("bzero: %s\n", test1);
	bzero(test1, del);
	i = 0;
	while (i < len1)
	{
		write(1, &test1[i], 1);
		i++;
	}
	printf("\n");

	printf("my ft: %s\n", test2);
	ft_bzero(test2, del);
	i = 0;
	while (i < len2)
	{
		write(1, &test2[i], 1);
		i++;
	}
	printf("\n");
	return (0);
}*/
