/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:27:03 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/03/21 22:09:00 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_make_copy(struct s_info *g)
{
	int	y;
	int	x;

	g->copy = (char **)malloc((g->nb + 1) * sizeof(char *));
	y = -1;
	while (g->lines[++y])
	{
		x = -1;
		g->copy[y] = (char *)malloc((g->len + 1) * sizeof(char));
		while (g->lines[y][++x] != '\0')
		{
			g->copy[y][x] = g->lines[y][x];
		}
		g->copy[y][x] = '\0';
	}
	g->copy[y] = NULL;
}

int	ft_full_with_p(char **copy, int y, int x)
{
	int	count;

	count = 0;
	if (copy[y][x + 1] == '0' || copy[y][x + 1] == 'C')
	{
		copy[y][x + 1] = 'P';
		count++;
	}
	if (copy[y][x - 1] == '0' || copy[y][x - 1] == 'C')
	{
		copy[y][x - 1] = 'P';
		count++;
	}
	if (copy[y - 1][x] == '0' || copy[y - 1][x] == 'C')
	{
		copy[y - 1][x] = 'P';
		count++;
	}
	if (copy[y + 1][x] == '0' || copy[y + 1][x] == 'C')
	{
		copy[y + 1][x] = 'P';
		count++;
	}
	return (count);
}

void	ft_full_map(struct s_info *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->copy[y])
	{
		x = 0;
		while (g->copy[y][x])
		{
			if (g->copy[y][x] == 'P' && ft_full_with_p(g->copy, y, x) > 0)
			{
				x = 0;
				y = 0;
			}
			x++;
		}
		y++;
	}
}

void	ft_exit_error(char **copy, char **lines, char *error)
{
	ft_putstr(error);
	ft_free_double_pointer(copy);
	ft_free_double_pointer(lines);
	exit (1);
}

void	ft_check_validation(struct s_info *g)
{
	int	y;
	int	x;

	y = -1;
	while (g->copy[++y])
	{
		x = -1;
		while (g->copy[y][++x])
		{
			if (g->copy[y][x] == 'E')
			{
				if (g->copy[y][x + 1] != 'P' && g->copy[y][x - 1] != 'P' &&
					g->copy[y + 1][x] != 'P' && g->copy[y - 1][x] != 'P')
					ft_exit_error(g->copy, g->lines, "Error\nThe player "
						"wont be able to reach the exit!");
			}
			if (g->copy[y][x] == 'C')
				ft_exit_error(g->copy, g->lines, "Error\nThe player"
					" will not reach all collectibles!");
		}
	}
	ft_free_double_pointer(g->copy);
}
