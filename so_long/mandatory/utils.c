/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:43:15 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/03/23 14:22:43 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_protection(char *p)
{
	if (p == NULL)
	{
		write(1, "Error\nEather there is no sufficient memory !", 29);
		write(1, "\nor the programme fails to set up the \
			connection to the graphical system", 73);
		write(1, "or the programmefails to create a new window", 28);
		exit (1);
	}
}

void	ft_protect_args(int argc)
{
	if (argc != 2)
	{
		write(1, "Error\nArguments number if diffrent that 2!", 43);
		exit(1);
	}
}

void	ft_protection_double_pointer(char **s)
{
	if (s == NULL)
	{
		write(1, "Error\nNo sufficient memory!", 28);
		exit (1);
	}
}

void	ft_putstr(char *str)
{
	int	h;

	h = 0;
	while (str[h])
	{
		write(1, &str[h], 1);
		h++;
	}
}

void	ft_free_double_pointer(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
}
