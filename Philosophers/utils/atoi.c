/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:53:41 by ralves-e          #+#    #+#             */
/*   Updated: 2024/09/04 19:56:21 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_strncmp(char *str1, char *str2, int n)
{
	if (n == 0)
		return (0);
	if (n < 0)
		return (-1);
	while (n > 1 && (unsigned char)*str1 == (unsigned char)*str2
		&& *str1 && *str2)
	{
		str1++;
		str2++;
		n--;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	char	*temp;

	i = 0;
	sign = 1;
	temp = (char *)nptr;
	while (*temp == ' ' || (*temp >= '\t' && *temp <= '\r'))
		temp++;
	if (*temp == '-' || *temp == '+')
	{
		if (*temp == '-')
			sign *= -1;
		temp++;
	}
	if (ft_strncmp((char *)temp, "2147483648", 11) == 0 && sign == -1)
		return (-2147483648);
	while (*temp >= '0' && *temp <= '9')
	{
		i = i * 10 + (*temp - '0');
		temp++;
	}
	return (i * sign);
}
