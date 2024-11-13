/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:07:33 by ralves-e          #+#    #+#             */
/*   Updated: 2024/04/21 17:36:16 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	if (!n || (!str1 && !str2))
		return (str1);
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	if (s1 > s2 && s1 < s2 + n)
	{
		i = n;
		while (i > 0)
		{
			i--;
			s1[i] = s2[i];
		}
		return (str1);
	}
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (str1);
}
