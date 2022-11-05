/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filevalidation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:05:05 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/03/06 16:15:51 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_first(char *line)
{
	int	i;

	i = 0;
	if (!line)
	{
		free (line);
		ft_putendl_fd("Error!\nFirst Line invalide", 2);
		exit (0);
	}
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
		{
			free (line);
			ft_putendl_fd("Error!\nFisrt Line invalide", 2);
			exit (0);
		}
		i++;
	}
	i = ft_strlen(line);
	free (line);
	return (i);
}

void	ft_check(int fd, char *map, t_data *data)
{
	char	*line;
	char	c;

	close (fd);
	fd = ft_open (map, data->array);
	line = ft_calloc(sizeof(char), 2);
	while (read (fd, line, 1))
	{
		line[1] = '\0';
		c = *line;
	}
	free (line);
	if (c == '\n')
	{
		ft_putendl_fd("Error!\nMap shouldn't ended with \\n", 2);
		exit (0);
	}
	close (fd);
}

void	ft_check_last(char *line, int len)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1')
		{
			free (line);
			ft_putendl_fd("Error!\nLast line is invalid", 2);
			exit (0);
		}
	}
	if (len != i + 1)
	{
		free (line);
		ft_putendl_fd("Error!\nLast line is invalid", 2);
		exit (0);
	}
}

void	ft_check_line(char *line, t_data *data)
{
	int	i;

	i = -1;
	if (line[ft_strlen(line) - 1] == '\n')
	{
		if ((int)ft_strlen(line) != data->array[0]
			|| line[ft_strlen(line) - 2] != '1' || line[0] != '1')
		{
			free (line);
			ft_printf ("Error!\nMap isn't rectangular or the map isn't closed\n");
			exit (0);
		}
	}
	else
		ft_check_last(line, data->array[0]);
	while (line[++i] == '0' || line[i] == '1' || line[i] == 'C'
		|| line[i] == 'P' || line[i] == 'E' || line[i] == 'A');
	if (line[i] != '\n' && line[i] != '\0')
	{
		free (line);
		ft_printf("Error!\n%c This character is invalid\n", line[i]);
		exit (0);
	}
}

void	ft_start(char	*map, int fd, t_data *data)
{
	char	*line;

	data->array = ft_calloc (sizeof(int), 2);
	fd = ft_open (map, data->array);
	line = get_next_line (fd);
	data->array[0] = ft_check_first (line);
	data->array[1] += 1;
	line = get_next_line (fd);
	while (line)
	{
		ft_check_line(line, data);
		free (line);
		data->array[1] += 1;
		line = get_next_line(fd);
	}
	free (line);
	ft_check (fd, map, data);
	close (fd);
}
