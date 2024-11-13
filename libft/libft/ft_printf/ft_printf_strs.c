/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:31:40 by ralves-e          #+#    #+#             */
/*   Updated: 2024/07/10 18:57:58 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!fd || !s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

char	*ft_toupper_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = (str[i] + 'A' - 'a');
		}
		else
		{
			str[i] = (str[i]);
		}
		i++;
	}
	return (str);
}
