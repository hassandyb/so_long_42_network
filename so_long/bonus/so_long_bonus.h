/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:27:01 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/03/24 14:28:58 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

struct s_info
{
	int		fd;
	char	*mapname;
	char	*stock;
	char	**lines;
	int		nb;
	int		c;
	int		e;
	int		p;
	int		len;
	int		x;
	char	**copy;
	void	*mlx;
	void	*window;
	int		hw;
	void	*player;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*floor;
	int		xp;
	int		yp;
	int		moves;
	void	*enemy;
	int		frame;
	void	*player2;
	void	*collectible2;
	void	*collectible3;
	void	*enemy2;
	char	*moves_str;
	int		direction;
};

char	*ft_strjoin(char *str, char *buffer);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_protection(char *p);
void	ft_protection_double_pointer(char **s);
void	ft_free_double_pointer(char **str);
void	ft_check_newlines(struct s_info *g);
void	ft_split(struct s_info *g, char c);
int		ft_sentences_count(char *str, char c);
char	*ft_substr(char *s, int start, int len);
void	ft_getdata(struct s_info *g);
void	ft_check_map(struct s_info *g);
void	ft_error(char **p, char *str);
void	ft_make_copy(struct s_info *g);
void	ft_full_map(struct s_info *g);
int		ft_full_with_p(char **copy, int y, int x);
void	ft_check_validation(struct s_info *g);
void	ft_exit_error(char **copy, char **lines, char *error);
void	ft_load_xpm_images(struct s_info *g);
void	ft_display_images(struct s_info *g);
int		move_right(struct s_info *g, int collected);
int		move_left(struct s_info *g, int collected);
int		move_up(struct s_info *g, int collected);
int		move_down(struct s_info *g, int collected);
int		moves_handler(int key, struct s_info *g);
void	ft_find_p(struct s_info *g);
void	ft_protect_args(int argc);
void	ft_put_ep(struct s_info *g, int y, int x);
void	ft_put_1c(struct s_info *g, int y, int x);
void	ft_you_lost(struct s_info *g);
int		animation_function(struct s_info *g);
void	ft_animate_p_and_y(struct s_info *g, void *p, void *e);
void	ft_animate_collectible(struct s_info *g, void *coll);
char	*ft_itoa(int moves);
int		ft_intlen(int nbr);
void	ft_protection_load_image(struct s_info *g);
int		cross_handler(struct s_info *g);
void	move_enemy(struct s_info *g);
void	ft_right_direction(struct s_info *g, int y, int x);
void	ft_left_direction(struct s_info *g, int y, int x);
void	mlx_functions(struct s_info *g);

#endif