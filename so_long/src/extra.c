/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:48:55 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/03/07 18:50:14 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
