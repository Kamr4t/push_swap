/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:42:13 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/27 10:50:18 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (dest);
	if (!src && !dest)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	*source;
	char	dest1[50] = "TEST";
	char	dest2[50] = "TEST";
	char	*test1;
	char	*test2;

	source = "Hello World!";

	test1 = ft_memcpy(dest1, source, 8);
	test2 = memcpy(dest2, source, 8);

	printf("my ft_: %s\n", test1);
	printf("memove: %s\n", test2);
	return (0);
}*/
