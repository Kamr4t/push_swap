/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:58:34 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/20 10:56:36 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*array;
	size_t	i;
	size_t	str_len;

	if (!s)
		return (0);
	str_len = ft_strlen(s);
	if (str_len < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	array = (char *)ft_calloc((len + 1), sizeof(char));
	if (!array)
		return (0);
	i = 0;
	while (i < len && s[i + start] != '\0')
	{
		array[i] = s[i + start];
		i++;
	}
	array[i] = '\0';
	return (array);
}
