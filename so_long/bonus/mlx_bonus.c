/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:27:30 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/03/23 13:42:46 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_load_xpm_images(struct s_info *g)
{
	g->player = mlx_xpm_file_to_image
		(g->mlx, "xpm_files/player_1.xpm", &g->hw, &g->hw);
	g->player2 = mlx_xpm_file_to_image
		(g->mlx, "xpm_files/player_2.xpm", &g->hw, &g->hw);
	g->wall = mlx_xpm_file_to_image
		(g->mlx, "xpm_files/wall.xpm", &g->hw, &g->hw);
	g->collectible = mlx_xpm_file_to_image
		(g->mlx, "xpm_files/collectible_1.xpm", &g->hw, &g->hw);
	g->collectible2 = mlx_xpm_file_to_image
		(g->mlx, "xpm_files/collectible_2.xpm", &g->hw, &g->hw);
	g->collectible3 = mlx_xpm_file_to_image
		(g->mlx, "xpm_files/collectible_3.xpm", &g->hw, &g->hw);
	g->exit = mlx_xpm_file_to_image
		(g->mlx, "xpm_files/exit.xpm", &g->hw, &g->hw);
	g->floor = mlx_xpm_file_to_image
		(g->mlx, "xpm_files/floor.xpm", &g->hw, &g->hw);
	g->enemy = mlx_xpm_file_to_image
		(g->mlx, "xpm_files/enemy_1.xpm", &g->hw, &g->hw);
	g->enemy2 = mlx_xpm_file_to_image
		(g->mlx, "xpm_files/enemy_2.xpm", &g->hw, &g->hw);
	ft_protection_load_image(g);
}

void	ft_put_1c(struct s_info *g, int y, int x)
{
	if (g->lines[y][x] == '1')
		mlx_put_image_to_window
			(g->mlx, g->window, g->wall, x * 30, y * 30);
	if (g->lines[y][x] == 'C')
	{
		mlx_put_image_to_window
			(g->mlx, g->window, g->collectible, x * 30, y * 30);
	}
}

void	ft_put_ep(struct s_info *g, int y, int x)
{
	if (g->lines[y][x] == 'E')
	{
		mlx_put_image_to_window
			(g->mlx, g->window, g->floor, x * 30, y * 30);
		mlx_put_image_to_window
			(g->mlx, g->window, g->exit, x * 30, y * 30);
	}
	if (g->lines[y][x] == 'P')
	{
		mlx_put_image_to_window
			(g->mlx, g->window, g->player, x * 30, y * 30);
	}
}

void	ft_display_images(struct s_info *g)
{
	int	y;
	int	x;

	y = -1;
	while (g->lines[++y])
	{
		x = -1;
		while (g->lines[y][++x])
		{
			if (g->lines[y][x] == '0')
				mlx_put_image_to_window
					(g->mlx, g->window, g->floor, x * 30, y * 30);
			if (g->lines[y][x] == 'Y')
				mlx_put_image_to_window
					(g->mlx, g->window, g->enemy, x * 30, y * 30);
			if (g->lines[y][x] == '1' || g->lines[y][x] == 'C')
				ft_put_1c(g, y, x);
			if (g->lines[y][x] == 'E' || g->lines[y][x] == 'P')
				ft_put_ep(g, y, x);
		}
	}
}

int	moves_handler(int key, struct s_info *g)
{
	int			r;
	static int	collected;

	if (key == 2 || key == 124)
		r = move_right(g, collected);
	if (key == 0 || key == 123)
		r = move_left(g, collected);
	if (key == 13 || key == 126)
		r = move_up(g, collected);
	if (key == 1 || key == 125)
		r = move_down(g, collected);
	if (key == 53)
	{
		ft_free_double_pointer(g->lines);
		mlx_destroy_window(g->mlx, g->window);
		exit(0);
	}
	if (r == 1)
		collected++;
	mlx_clear_window(g->mlx, g->window);
	ft_display_images(g);
	g->moves_str = ft_itoa(g->moves);
	mlx_string_put(g->mlx, g->window, 0, 0, 0xFFFFFF, g->moves_str);
	free(g->moves_str);
	return (0);
}
