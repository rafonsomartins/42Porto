/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:30:29 by ralves-e          #+#    #+#             */
/*   Updated: 2024/04/11 18:30:29 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	char	*last;

	last = 0;
	while (*str)
	{
		if ((unsigned char)*str == (unsigned char)c)
			last = str;
		str++;
	}
	if ((unsigned char)*str == (unsigned char)c)
		return (str);
	return (last);
}
