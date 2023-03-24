/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:25:45 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/03/24 14:33:45 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_exist_and_ber(struct s_info *g)
{
	int	i;
	int	l;

	i = 0;
	g->fd = open(g->mapname, O_RDONLY);
	if (g->fd == -1)
	{
		write(1, "Error\nThe map doesn't exist!", 28);
		exit(1);
	}
	close(g->fd);
	l = ft_strlen(g->mapname);
	if (g->mapname[l - 1] == 'r' && g->mapname[l - 2] == 'e'
		&& g->mapname[l - 3] == 'b' && g->mapname[l - 4] == '.')
		return (1);
	else
	{
		write(1, "Error\nMap name doesn't end with .ber!", 38);
		exit(1);
	}
}

void	ft_map_not_empty(struct s_info *g)
{
	int		i;
	char	*p;

	i = 453565;
	p = (char *)malloc(sizeof(char));
	ft_protection(p);
	g->fd = open(g->mapname, O_RDONLY);
	i = read(g->fd, p, 1);
	if (i == 0)
	{
		write(1, "Error\nThe map is empty!", 24);
		free(p);
		exit(1);
	}
	close(g->fd);
	free(p);
}

void	ft_store_map_content(struct s_info *g)
{
	int		r;
	char	*buffer;

	g->fd = open(g->mapname, O_RDONLY);
	g->stock = NULL;
	buffer = (char *)malloc(sizeof(char) * 2);
	ft_protection(buffer);
	r = 1;
	while (r == 1)
	{
		r = read(g->fd, buffer, 1);
		if (r == 0)
			break ;
		buffer[1] = '\0';
		g->stock = ft_strjoin(g->stock, buffer);
	}
	free (buffer);
	close (g->fd);
}

void	mlx_functions(struct s_info *g)
{
	g->mlx = mlx_init();
	ft_protection(g->mlx);
	g->window = mlx_new_window(g->mlx, g->len * 30, g->nb * 30, "game window");
	ft_protection(g->window);
	ft_load_xpm_images(g);
	ft_display_images(g);
	g->moves = 0;
	mlx_hook(g->window, 02, 0, moves_handler, g);
	mlx_hook(g->window, 17, 0, cross_handler, g);
	g->frame = 0;
	mlx_loop_hook(g->mlx, animation_function, g);
	mlx_loop(g->mlx);
}

int	main(int argc, char **argv)
{
	struct s_info	g;

	ft_protect_args(argc);
	g.mapname = argv[1];
	ft_exist_and_ber(&g);
	ft_map_not_empty(&g);
	ft_store_map_content(&g);
	ft_check_newlines(&g);
	ft_split(&g, '\n');
	ft_getdata(&g);
	ft_check_map(&g);
	ft_make_copy(&g);
	ft_full_map(&g);
	ft_check_validation(&g);
	g.direction = 1;
	mlx_functions(&g);
}
