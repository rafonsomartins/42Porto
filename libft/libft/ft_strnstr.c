/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:40:39 by ralves-e          #+#    #+#             */
/*   Updated: 2024/04/22 20:16:03 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	char	*h;
	char	*ne;
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	if (!n)
		return (0);
	while (*haystack && n > 0)
	{
		h = (char *)haystack;
		ne = (char *)needle;
		i = n;
		while (*h == *ne && *h && *ne && i > 0)
		{
			h++;
			ne++;
			i--;
		}
		if (!(*ne))
			return ((char *)(haystack));
		haystack++;
		n--;
	}
	return (0);
}
