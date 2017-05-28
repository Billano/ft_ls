/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 04:40:39 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/16 04:40:41 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t	ft_printf_percent(t_param *params)
{
	if (ft_printf_str_contains(params->flags, '-'))
	{
		ft_putchar('%');
		ft_print_blank_s(params, 1);
	}
	else
	{
		ft_print_blank_s(params, 1);
		ft_putchar('%');
	}
	return (ft_max_number(1, params->width));
}
