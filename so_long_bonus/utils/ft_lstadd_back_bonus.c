/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:55:36 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/03/06 17:10:11 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_lstadd_back(t_enemies **lst, t_enemies *new)
{
	t_enemies	*p;

	if (lst && new)
	{
		p = *lst;
		new->next = 0;
		if (p == 0)
		{
			*lst = new;
			return ;
		}
		while (p->next != 0)
			p = p->next;
		p->next = new;
	}
}
