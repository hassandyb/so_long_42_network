/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:29:03 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/03/24 13:49:14 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_putnbr(int nbr)
{
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		nbr = nbr + '0';
		write(1, &nbr, 1);
	}
}

void	ft_print_moves(int moves)
{
	write(1, "Number of Moves : ", 19);
	ft_putnbr(moves);
	write(1, "\n", 1);
}

int	cross_handler(struct s_info *g)
{
	(void)g;
	ft_free_double_pointer(g->lines);
	mlx_destroy_window(g->mlx, g->window);
	exit(0);
}
