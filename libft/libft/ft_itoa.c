/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:05:56 by ralves-e          #+#    #+#             */
/*   Updated: 2024/04/18 20:31:46 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*assign(int n, int digits)
{
	char			*buf;
	unsigned int	i;

	buf = (char *)malloc(sizeof(char) * (digits + 1));
	if (!buf)
		return (0);
	buf[digits] = '\0';
	if (n == 0)
		buf[0] = '0';
	if (n < 0)
	{
		buf[0] = '-';
		i = (unsigned int)(-n);
	}
	else
		i = (unsigned int)n;
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
	buf = assign(n, digits);
	return (buf);
}

// #include <stdio.h>
// int main(void)
// {
// 	char	*s;

// 	s = ft_itoa(16054);
// 	printf("%s", s);
// 	free(s);
// }