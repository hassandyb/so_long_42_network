/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:52:48 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/03/21 17:30:48 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_right(struct s_info *g, int collected)
{
	ft_find_p(g);
	if (g->lines[g->yp][g->xp + 1] == 'C')
	{
		g->lines[g->yp][g->xp + 1] = 'P';
		g->lines[g->yp][g->xp] = '0';
		ft_print_moves(++g->moves);
		return (1);
	}
	if (g->lines[g->yp][g->xp + 1] == '0')
	{
		g->lines[g->yp][g->xp + 1] = 'P';
		g->lines[g->yp][g->xp] = '0';
		ft_print_moves(++g->moves);
		return (0);
	}
	if (g->lines[g->yp][g->xp + 1] == 'E' && collected == g->c)
	{
		ft_free_double_pointer(g->lines);
		mlx_destroy_window(g->mlx, g->window);
		write(1, "You Win!", 9);
		exit(0);
	}
	return (0);
}

int	move_left(struct s_info *g, int collected)
{
	ft_find_p(g);
	if (g->lines[g->yp][g->xp - 1] == 'C')
	{
		g->lines[g->yp][g->xp - 1] = 'P';
		g->lines[g->yp][g->xp] = '0';
		ft_print_moves(++g->moves);
		return (1);
	}
	if (g->lines[g->yp][g->xp - 1] == '0')
	{
		g->lines[g->yp][g->xp - 1] = 'P';
		g->lines[g->yp][g->xp] = '0';
		ft_print_moves(++g->moves);
		return (0);
	}
	if (g->lines[g->yp][g->xp - 1] == 'E' && collected == g->c)
	{
		ft_free_double_pointer(g->lines);
		mlx_destroy_window(g->mlx, g->window);
		write(1, "You Win!", 9);
		exit(0);
	}
	return (0);
}

int	move_up(struct s_info *g, int collected)
{
	ft_find_p(g);
	if (g->lines[g->yp - 1][g->xp] == 'C')
	{
		g->lines[g->yp - 1][g->xp] = 'P';
		g->lines[g->yp][g->xp] = '0';
		ft_print_moves(++g->moves);
		return (1);
	}
	if (g->lines[g->yp - 1][g->xp] == '0')
	{
		g->lines[g->yp - 1][g->xp] = 'P';
		g->lines[g->yp][g->xp] = '0';
		ft_print_moves(++g->moves);
		return (0);
	}
	if (g->lines[g->yp - 1][g->xp] == 'E' && collected == g->c)
	{
		ft_free_double_pointer(g->lines);
		mlx_destroy_window(g->mlx, g->window);
		write(1, "You Win!", 9);
		exit(0);
	}
	return (0);
}

int	move_down(struct s_info *g, int collected)
{
	ft_find_p(g);
	if (g->lines[g->yp + 1][g->xp] == 'C')
	{
		g->lines[g->yp + 1][g->xp] = 'P';
		g->lines[g->yp][g->xp] = '0';
		ft_print_moves(++g->moves);
		return (1);
	}
	if (g->lines[g->yp + 1][g->xp] == '0')
	{
		g->lines[g->yp + 1][g->xp] = 'P';
		g->lines[g->yp][g->xp] = '0';
		ft_print_moves(++g->moves);
		return (0);
	}
	if (g->lines[g->yp + 1][g->xp] == 'E' && collected == g->c)
	{
		ft_free_double_pointer(g->lines);
		mlx_destroy_window(g->mlx, g->window);
		write(1, "You Win!", 9);
		exit(0);
	}
	return (0);
}
