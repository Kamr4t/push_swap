/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:42:56 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/15 10:47:17 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		while (s1[i] == s2[j] && i < n)
		{
			i++;
			j++;
			if (s2[j] == '\0')
				return ((char *) &s1[i - j]);
		}
		i = i + 1 - j;
	}
	return (0);
}
/*
int	main(void)
{
	char	hay[100] = "eeEEEeeeEeeeEeeeeEEEe ";
	char	*needle = "eeeEeeee";
	char	*test;

	//test = strnstr(hay, needle, 17);
	//printf("%s\n", test);
	test = ft_strnstr(hay, needle, 17);
	printf("%s\n", test);
	return (0);
}*/
