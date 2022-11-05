/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:00:47 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/03/07 18:48:53 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*ft_door(void *mlx)
{
	void	*img;
	int		img_width;
	int		img_height;

	img_width = 1;
	img_height = 1;
	img = mlx_xpm_file_to_image(mlx,
			"image/closed.xpm", &img_width, &img_height);
	return (img);
}

void	*ft_wall(void *mlx)
{
	void	*img;
	int		img_width;
	int		img_height;

	img_width = 1;
	img_height = 1;
	img = mlx_xpm_file_to_image(mlx,
			"image/wall.xpm", &img_width, &img_height);
	return (img);
}

void	*ft_messi(void *mlx)
{
	void	*img;
	int		img_width;
	int		img_height;

	img_width = 1;
	img_height = 1;
	img = mlx_xpm_file_to_image(mlx,
			"image/takeball.xpm", &img_width, &img_height);
	return (img);
}

void	*ft_player(void *mlx)
{
	void	*img;
	int		img_width;
	int		img_height;

	img_width = 1;
	img_height = 1;
	img = mlx_xpm_file_to_image(mlx,
			"image/player.xpm", &img_width, &img_height);
	return (img);
}

void	*ft_coin(void *mlx)
{
	void	*img;
	int		img_width;
	int		img_height;

	img_width = 1;
	img_height = 1;
	img = mlx_xpm_file_to_image(mlx,
			"image/coin.xpm", &img_width, &img_height);
	return (img);
}
