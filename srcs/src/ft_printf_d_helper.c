/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:54:15 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/14 20:54:15 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_print_d_helper(t_param *params, size_t length, char *nbr)
{
	if (ft_printf_str_contains(params->flags, '0') &&
		params->precision < length)
	{
		ft_print_sign(params);
		ft_print_blank_d_zero(params, length);
	}
	else
	{
		ft_print_blank_d(params, length);
		ft_print_sign(params);
	}
	ft_print_zero(params, length);
	if (!(params->precision_flag && *nbr == '0' && params->precision == 0))
		ft_putstr(nbr);
}

void	ft_print_d(t_param *params, size_t length, char *nbr)
{
	if (ft_printf_str_contains(params->flags, '-'))
	{
		ft_print_sign(params);
		ft_print_zero(params, length);
		if (!(params->precision_flag && *nbr == '0' && params->precision == 0))
			ft_putstr(nbr);
		ft_print_blank_d(params, length);
	}
	else
	{
		ft_print_d_helper(params, length, nbr);
	}
	ft_memdel((void **)&nbr);
}

size_t	ft_printf_d_size_t(va_list ap, t_param *params)
{
	size_t		n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, size_t);
	nbr = ft_itoa_base(n, 10);
	length = ft_strlen(nbr);
	if (params->precision_flag && params->precision == 0 && *nbr == '0')
		length = 0;
	ft_print_d(params, length, nbr);
	if (params->symbol == 1)
		length += 1;
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}
