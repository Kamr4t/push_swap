/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:08:12 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/15 09:56:47 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(dest);
	i = 0;
	if (size <= len)
		return (size + ft_strlen(src));
	if (src[i] == '\0')
		return (len + ft_strlen(src));
	while (src[i] != '\0' && (len + i) < size)
	{
		dest[len + i] = src[i];
		i++;
	}
	if ((len + i) == size)
		dest[len + i - 1] = '\0';
	else
		dest[len + i] = '\0';
	return (len + ft_strlen(src));
}
/*
int	main(void)
{
	char	dest1[12] = "Hello ";
	char	dest2[12] = "Hello ";
	char	*src = "World!";
	int	len;

	len = ft_strlcat(dest1, src, sizeof(dest1));
	printf("%s\n%d\n", dest1, len);

	len = strlcat(dest2, src, sizeof(dest2));
	printf("%s\n%d\n", dest2, len);
}*/
