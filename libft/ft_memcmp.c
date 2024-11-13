/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:22:06 by ralves-e          #+#    #+#             */
/*   Updated: 2024/04/13 12:50:10 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	if (n == 0)
		return (0);
	p1 = ptr1;
	p2 = ptr2;
	i = 0;
	while ((unsigned char)p1[i] == (unsigned char)p2[i] && i < n - 1)
		i++;
	return ((unsigned char)p1[i] - (unsigned char)p2[i]);
}
