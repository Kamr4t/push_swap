/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:02:37 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/19 14:56:24 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char	src1[] = "Hello World!";
	char	dest1[0];
	char	src2[] = "Hello World!";
	char	dest2[0];

	size_t	test;

	test = ft_strlcpy(dest1, src1, sizeof(dest1));
	printf("Length: %zu\n", test);
	printf("%s\n", dest1);

	test = strlcpy(dest2, src2, sizeof(dest2));
	printf("Length: %zu\n", test);
	printf("%s\n", dest2);
	return (0);
}*/
