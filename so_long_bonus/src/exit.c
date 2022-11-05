/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:36:34 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/03/07 17:37:02 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_win(t_data *data)
{
	ft_printf ("\033[0;32m");
	ft_printf (" -------------------\n");
	ft_printf ("|YOU WIN IN %d move |\n", ++data->move);
	ft_printf (" -------------------\n");
	mlx_destroy_window (data->mlx, data->mlx_win);
	exit (0);
}

void	ft_lose(t_data *data)
{
	ft_printf ("\033[0;31m");
	ft_printf (" ----------------------\n");
	ft_printf ("| Good luck next time !|\n");
	ft_printf (" ----------------------\n");
	mlx_destroy_window (data->mlx, data->mlx_win);
	exit (0);
}

int	ft_lose_red(t_data *data)
{
	ft_printf ("\033[0;31m");
	ft_printf (" ----------------------\n");
	ft_printf ("| Good luck next time !|\n");
	ft_printf (" ----------------------\n");
	mlx_destroy_window (data->mlx, data->mlx_win);
	exit (0);
}
