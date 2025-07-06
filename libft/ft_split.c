/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:11:21 by ancamara          #+#    #+#             */
/*   Updated: 2025/06/17 18:14:40 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **str, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free (str[i]);
		i++;
	}
	free (str);
	return (NULL);
}

static size_t	ft_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	ft_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static char	*ft_array(const char *s, char c)
{
	size_t	i;
	char	*array;

	array = (char *)ft_calloc((ft_len(&*s, c) + 1), sizeof(char));
	if (array == NULL)
		return (0);
	i = 0;
	while (*s != c && *s)
	{
		array[i] = *s;
		s++;
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;

	array = (char **)ft_calloc((ft_count(s, c) + 1), sizeof(char *));
	if (array == NULL)
		return (0);
	array[ft_count(s, c)] = NULL;
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s != '\0')
		{
			array[i] = ft_array(&*s, c);
			if (!(array[i]))
				return (ft_free(array, i));
			while (*s != c && *s)
				s++;
			i++;
		}
	}
	return (array);
}
/*
int	main(void)
{
	char	**array;
	char	test[] = "test,Anthony,,,a,A,,Hello,,,
	World,,./343,,,CAMARA,42,,Berlin,21as;;;,,,,";
	char	c = ',';
	size_t	i;

	i =0;
	array = ft_split(test, c);
	while (i < ft_count(test, c))
	{
		printf("%s\n", array[i]);
		i++;
	}
	
	free(array);
	return (0);
}*/
