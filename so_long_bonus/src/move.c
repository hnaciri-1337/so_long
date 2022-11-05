/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:20:22 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/03/06 22:39:35 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_open(char *map, int *array)
{
	int	fd;

	fd = open (map, O_RDONLY);
	if (fd < 0)
	{
		free (array);
		perror ("Error!\nCan't open the map");
		exit (1);
	}
	return (fd);
}

int	ft_move_up(t_data *data)
{
	if (data->the_map[data->i - 1][data->j] != '1')
	{
		if (!ft_swap_up(data, data->i, data->j))
			return (0);
		ft_draw_help ('0', data->j * X, data->i * X, data);
		ft_draw_help ('0', data->j * X, (data->i - 1) * X, data);
		if (data->the_map[data->i - 1][data->j] == 'C')
			ft_draw_help ('M', data->j * X, (data->i - 1) * X, data);
		else
			ft_draw_help ('P', data->j * X, (data->i - 1) * X, data);
		data->the_map[data->i - 1][data->j] = 'P';
		data->i--;
		data->the_map[data->i][data->j] = '0';
		return (1);
	}
	return (0);
}

int	ft_move_down(t_data *data)
{
	if (data->the_map[data->i + 1][data->j] != '1')
	{
		if (!ft_swap_down(data, data->i, data->j))
			return (0);
		ft_draw_help ('0', data->j * X, data->i * X, data);
		ft_draw_help ('0', data->j * X, (data->i + 1) * X, data);
		if (data->the_map[data->i + 1][data->j] == 'C')
			ft_draw_help ('M', data->j * X, (data->i + 1) * X, data);
		else
			ft_draw_help ('P', data->j * X, (data->i + 1) * X, data);
		data->the_map[data->i + 1][data->j] = 'P';
		data->i++;
		data->the_map[data->i][data->j] = '0';
		return (1);
	}
	return (0);
}

int	ft_move_right(t_data *data)
{
	if (data->the_map[data->i][data->j + 1] != '1')
	{
		if (!ft_swap_right(data, data->i, data->j))
			return (0);
		ft_draw_help ('0', data->j * X, data->i * X, data);
		ft_draw_help ('0', (data->j + 1) * X, data->i * X, data);
		if (data->the_map[data->i][data->j + 1] == 'C')
			ft_draw_help ('M', (data->j + 1) * X, data->i * X, data);
		else
			ft_draw_help ('P', (data->j + 1) * X, data->i * X, data);
		data->the_map[data->i][data->j + 1] = 'P';
		data->j++;
		data->the_map[data->i][data->j] = '0';
		return (1);
	}
	return (0);
}

int	ft_move_left(t_data *data)
{
	if (data->the_map[data->i][data->j - 1] != '1')
	{
		if (!ft_swap_left(data, data->i, data->j))
			return (0);
		ft_draw_help ('0', data->j * X, data->i * X, data);
		ft_draw_help ('0', (data->j - 1) * X, data->i * X, data);
		if (data->the_map[data->i][data->j - 1] == 'C')
			ft_draw_help ('M', (data->j - 1) * X, data->i * X, data);
		else
			ft_draw_help ('P', (data->j - 1) * X, data->i * X, data);
		data->the_map[data->i][data->j - 1] = 'P';
		data->j--;
		data->the_map[data->i][data->j] = '0';
		return (1);
	}
	return (0);
}
