/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:14:54 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/22 16:50:19 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_len(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*array;
	size_t	i;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = ft_nb_len(n);
	if (n < 0)
		n = -n;
	array = (char *)ft_calloc((i + 1), sizeof(char));
	if (array == NULL)
		return (0);
	array[i] = '\0';
	while (n > 0)
	{
		i--;
		array[i] = '0' + n % 10;
		n /= 10;
	}
	if (i > 0)
		array[0] = '-';
	return (array);
}
