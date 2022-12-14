/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:12:09 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/03/07 12:49:43 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s && fd >= 0)
	{
		ft_putstr_fd(s, fd);
		write (fd, "\n", 1);
	}
}
