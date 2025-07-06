/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:05:30 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/20 15:32:35 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*array;
	size_t	i;
	size_t	j;

	array = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (array == NULL)
		return (0);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		array[j + i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		array[j + i] = s2[j];
		j++;
	}
	array[j + i] = '\0';
	return (array);
}
