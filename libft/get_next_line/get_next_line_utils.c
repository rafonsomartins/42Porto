/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:19:53 by ralves-e          #+#    #+#             */
/*   Updated: 2024/05/03 19:19:53 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	if (!src)
		return (0);
	while (src[src_len] != '\0')
		src_len++;
	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	if (!str)
		return (0);
	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}

char	*ft_realloc(char *buf, char	*final)
{
	char	*res;

	res = (char *)malloc(sizeof(char)
			* (ft_strlen(buf) + ft_strlen(final) + 1));
	if (!res)
		return (0);
	ft_strlcpy(res, buf, ft_strlen(buf) + 1);
	ft_strlcpy(res + ft_strlen(buf), final, ft_strlen(final) + 1);
	free(final);
	free(buf);
	return (res);
}
