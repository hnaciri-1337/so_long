/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:00:47 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/03/07 18:15:26 by hnaciri-         ###   ########.fr       */
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

void	ft_enemies(t_data *data)
{
	void		*img;
	int			img_width;
	int			img_height;
	t_enemies	*head;

	head = data->enemies;
	img_width = 1;
	img_height = 1;
	while (head)
	{
		if (head->number % 2)
			img = mlx_xpm_file_to_image (data->mlx,
					"image/ramos.xpm", &img_width, &img_height);
		else
			img = mlx_xpm_file_to_image (data->mlx,
					"image/pepe.xpm", &img_width, &img_height);
		mlx_put_image_to_window (data->mlx, data->mlx_win,
			img, head->j * X, head->i * X);
		head = head->next;
	}
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

void	*ft_sand(void *mlx)
{
	void	*img;
	int		img_width;
	int		img_height;

	img_width = 1;
	img_height = 1;
	img = mlx_xpm_file_to_image(mlx,
			"image/sand.xpm", &img_width, &img_height);
	return (img);
}
