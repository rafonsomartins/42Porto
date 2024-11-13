/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:45 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/04/21 17:29:24 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char const *s, char const c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		s;
	int		size;
	char	*newstring;

	if (!s1 || !set)
		return (0);
	size = ft_strlen(s1);
	i = 0;
	s = 0;
	while (s1[s] && ft_check(set, s1[s]))
		s++;
	while (size > s && ft_check(set, s1[size - 1]))
		size--;
	newstring = (char *)malloc(sizeof(char) * (size - s + 1));
	if (!newstring)
		return (0);
	while (size > s)
	{
		newstring[i] = s1[s];
		i++;
		s++;
	}
	newstring[i] = '\0';
	return (newstring);
}

// #include <stdio.h>
// int main (void)
// {
// 	char	*s = ft_strtrim("lorem ipsum dolor sit amet", "te");
// 	printf("%s\n", s);
// 	free(s);
// }
