/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:22:47 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/13 18:23:10 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_print_zero(t_param *params, size_t length)
{
	size_t i;

	i = 0;
	if (params->precision > length)
	{
		while (i < (params->precision - length))
		{
			ft_putchar('0');
			i++;
		}
	}
}
