/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:47:07 by ralves-e          #+#    #+#             */
/*   Updated: 2024/05/21 20:00:03 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*assign_itoa(int n, int digits)
{
	char			*buf;
	long int		i;

	buf = (char *)malloc(sizeof(char) * digits + 1);
	if (!buf)
		return (0);
	buf[digits] = '\0';
	if (n == 0)
		buf[0] = '0';
	if (n < 0)
	{
		buf[0] = '-';
		i = -(long)n;
	}
	else
		i = n;
	while (i != 0)
	{
		digits--;
		buf[digits] = (i % 10) + '0';
		i /= 10;
	}
	return (buf);
}

char	*ft_itoa(int n)
{
	char	*buf;
	int		i;
	int		digits;

	i = n;
	digits = 0;
	if (n == 0)
		digits++;
	while (i != 0)
	{
		digits++;
		i /= 10;
	}
	if (n < 0)
		digits++;
	buf = assign_itoa(n, digits);
	return (buf);
}
