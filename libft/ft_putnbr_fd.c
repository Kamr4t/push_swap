/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:37:05 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/22 09:25:41 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_print(char *str, int size, int fd)
{
	while (size > 0)
	{
		size--;
		write(fd, &str[size], 1);
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	char	str[11];
	int		i;
	long	nbr;

	i = 0;
	if (nb == 0)
		write(fd, "0", 1);
	nbr = nb;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i++;
	}
	str[i] = '\0';
	ft_print(str, i, fd);
}
