/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:09:21 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/03/24 14:06:46 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_animate_p_and_y(struct s_info *g, void *p, void *e)
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
				mlx_put_image_to_window
					(g->mlx, g->window, p, x * 30, y * 30);
			if (g->lines[y][x] == 'Y')
				mlx_put_image_to_window
					(g->mlx, g->window, e, x * 30, y * 30);
		}
	}
}

void	ft_animate_collectible(struct s_info *g, void *coll)
{
	int	y;
	int	x;

	y = -1;
	while (g->lines[++y])
	{
		x = -1;
		while (g->lines[y][++x])
		{
			if (g->lines[y][x] == 'C')
				mlx_put_image_to_window
					(g->mlx, g->window, coll, x * 30, y * 30);
		}
	}
}

int	animation_function(struct s_info *g)
{
	if (g->frame <= 20)
		ft_animate_p_and_y(g, g->player, g->enemy);
	if (g->frame > 20)
		ft_animate_p_and_y(g, g->player2, g->enemy2);
	if (g->frame <= 10 || (g->frame > 20 && g->frame <= 30))
		ft_animate_collectible(g, g->collectible);
	if ((g->frame > 10 && g->frame <= 20))
		ft_animate_collectible(g, g->collectible2);
	if (g->frame > 30)
		ft_animate_collectible(g, g->collectible3);
	g->frame++;
	if (g->frame == 40)
		move_enemy(g);
	if (g->frame == 40)
		g->frame = 0;
	return (0);
}

int	cross_handler(struct s_info *g)
{
	ft_free_double_pointer(g->lines);
	mlx_destroy_window(g->mlx, g->window);
	exit(0);
}
