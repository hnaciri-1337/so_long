/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:16:47 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/03/07 18:17:03 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_anime_player(t_data *data)
{
	void	*img;

	img = ft_sand(data->mlx);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		img, data->j * X, data->i * X);
	data->anime++;
	if (data->anime % 2)
		img = ft_messi2(data->mlx);
	else
		img = ft_player(data->mlx);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		img, data->j * X, data->i * X);
}

void	ft_anime_enemie(t_data *data, t_enemies *enemies)
{
	int	i;

	while (enemies)
	{
		i = rand() % 4;
		if (i == 0)
			ft_enemie_up (data, enemies);
		else if (i == 1)
			ft_enemie_down (data, enemies);
		else if (i == 2)
			ft_enemie_right (data, enemies);
		else if (i == 3)
			ft_enemie_left (data, enemies);
		enemies = enemies->next;
	}
	ft_enemies (data);
}

int	enemies(t_data *data)
{
	static int	i = 0;
	t_enemies	*enemies;

	enemies = data->enemies;
	i++;
	if (!((i + 2000) % 4000))
		ft_anime_player (data);
	if (!(i % 5000))
	{
		ft_anime_enemie (data, enemies);
		i = 0;
	}
	return (0);
}
