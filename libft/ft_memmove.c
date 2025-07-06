/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:30:11 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/20 14:40:56 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	char	*temp_d;
	char	*temp_s;

	if (!src && !dest)
		return (NULL);
	temp_s = (char *)src;
	temp_d = (char *)dest;
	i = 0;
	if (temp_d > temp_s)
		while (len-- > 0)
			temp_d[len] = temp_s[len];
	else
	{
		while (i < len)
		{
			temp_d[i] = temp_s[i];
			i++;
		}
	}
	return (dest);
}
