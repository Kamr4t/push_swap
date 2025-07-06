/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:07:23 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/22 16:31:20 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (0);
}
/*
int	main(void)
{
	char	hay[50] = "Where is the Needle in the Hay, i Can't find it!!?";
	char	needle = 'I';
	char	*test;
	
	test = ft_strchr(hay, needle);
	if (test == 0)
	{
		printf("test\n");
		return (0);
	}
	printf("%s\n", test);
	test = strchr(hay, needle);
	printf("%s\n", test);	
	return (0);
}*/
