/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:39:02 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/03/07 18:49:52 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_draw_help(char c, int x, int y, t_data *data)
{
	void	*img;

	img = ft_sand (data->mlx);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, x, y);
	if (c == '1')
		img = ft_wall (data->mlx);
	else if (c == 'E')
		img = ft_door (data->mlx);
	else if (c == 'C')
		img = ft_coin (data->mlx);
	else if (c == 'P')
		img = ft_player (data->mlx);
	else if (c == '0')
		img = ft_sand (data->mlx);
	else if (c == 'M')
		img = ft_messi (data->mlx);
	else
		return ;
	if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, img, x + 12, y + 2);
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win, img, x, y);
}

void	ft_draw(t_data *data)
{
	int		i;
	int		j;
	int		x;
	int		y;

	y = 0;
	i = -1;
	while (++i < data->array[1])
	{
		x = 0;
		j = -1;
		while (data->the_map[i][++j])
		{
			ft_draw_help (data->the_map[i][j], x, y, data);
			x += X;
		}
		y += X;
	}
}

int	ft_check_and_draw(int key_code, t_data *data)
{
	int		j;

	ft_printf ("\033[0;33m");
	j = data->move;
	if (key_code == 53)
		ft_lose(data);
	if (key_code == 125 || key_code == 1)
		data->move += ft_move_down (data);
	if (key_code == 123 || key_code == 0)
		data->move += ft_move_left (data);
	if (key_code == 126 || key_code == 13)
		data->move += ft_move_up (data);
	if (key_code == 124 || key_code == 2)
		data->move += ft_move_right (data);
	if (data->move != j)
		ft_printf ("Move number : %d\n", data->move);
	return (0);
}

void	ft_display(char *map, t_data *data)
{
	int			fd;
	int			i;

	i = -1;
	fd = ft_open (map, data->array);
	data->the_map = ft_calloc (sizeof(char *), data->array[1] + 1);
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, (data->array[0] - 1)
			* X, data->array[1] * X, "So_long!");
	while (++i < data->array[1])
		data->the_map[i] = get_next_line (fd);
	ft_count_exit (data->the_map, data->array[1]);
	ft_count_coins (data);
	ft_count_player (data);
	ft_draw (data);
	mlx_key_hook (data->mlx_win, ft_check_and_draw, data);
	mlx_hook(data->mlx_win, 17, 0, ft_lose, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	char	*file;
	int		fd;
	t_data	data;

	ft_printf ("\033[0;31m");
	data.coin = 0;
	data.move = 0;
	fd = 0;
	if (ac != 2)
		ft_putendl_fd ("Error!\nOpps number of arguments invalid !", 2);
	if (ac != 2)
		return (1);
	file = ft_substr(av[1], ft_strlen(av[1]) - 4, 4);
	if ((ft_strncmp(file, ".ber", 4)) != 0)
	{
		ft_putendl_fd ("Error!\nInvalid file type !", 2);
		exit (0);
	}
	free (file);
	ft_start(av[1], fd, &data);
	ft_display (av[1], &data);
}
