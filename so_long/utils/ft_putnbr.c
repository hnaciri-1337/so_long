/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:18:24 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/03/07 12:57:40 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int static	ft_alloc(long long int nbr)
{
	int	counter;

	counter = 2;
	if (nbr < 10)
		return (counter);
	while (nbr >= 10)
	{
		nbr /= 10;
		counter++;
	}
	return (counter);
}

char static	*ft_negative(long long int nbr)
{
	char		*str;
	int			i;
	long int	n;

	n = nbr;
	i = ft_alloc (nbr);
	str = malloc (sizeof(char) * (i + 1));
	if (str == 0)
		return (0);
	while (i--)
	{
		str[i] = (nbr % 10) + 48;
		nbr /= 10;
	}
	str[0] = '-';
	str[ft_alloc(n)] = 0;
	return (str);
}

static char	*ft_positive(long long int nbr)
{
	char				*str;
	int					i;
	long long int		n;

	n = nbr;
	i = ft_alloc (nbr) - 1;
	str = malloc (sizeof(char) * i + 1);
	if (str == 0)
		return (0);
	while (i--)
	{
		str[i] = (nbr % 10) + 48;
		nbr /= 10;
	}
	str[ft_alloc(n) - 1] = 0;
	return (str);
}

int	ft_putnbr(long int n)
{
	int				i;
	long long int	nbr;
	char			*str;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		str = ft_negative(nbr);
	}
	else
		str = ft_positive(nbr);
	i = ft_putstr(str);
	free (str);
	return (i);
}
