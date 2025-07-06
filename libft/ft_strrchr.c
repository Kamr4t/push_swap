/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:00:34 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/22 17:16:51 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i--;
	}
	return (0);
}
/*
int	main(void)
{
	char	hay[50] = "Where is the Needle in the Hay, i Can't find it!!?";
	char	needle = 'P';
	char	*test;
	
	test = ft_strrchr(hay, needle);
	if (test == 0)
	{
		printf("test\n");
		return (0);
	}
	printf("%s\n", test);
	test = strrchr(hay, needle);
	printf("%s\n", test);	
	return (0);
}*/
