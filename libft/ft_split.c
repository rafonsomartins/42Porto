/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:22:28 by ralves-e          #+#    #+#             */
/*   Updated: 2024/04/22 21:22:50 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_memerror(char **buf_res, int i)
{
	while (i--)
		free(buf_res[i]);
	free(buf_res);
	return (0);
}

static int	ft_countstrc(char const *s, char c, char ch)
{
	int	i;

	if (ch == 'c')
	{
		i = 0;
		while (*s == c)
			i++;
		return (i);
	}
	if (!s || !*s)
		return (0);
	while (*s && *s == c)
		s++;
	i = 0;
	while (*s)
	{
		if (*s == c && *(s + 1) != c)
			i++;
		s++;
	}
	s--;
	if (*s == c)
		return (i);
	return (i + 1);
}

static void	ft_ccpy(char *res, const char *s, char *buf)
{
	if (buf)
		ft_strlcpy(res, s, buf - s + 1);
	else
		ft_strlcpy(res, s, ft_strlen(s) + 1);
	return ;
}

static char	**ft_assign(char **res, char const *s, char c, int i)
{
	char	**buf;

	buf = res;
	while (i > 0)
	{
		while (*s && *s == c)
			s++;
		if (ft_strchr(s, c))
		{
			*res = (char *)malloc(sizeof(char) * (ft_strchr(s, c) - s + 1));
			if (!*res)
				return (ft_memerror(buf, res - buf));
		}
		else
		{
			*res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
			if (!*res)
				return (ft_memerror(buf, res - buf));
		}
		ft_ccpy(*res, s, ft_strchr(s, c));
		i--;
		s = ft_strchr(s, c) + ft_countstrc(s, c, 'c') + 1;
		res++;
	}
	return (buf);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**res;
	char	**buf_res;

	i = ft_countstrc(s, c, 's');
	res = (char **)malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (0);
	res[i] = 0;
	buf_res = ft_assign(res, s, c, i);
	return (buf_res);
}

/* 
int main (void)
{
	char	**ch;
	char	**ch_start;

	ch = ft_split("opazgandazstyle", 'z');
	ch_start = ch;
	if (!ch)
		return (1);
	while (*ch != NULL)
	{
		printf("ch: %s\n", *ch);
		free(*ch);
		ch++;
	}
	free(ch_start);
} */
