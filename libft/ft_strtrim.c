/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:14:29 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/20 11:03:35 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_skip(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*array;
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	while (ft_skip(s[i], set))
		i++;
	start = i;
	i = ft_strlen(s) - 1;
	while (ft_skip(s[i], set))
		i--;
	end = i - start + 1;
	array = ft_substr(s, start, end);
	return (array);
}
