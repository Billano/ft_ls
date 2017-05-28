/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:22:38 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/17 02:05:00 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_print_sign_helper(t_param *params)
{
	if (params->specifier == 'o')
		ft_putstr("0");
	else if ((params->specifier == 'x' || params->specifier == 'p'))
		ft_putstr("0x");
	else if (params->specifier == 'X')
		ft_putstr("0X");
}

void	ft_print_sign(t_param *params)
{
	if (ft_printf_str_contains(params->flags, '#') && (params->sign == 0 ||
				params->specifier == 'p'))
	{
		ft_print_sign_helper(params);
	}
	else if (ft_printf_str_contains(params->flags, '#') &&
			params->precision_flag && params->precision == 0)
	{
		if (params->specifier == 'o')
			ft_putstr("0");
	}
	else if (params->specifier == 'd' || params->specifier == 'i')
	{
		if (params->sign == 0 && ft_printf_str_contains(params->flags, '+'))
			ft_putchar('+');
		else if (params->sign == 0 &&
				ft_printf_str_contains(params->flags, ' '))
			ft_putchar(' ');
		else if (params->sign == 1)
			ft_putchar('-');
	}
}
