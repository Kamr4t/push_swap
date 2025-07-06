/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:37:30 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/20 16:05:57 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nr_ele, size_t size_ele)
{
	unsigned char	*array;
	size_t			i;

	if (nr_ele && size_ele > SIZE_MAX / nr_ele)
		return (NULL); 
	array = malloc (nr_ele * size_ele);
	if (!array)
		return (NULL);
	i = 0;
	while (i < nr_ele * size_ele)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}
