/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:14:38 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/03/07 18:15:29 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

void	*ft_messi2(void *mlx)
{
	void	*img;
	int		img_width;
	int		img_height;

	img_width = 1;
	img_height = 1;
	img = mlx_xpm_file_to_image(mlx,
			"image/player2.xpm", &img_width, &img_height);
	return (img);
}
