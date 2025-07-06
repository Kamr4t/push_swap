/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:26:57 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/20 11:05:54 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = c;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char *hello1 = strdup("Hello World!");
	char *hello2 = strdup("Hello World!");

	hello1 = memset(hello1, "\0", 0);
	printf("memset: %s\n", hello1);

	hello2 = ft_memset(hello2, "\0", 0);
	printf("my ft_: %s\n", hello2);
	return (0);
}*/
