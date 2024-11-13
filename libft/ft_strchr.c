/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:35:48 by ralves-e          #+#    #+#             */
/*   Updated: 2024/04/18 18:42:45 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	const char		*s1;
	unsigned char	ch;

	s1 = str;
	ch = (unsigned char)c;
	while (*s1 != '\0')
	{
		if (*s1 == ch)
			return ((char *)s1);
		s1++;
	}
	if (ch == '\0')
		return ((char *)s1);
	return (0);
}
