/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:11:00 by ralves-e          #+#    #+#             */
/*   Updated: 2024/04/21 15:58:52 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		length;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > 2147483647)
		len = 2147483647;
	length = ft_strlen(&s[start]);
	if (length > (int)len)
		length = (int)len;
	res = (char *)malloc(sizeof(char) * (length + 1));
	if (!res)
		return (0);
	ft_strlcpy(res, &s[start], length + 1);
	return (res);
}
