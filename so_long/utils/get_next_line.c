/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:59:55 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/03/07 12:50:17 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*get_line(char *line, int rd, char *readed, int fd)
{
	char	*tmp;

	while (!(ft_strchr(line, '\n')) && rd)
	{
		rd = read (fd, readed, 1);
		if (rd == 0 && *readed == 0)
			return (0);
		if (rd < 0)
		{
			perror ("Error!\nCan't read the map");
			exit (0);
		}
		readed[rd] = 0;
		tmp = line;
		line = ft_strjoin (line, readed);
		free (tmp);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	int		rd;
	char	*readed;

	readed = ft_calloc(sizeof(char), 2);
	if (!readed)
		return (0);
	line = 0;
	rd = 1;
	line = get_line(line, rd, readed, fd);
	free (readed);
	return (line);
}
