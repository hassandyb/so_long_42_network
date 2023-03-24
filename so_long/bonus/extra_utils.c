/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:40:46 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/03/24 14:07:34 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_find_p(struct s_info *g)
{
	int	y;
	int	x;

	y = -1;
	while (g->lines[++y])
	{
		x = -1;
		while (g->lines[y][++x])
		{
			if (g->lines[y][x] == 'P')
			{
				g->xp = x;
				g->yp = y;
				return ;
			}
		}
	}
}

void	ft_you_lost(struct s_info *g)
{
	ft_free_double_pointer(g->lines);
	mlx_destroy_window(g->mlx, g->window);
	write(1, "You Lost!", 10);
	exit (0);
}

void	ft_protection_load_image(struct s_info *g)
{
	if (g->player == NULL || g->player2 == NULL || g->wall == NULL
		|| g->collectible == NULL || g->collectible2 == NULL
		|| g->collectible3 == NULL || g->floor == NULL
		|| g->exit == NULL || g->enemy == NULL || g->enemy2 == NULL)
	{
		ft_free_double_pointer(g->lines);
		mlx_destroy_window(g->mlx, g->window);
		exit(1);
	}
}

int	ft_intlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len = 1;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int moves)
{
	int		len;
	char	*str;

	len = ft_intlen(moves);
	str = (char *)malloc((len + 1) * sizeof(char));
	ft_protection(str);
	str[len] = '\0';
	if (moves == 0)
	{
		str[0] = '0';
		return (str);
	}
	len--;
	while (moves > 0)
	{
		str[len] = (moves % 10) + '0';
		moves = moves / 10;
		len--;
	}
	return (str);
}
