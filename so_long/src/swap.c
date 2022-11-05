/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:35:36 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/03/07 18:35:38 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_swap_up(t_data *data, int i, int j)
{
	if (data->the_map[i - 1][j] == 'E')
	{
		if (data->coin == 0)
			ft_win(data);
		else
			return (0);
	}
	if (data->the_map[i - 1][j] == 'C')
		data->coin--;
	return (1);
}

int	ft_swap_down(t_data *data, int i, int j)
{
	if (data->the_map[i + 1][j] == 'E')
	{
		if (data->coin == 0)
			ft_win(data);
		else
			return (0);
	}
	if (data->the_map[i + 1][j] == 'C')
		data->coin--;
	return (1);
}

int	ft_swap_right(t_data *data, int i, int j)
{
	if (data->the_map[i][j + 1] == 'E')
	{
		if (data->coin == 0)
			ft_win(data);
		else
			return (0);
	}
	if (data->the_map[i][j + 1] == 'C')
		data->coin--;
	return (1);
}

int	ft_swap_left(t_data *data, int i, int j)
{
	if (data->the_map[i][j - 1] == 'E')
	{
		if (data->coin == 0)
			ft_win(data);
		else
			return (0);
	}
	if (data->the_map[i][j - 1] == 'C')
		data->coin--;
	return (1);
}
