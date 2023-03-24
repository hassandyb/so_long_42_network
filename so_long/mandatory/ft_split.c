/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:31:38 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/03/12 15:46:35 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	j;

	j = 0;
	while (str[j])
		j++;
	return (j);
}

void	ft_check_newlines(struct s_info *g)
{
	int	b;
	int	i;

	b = 0;
	i = 0;
	while (g->stock[i])
	{
		if (g->stock[i] == '\n' && g->stock[i + 1] == '\n')
			b = 1;
		i++;
	}
	if (g->stock[0] == '\n' || g->stock[i - 1] == '\n' || b == 1)
	{
		write(1, "Error\nThe map contains unnecessary new lines", 45);
		free(g->stock);
		exit(1);
	}
}

char	*ft_substr( char *s, int start, int len)
{
	int		i;
	int		slen;
	char	*p;

	i = 0;
	slen = ft_strlen(s);
	if (len > slen - start)
		p = (char *)malloc(slen - start + 1);
	else
		p = (char *)malloc(len + 1);
	ft_protection(p);
	while (s[i] != '\0' && i < len)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_sentences_count( char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		if ((str[i] == c && str[i +1] != c) || str[i + 1] == '\0')
			j++;
		i++;
	}
	return (j);
}

void	ft_split(struct s_info *g, char c)
{
	int	i;
	int	start;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = ft_sentences_count(g->stock, c);
	g->lines = (char **)malloc(sizeof(char *) * (n + 1));
	ft_protection_double_pointer(g->lines);
	while (j < n)
	{
		while (g->stock[i] == c)
			i++;
		start = i;
		while (g->stock[i] && g->stock[i] != c)
			i++;
		g->lines[j] = ft_substr(g->stock, start, i - start);
		if (g->lines[j] == NULL)
			ft_free_double_pointer(g->lines);
		j++;
	}
	g->lines[n] = NULL;
	free (g->stock);
}
