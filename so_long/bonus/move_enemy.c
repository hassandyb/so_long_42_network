/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:26:24 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/03/24 14:14:35 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_right_direction(struct s_info *g, int y, int x)
{
	if (g->lines[y][x + 1] == '0')
	{
		g->lines[y][x] = '0';
		g->lines[y][x + 1] = 'Y';
		mlx_put_image_to_window(g->mlx, g->window, g->floor, x * 30, y * 30);
		mlx_put_image_to_window(g->mlx,
			g->window, g->enemy, (x + 1) * 30, y * 30);
	}
	else if (g->lines[y][x + 1] == 'P')
		ft_you_lost(g);
	else
		g->direction = 2;
}

void	ft_left_direction(struct s_info *g, int y, int x)
{
	if (g->lines[y][x - 1] == '0')
	{
		g->lines[y][x] = '0';
		g->lines[y][x - 1] = 'Y';
		mlx_put_image_to_window(g->mlx, g->window, g->floor, x * 30, y * 30);
		mlx_put_image_to_window(g->mlx,
			g->window, g->enemy, (x - 1) * 30, y * 30);
	}
	else if (g->lines[y][x - 1] == 'P')
		ft_you_lost(g);
	else
		g->direction = 1;
}

void	move_enemy(struct s_info *g)
{
	int	y;
	int	x;

	y = -1;
	while (g->lines[++y])
	{
		x = -1;
		while (g->lines[y][++x])
		{	
			if (g->lines[y][x] == 'Y')
			{
				if (g->direction == 1)
				{
					ft_right_direction(g, y, x);
					return ;
				}
				else if (g->direction == 2)
				{
					ft_left_direction(g, y, x);
					return ;
				}
			}
		}
	}
}
