/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:27:14 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/03/07 17:23:10 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_enemie_up(t_data *data, t_enemies *enemies)
{
	if (data->the_map[enemies->i - 1][enemies->j] != '1')
	{
		if (!ft_swape_up(data, enemies->i, enemies->j))
			return (0);
		ft_draw_help ('0', enemies->j * X, enemies->i * X, data);
		ft_draw_help ('0', enemies->j * X, (enemies->i - 1) * X, data);
		data->the_map[enemies->i - 1][enemies->j] = 'A';
		data->the_map[enemies->i][enemies->j] = '0';
		enemies->i--;
		return (1);
	}
	return (0);
}

int	ft_enemie_down(t_data *data, t_enemies *enemies)
{
	if (data->the_map[enemies->i + 1][enemies->j] != '1')
	{
		if (!ft_swape_down(data, enemies->i, enemies->j))
			return (0);
		ft_draw_help ('0', enemies->j * X, enemies->i * X, data);
		ft_draw_help ('0', enemies->j * X, (enemies->i + 1) * X, data);
		data->the_map[enemies->i + 1][enemies->j] = 'A';
		data->the_map[enemies->i][enemies->j] = '0';
		enemies->i++;
		return (1);
	}
	return (0);
}

int	ft_enemie_right(t_data *data, t_enemies *enemies)
{
	if (data->the_map[enemies->i][enemies->j + 1] != '1')
	{
		if (!ft_swape_right(data, enemies->i, enemies->j))
			return (0);
		ft_draw_help ('0', enemies->j * X, enemies->i * X, data);
		ft_draw_help ('0', (enemies->j + 1) * X, enemies->i * X, data);
		data->the_map[enemies->i][enemies->j + 1] = 'A';
		data->the_map[enemies->i][enemies->j] = '0';
		enemies->j++;
		return (1);
	}
	return (0);
}

int	ft_enemie_left(t_data *data, t_enemies *enemies)
{
	if (data->the_map[enemies->i][enemies->j - 1] != '1')
	{
		if (!ft_swape_left(data, enemies->i, enemies->j))
			return (0);
		ft_draw_help ('0', enemies->j * X, enemies->i * X, data);
		ft_draw_help ('0', (enemies->j - 1) * X, enemies->i * X, data);
		data->the_map[enemies->i][enemies->j - 1] = 'A';
		data->the_map[enemies->i][enemies->j] = '0';
		enemies->j--;
		return (1);
	}
	return (0);
}
