/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:38:17 by eurodrig          #+#    #+#             */
/*   Updated: 2016/12/06 19:58:31 by eurodrig         ###   ########.fr       */
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

static t_point	ft_iterate(int n, char *s, long *x, t_point ij)
{
	if (n < 0)
	{
		s[0] = '-';
		*x *= -1;
		ij.i--;
	}
	while (ij.i)
	{
		s[ij.j] = ((*x / (ft_pwr(10, ij.i - 1))) % 10) + 48;
		ij.i--;
		ij.j++;
	}
	return (ij);
}

char			*ft_itoa(int n)
{
	t_point ij;
	char	*s;
	long	x;

	ij.j = 0;
	ij.i = 0;
	ij = ft_digit(n, ij);
	x = (long)n;
	if (n != 0)
	{
		if ((s = (char *)malloc(sizeof(char) * ij.i + 1)) == NULL)
			return (NULL);
		ij = ft_iterate(n, s, &x, ij);
	}
	else
	{
		if ((s = (char *)malloc(sizeof(char) * 2)) == NULL)
			return (NULL);
		s[ij.j] = '0';
		ij.j++;
	}
	s[ij.j] = '\0';
	return (s);
}
