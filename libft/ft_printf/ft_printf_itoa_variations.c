/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa_variations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:18:53 by ralves-e          #+#    #+#             */
/*   Updated: 2024/07/13 15:50:53 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*assign_utoa(unsigned int n, int digits)
{
	char			*buf;
	unsigned int	i;

	buf = (char *)malloc(sizeof(char) * digits + 1);
	if (!buf)
		return (0);
	buf[digits] = '\0';
	i = n;
	while (i != 0)
	{
		digits--;
		buf[digits] = (i % 10) + '0';
		i /= 10;
	}
	return (buf);
}

char	*ft_utoa(unsigned int n)
{
	char				*buf;
	unsigned int		i;
	int					digits;

	i = n;
	digits = 0;
	if (n == 0)
		digits++;
	while (i != 0)
	{
		digits++;
		i /= 10;
	}
	buf = assign_utoa(n, digits);
	return (buf);
}

char	*assign_hexa(unsigned long long n, int digits)
{
	char				*buf;
	unsigned long long	i;
	char				*base;

	base = "0123456789abcdef";
	buf = (char *)malloc(sizeof(char) * digits + 1);
	if (!buf)
		return (0);
	buf[digits] = '\0';
	if (n == 0)
		buf[0] = '0';
	i = n;
	while (i)
	{
		digits--;
		buf[digits] = base[(i % 16)];
		i /= 16;
	}
	return (buf);
}

char	*ft_itoa_hexa(unsigned long long n)
{
	char				*buf;
	int					digits;
	unsigned long long	i;

	i = n;
	digits = 0;
	if (n == 0)
		digits++;
	while (i)
	{
		digits++;
		i /= 16;
	}
	buf = assign_hexa(n, digits);
	return (buf);
}
