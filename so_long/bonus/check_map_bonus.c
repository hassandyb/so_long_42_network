/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:23:20 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/03/24 14:27:54 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strjoin(char *str, char *buffer)
{
	char	*temp;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
	{
		str = (char *)malloc(sizeof(char));
		ft_protection(str);
		str[0] = '\0';
	}
	len = ft_strlen(str) + ft_strlen(buffer);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	ft_protection(temp);
	while (str[i])
	{
		temp[i] = str[i];
		i++;
	}
	while (buffer[j])
		temp[i++] = buffer[j++];
	temp[i] = '\0';
	return (free(str), temp);
}

void	ft_getdata(struct s_info *g)
{
	int	j;

	g->nb = 0;
	g->x = 0;
	g->c = 0;
	g->e = 0;
	g->p = 0;
	g->len = ft_strlen(g->lines[0]);
	while (g->lines[g->nb] != NULL)
	{
		j = 0;
		while (g->lines[g->nb][j] != '\0')
		{
			if (g->lines[g->nb][j] == 'C')
				g->c++;
			else if (g->lines[g->nb][j] == 'P')
				g->p++;
			else if (g->lines[g->nb][j] == 'E')
				g->e++;
			j++;
		}
		if (j != g->len)
			g->x = 1;
		g->nb++;
	}	
}

void	ft_error(char **p, char *str)
{
	ft_free_double_pointer(p);
	ft_putstr(str);
	exit (1);
}

void	ft_check_map(struct s_info *g)
{
	int	i;
	int	j;

	if (g->x == 1)
		ft_error(g->lines, "Error\nThe map is not rectangular!");
	if (g->p != 1 || g->c == 0 || g->e != 1)
		ft_error(g->lines, "Error\nThere is no collectibles or eather"
			"there is many players/exits or there is no player/exit!");
	i = -1;
	while (g->lines[++i] != NULL)
	{
		j = -1;
		while (g->lines[i][++j] != '\0')
		{
			if (g->lines[i][j] != '0' && g->lines[i][j] != '1'
				&& g->lines[i][j] != 'C' && g->lines[i][j] != 'E'
				&& g->lines[i][j] != 'P' && g->lines[i][j] != 'Y')
				ft_error(g->lines, "Error\nNot 0, 1, C, E, Y and P!");
			if (i == 0 || i == g->nb - 1 || j == 0 || j == g->len - 1)
			{
				if (g->lines[i][j] != '1')
					ft_error(g->lines, "Error\nMap not surrounded by walls!");
			}	
		}	
	}
}
