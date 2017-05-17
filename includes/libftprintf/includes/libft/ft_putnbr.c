/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 19:14:50 by eurodrig          #+#    #+#             */
/*   Updated: 2016/12/07 18:00:33 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_point	ft_digit(int n, t_point ij)
{
	long new;

	new = (long)n;
	if (new < 0)
	{
		new *= -1;
		ij.j++;
		ij.i++;
	}
	while (new != 0)
	{
		ij.i++;
		new = new / 10;
	}
	return (ij);
}

static t_point	ft_iterate(int n, long *x, t_point ij)
{
	if (n < 0)
	{
		ft_putchar('-');
		*x *= -1;
		ij.i--;
	}
	while (ij.i)
	{
		ft_putchar(((*x / (ft_pwr(10, ij.i - 1))) % 10) + 48);
		ij.i--;
		ij.j++;
	}
	return (ij);
}

void			ft_putnbr(int n)
{
	t_point ij;
	long	x;

	ij.j = 0;
	ij.i = 0;
	ij = ft_digit(n, ij);
	x = (long)n;
	if (n != 0)
	{
		ij = ft_iterate(n, &x, ij);
	}
	else
	{
		ft_putchar('0');
	}
}
