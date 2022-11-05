/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:29:11 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/03/07 18:51:13 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_count_exit(char **the_map, int l)
{
	int	i;
	int	j;

	i = 0;
	while (i < l)
	{
		j = -1;
		while (the_map[i][++j])
		{
			if (the_map[i][j] == 'E')
				return ;
		}
		i++;
	}
	ft_putendl_fd ("Error!\nThere is no exit in the map", 2);
	exit (1);
}

void	ft_count_player(t_data *data)
{
	int	i;
	int	j;
	int	p;

	p = 0;
	i = -1;
	while (++i < data->array[1])
	{
		j = -1;
		while (data->the_map[i][++j])
		{
			if (data->the_map[i][j] == 'P')
			{
				data->i = i;
				data->j = j;
				p++;
			}
		}
	}
	if (p != 1)
	{
		ft_putendl_fd ("Error!\nPlayers number is invalid", 2);
		exit (1);
	}
}

void	ft_count_coins(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->coin = 0;
	while (i < data->array[1])
	{
		j = -1;
		while (data->the_map[i][++j])
		{
			if (data->the_map[i][j] == 'C')
				data->coin++;
		}
		i++;
	}
	if (!data->coin)
	{
		ft_putendl_fd ("Error!\nThere is no coins in the map", 2);
		exit (1);
	}
}

void	ft_win(t_data *data)
{
	ft_printf ("\033[0;32m");
	ft_printf (" -------------------\n");
	ft_printf ("|YOU WIN IN %d move |\n", ++data->move);
	ft_printf (" -------------------\n");
	mlx_destroy_window (data->mlx, data->mlx_win);
	exit (0);
}

int	ft_lose(t_data *data)
{
	ft_printf ("\033[0;31m");
	ft_printf (" ----------------------\n");
	ft_printf ("| Good luck next time !|\n");
	ft_printf (" ----------------------\n");
	mlx_destroy_window (data->mlx, data->mlx_win);
	exit (0);
	return (0);
}
