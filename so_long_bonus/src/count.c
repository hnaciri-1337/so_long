/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:29:11 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/03/07 17:36:46 by hnaciri-         ###   ########.fr       */
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

void	ft_count_player(char **the_map, int l)
{
	int	i;
	int	j;
	int	p;

	p = 0;
	i = 0;
	while (i < l)
	{
		j = -1;
		while (the_map[i][++j])
		{
			if (the_map[i][j] == 'P')
				p++;
		}
		i++;
	}
	if (p != 1)
	{
		ft_putendl_fd ("Error!\nPlayers number is invalid", 2);
		exit (1);
	}
}

void	ft_count_enemies(t_data *data)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	data->enemies = 0;
	while (++i < data->array[1])
	{
		j = -1;
		while (data->the_map[i][++j])
		{
			if (data->the_map[i][j] == 'A')
			{
				count++;
				ft_lstadd_back (&data->enemies, ft_lstnew (i, j, count));
			}
		}
	}
	if (!count)
	{
		ft_putendl_fd ("Error!\nThere is no enemies in the map", 2);
		ft_putendl_fd ("Its Bonus we need enemies 'A' character", 2);
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
