/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:25:31 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/03/06 17:12:10 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_enemies	*ft_lstnew(int i, int j, int number)
{
	t_enemies	*new;

	new = malloc (sizeof(t_enemies));
	if (new == 0)
		return (0);
	new->i = i;
	new->j = j;
	new->number = number;
	new->next = 0;
	return (new);
}
