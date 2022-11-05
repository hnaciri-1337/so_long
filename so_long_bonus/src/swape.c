/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:22:32 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/03/07 17:23:32 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_swape_up(t_data *data, int i, int j)
{
	if (data->i == i - 1 && data->j == j)
		ft_lose (data);
	if (data->the_map[i - 1][j] == '0')
		return (1);
	return (0);
}

int	ft_swape_down(t_data *data, int i, int j)
{
	if (data->i == i + 1 && data->j == j)
		ft_lose (data);
	if (data->the_map[i + 1][j] == '0')
		return (1);
	return (0);
}

int	ft_swape_right(t_data *data, int i, int j)
{
	if (data->i == i && data->j == j + 1)
		ft_lose (data);
	if (data->the_map[i][j + 1] == '0')
		return (1);
	return (0);
}

int	ft_swape_left(t_data *data, int i, int j)
{	
	if (data->i == i && data->j == j - 1)
		ft_lose (data);
	if (data->the_map[i][j - 1] == '0')
		return (1);
	return (0);
}
