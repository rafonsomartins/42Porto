/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 23:52:07 by ralves-e          #+#    #+#             */
/*   Updated: 2024/04/21 17:28:38 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_exp(int b, int e)
{
	int	result;

	result = 1;
	while (e > 0)
	{
		result *= b;
		e--;
	}
	return (result);
}

static void	ft_putnegative(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	write(fd, "-", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		j;
	char	s;

	i = 0;
	if (n < 0)
	{
		ft_putnegative(n, fd);
		n *= -1;
	}
	j = n;
	if (n == 0)
		i = 1;
	while (j > 0)
	{
		j /= 10;
		i++;
	}
	while (i > 0)
	{
		s = (n / ft_exp(10, i - 1)) + '0';
		n %= ft_exp(10, i - 1);
		write(fd, &s, 1);
		i--;
	}
}
